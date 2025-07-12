#pragma once

#include <QString>
#include <QVector>
#include <QDateTime>


class FeedItem {
private:
    QString m_guid;
    QString m_title;
    QString m_description;
    QString m_link;
    QString m_content;
    QString m_author;
    QDateTime m_datetime;
};

class Feed {
public:
    explicit Feed();
    ~Feed();

private:
   QString m_title;
   QString m_description;
   QString m_link;
   QString m_image_url;
   QVector<FeedItem> m_items;
};
