//
// Created by Ibrahim Hanif on 08/09/21.
//

#ifndef QTPDFREADER_MAINWINDOW_H
#define QTPDFREADER_MAINWINDOW_H
#include <QMainWindow>
#include <QAction>
#include <poppler-qt5.h>
#include "DocumentObserver.h"
class DocumentObserver;

class MainWindow: public QMainWindow {
    Q_OBJECT
    friend class DocumentObserver;
public:
    explicit MainWindow(QWidget *parent= nullptr);
    ~MainWindow() override;

private Q_SLOTS:
    void slotOpenFile();
    void slotSaveCopyFile();

private:
    QAction *m_fileOpenAction;
    QAction *m_saveCopyFile;

    Poppler::Document *m_doc;
    QList<DocumentObserver*> m_observers;

    int m_currentPage;

    int page() const;
    void loadFile(const QString& fileName);
    void closeDocument();
    void setPage(int page);
};


#endif //QTPDFREADER_MAINWINDOW_H
