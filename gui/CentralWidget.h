#pragma once

#include <QWidget>
#include <QMainWindow>


class CentralWidget: public QWidget {
    Q_OBJECT

public:
    CentralWidget(QMainWindow* parent = nullptr);
    ~CentralWidget();
};
