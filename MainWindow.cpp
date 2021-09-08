//
// Created by Ibrahim Hanif on 08/09/21.
//

#include "MainWindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include "PageViewer.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), m_doc(nullptr),
m_currentPage(0) {
    setWindowTitle("Qt PDF Reader");

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileOpenAction = fileMenu->addAction(tr("&Open"),
                                           this, &MainWindow::slotOpenFile);
    m_fileOpenAction->setShortcut(Qt::CTRL | Qt::Key_O);
    m_saveCopyFile = fileMenu->addAction(tr("&Save Copy File"),
                                         this, &MainWindow::slotSaveCopyFile);
    m_saveCopyFile->setShortcut(Qt::CTRL| Qt::SHIFT |Qt::Key_S);

    auto *pageViewer = new PageViewer(this);
    setCentralWidget(pageViewer);
    m_observers.append(pageViewer);

    Q_FOREACH(auto &obs, m_observers){
        obs->m_window = this;
    }
    resize(800, 800);
}

void MainWindow::slotOpenFile() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Select PDF File"),
                                                    QDir::homePath(),
                                                    tr("PDF Files(*.pdf)"));
    if(fileName.isEmpty()) {
        return;
    }
    loadFile(fileName);
}

void MainWindow::slotSaveCopyFile() {

}

void MainWindow::loadFile(const QString& fileName) {
    auto newDoc = Poppler::Document::load(fileName);
    if(!newDoc){
        QMessageBox msgBox(QMessageBox::Warning, "Failed Open File", fileName, QMessageBox::Ok);
        msgBox.exec();
    }
    closeDocument();
    m_doc = newDoc;
    m_doc->setRenderHint(Poppler::Document::Antialiasing, true);
    m_doc->setRenderHint(Poppler::Document::TextAntialiasing, true);

    Q_FOREACH(auto &obs, m_observers){
        obs->documentLoaded();
        obs->pageChanged(0);
    }
}

void MainWindow::closeDocument() {
    if(!m_doc){
        return;
    }
    delete m_doc;
    m_doc = nullptr;
}

MainWindow::~MainWindow() {
    closeDocument();
}

int MainWindow::page() const {
    return m_currentPage;
}

void MainWindow::setPage(int page) {

}
