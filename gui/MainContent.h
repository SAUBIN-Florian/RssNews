#pragma once

#include <QWidget>


class MainContent: public QWidget {
    Q_OBJECT

public:
    MainContent(QWidget* parent = nullptr);
    ~MainContent();
};
