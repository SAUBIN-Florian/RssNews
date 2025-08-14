#include "Sidebar.h"

#include <QVBoxLayout>
#include <QLabel>


Sidebar::Sidebar(QWidget* parent): QWidget(parent) {
    QVBoxLayout* sidebarLayout = new QVBoxLayout();
    this->setLayout(sidebarLayout);

    sidebarLayout->addWidget(new QLabel("Some Label"));
    sidebarLayout->addStretch();
}

Sidebar::~Sidebar() {}
