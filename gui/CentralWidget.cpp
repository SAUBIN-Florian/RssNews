#include "CentralWidget.h"

#include <QHBoxLayout>
#include <QPushButton>

#include "Sidebar.h"


CentralWidget::CentralWidget(QMainWindow* parent): QWidget(parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout();
    this->setLayout(mainLayout);
    
    
}

CentralWidget::~CentralWidget() {}
