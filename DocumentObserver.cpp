//
// Created by Ibrahim Hanif on 08/09/21.
//

#include "DocumentObserver.h"

Poppler::Document *DocumentObserver::document() const{
    return m_window->m_doc;
}

DocumentObserver::~DocumentObserver() {
}

DocumentObserver::DocumentObserver(): m_window(nullptr) {
}

void DocumentObserver::setPage(int page) {
    m_window->setPage(page);
}

int DocumentObserver::page() const {
    return m_window->page();
}

void DocumentObserver::reloadPage() {
    m_window->setPage(m_window->page());
}
