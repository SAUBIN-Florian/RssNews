#include "MainWindow.h"
#include "CentralWidget.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    this->resize(1280, 720);
    CentralWidget* centralWidget = new CentralWidget(this);
    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}
