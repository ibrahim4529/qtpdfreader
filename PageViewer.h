//
// Created by Ibrahim Hanif on 08/09/21.
//

#ifndef QTPDFREADER_PAGEVIEWER_H
#define QTPDFREADER_PAGEVIEWER_H
#include <QScrollArea>
#include <QLabel>
#include "DocumentObserver.h"

class PageViewer : public QScrollArea , public DocumentObserver{

Q_OBJECT
public:
    explicit PageViewer(QWidget *parent);
    ~PageViewer();
    void pageChanged(int page) override;
    void documentClosed() override;
    void documentLoaded() override;

private:
    QLabel *m_imageLabel;
};


#endif //QTPDFREADER_PAGEVIEWER_H
