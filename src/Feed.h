#pragma once

#include <QString>
#include <QVector>
#include <QDateTime>


class FeedItem {
public:
    FeedItem(QString guid, QString title, QString description, QString link, QString content, QString author, QDateTime pubdate);
    ~FeedItem();

    const QString& guid() const;
    const QString& title() const;
    const QString& description() const;
    const QString& link() const;
    const QString& content() const;
    const QString& author() const;
    const QDateTime& pubDate() const;

private:
    QString m_guid;
    QString m_title;
    QString m_description;
    QString m_link;
    QString m_content;
    QString m_author;
    QDateTime m_pubdate;
};

class Feed {
public:
    Feed(QString title, QString description, QString link, QString image_url = "");
    ~Feed();

    const QString& title() const;
    const QString& description() const;
    const QString& link() const;
    const QString& imageUrl() const;
    const QVector<FeedItem>& items() const;

    void appendItem(FeedItem& item);

private:
   QString m_title;
   QString m_description;
   QString m_link;
   QString m_image_url;
   QVector<FeedItem>* m_items;
};
