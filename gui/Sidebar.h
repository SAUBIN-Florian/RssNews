#pragma once

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>


class Sidebar: public QWidget {
    Q_OBJECT

public:
    Sidebar(QWidget* parent = nullptr);
    ~Sidebar();

private:
   QListView* m_listView;
   QStandardItemModel* m_model;
};
