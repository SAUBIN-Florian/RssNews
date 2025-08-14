#include "CentralWidget.h"

#include <QHBoxLayout>

#include "Sidebar.h"


CentralWidget::CentralWidget(QMainWindow* parent): QWidget(parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout();
    this->setLayout(mainLayout); 

    Sidebar* sidebar = new Sidebar(this);
    mainLayout->addWidget(sidebar);
}

CentralWidget::~CentralWidget() {}
