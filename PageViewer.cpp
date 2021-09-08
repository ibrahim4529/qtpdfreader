//
// Created by Ibrahim Hanif on 08/09/21.
//

#include "PageViewer.h"
#include <QDebug>
#include <poppler-qt5.h>

PageViewer::PageViewer(QWidget *parent) : QScrollArea(parent) {
    m_imageLabel = new QLabel(this);
    m_imageLabel->resize(0, 0);
    setWidget(m_imageLabel);
}

PageViewer::~PageViewer() {

}

void PageViewer::pageChanged(int page) {
    Poppler::Page *popPage = document()->page(page);
    if(!popPage){
        qDebug() << "failed render page";
        return;
    }
    const double resX = physicalDpiX() * 1.0;
    const double resY = physicalDpiY() * 1.0;

    Poppler::Page::Rotation rot = Poppler::Page::Rotate0;
    QImage image = popPage->renderToImage(resX, resY, -1, -1, -1, -1, rot);
    if (!image.isNull()) {
        m_imageLabel->resize(image.size());
        m_imageLabel->setPixmap(QPixmap::fromImage(image));
    } else {
        m_imageLabel->resize(0, 0);
        m_imageLabel->setPixmap(QPixmap());
    }

    delete popPage;
}

void PageViewer::documentClosed() {
    m_imageLabel->clear();
    m_imageLabel->resize(0,0);
}

void PageViewer::documentLoaded() {

}
