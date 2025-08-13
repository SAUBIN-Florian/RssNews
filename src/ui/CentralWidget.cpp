#include "CentralWidget.h"

#include <QVBoxLayout>
#include <QPushButton>


CentralWidget::CentralWidget(QMainWindow* parent): QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout();
    this->setLayout(mainLayout);

    mainLayout->addWidget(new QPushButton("Button 1"));
    mainLayout->addWidget(new QPushButton("Button 2"));
    mainLayout->addWidget(new QPushButton("Button 3"));
}

CentralWidget::~CentralWidget() {}
