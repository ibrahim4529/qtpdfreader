cmake_minimum_required(VERSION 3.20)
project(qtpdfreader)
find_package(PkgConfig)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt@5/5.15.2/" "/usr/local/Cellar/poppler-qt5/21.08.0")

pkg_check_modules(POPPLER REQUIRED poppler-qt5)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qtpdfreader main.cpp MainWindow.cpp MainWindow.h DocumentObserver.cpp DocumentObserver.h PdfPage.cpp PdfPage.h PageViewer.cpp PageViewer.h)
target_include_directories(qtpdfreader PUBLIC ${POPPLER_INCLUDE_DIRS})
target_link_directories(qtpdfreader PUBLIC ${POPPLER_LIBRARY_DIRS})
target_link_libraries(qtpdfreader
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${POPPLER_LIBRARIES}
        )


