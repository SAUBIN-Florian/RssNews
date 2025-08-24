#include "CentralWidget.h"

#include <QHBoxLayout>
#include <QSplitter>

#include "Sidebar.h"
#include "MainContent.h"


CentralWidget::CentralWidget(QMainWindow* parent): QWidget(parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout();
    this->setLayout(mainLayout);
    
    QSplitter* splitter = new QSplitter(Qt::Horizontal);
    Sidebar* sidebar = new Sidebar(this);
    MainContent* content = new MainContent(this);
    splitter->addWidget(sidebar);
    splitter->addWidget(content);
    splitter->setSizes({200, 600});
    
    mainLayout->addWidget(splitter);
}

CentralWidget::~CentralWidget() {}
