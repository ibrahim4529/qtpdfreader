//
// Created by Ibrahim Hanif on 08/09/21.
//

#ifndef QTPDFREADER_DOCUMENTOBSERVER_H
#define QTPDFREADER_DOCUMENTOBSERVER_H
#include "MainWindow.h"
class MainWindow;
class DocumentObserver {
    friend class MainWindow;
public:
    virtual ~DocumentObserver();
    DocumentObserver(const DocumentObserver &) = delete;
    DocumentObserver &operator=(const DocumentObserver &) = delete;
    virtual void pageChanged(int page) = 0;
    virtual void documentLoaded() = 0;
    virtual void documentClosed() = 0;


protected:
    DocumentObserver();
    Poppler::Document *document() const;
    void setPage(int page);
    int page() const;
    void reloadPage();
private:
    MainWindow *m_window;
};


#endif //QTPDFREADER_DOCUMENTOBSERVER_H
