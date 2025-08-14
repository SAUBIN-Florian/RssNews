#pragma once

#include <QWidget>


class Sidebar: public QWidget {
    Q_OBJECT

public:
    Sidebar(QWidget* parent = nullptr);
    ~Sidebar();
};
