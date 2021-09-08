# SIMPLE QT PDFREADER

This project is for have fun
the last goal of this project is creating pdfreader can handle translate on hover using Google Translate api 

### Library
- [Poppler](https://poppler.freedesktop.org/)
- [Qt](https://www.qt.io/)

### Todo
- [X] Open File Using Menu Or Keyboard
- [X] Load Pdf File Using Poppler
- [ ] Show continuous scroll view
- [ ] Implement Selecting Text
- [ ] Show translate on text selection hover (like mouseover addons browser)

### How To Try This Project
- #### Requirement
  - Linux, using the command below to install requirement
    ```shell
    sudo apt install qtcreator cmake lippopler-qt5-dev pkg-config 
    ```
  - Mac, using the command below to install requirement
    ```shell
    brew install qtcreator qt5 poppler-qt5 cmake pkg-config 
    ```
- #### Building And Runnig
  - clone this repo and running the command below to build and running
    ```shell
    mkdir buid && cd build && cmake .. && make && ./qtpdfreader
    ```