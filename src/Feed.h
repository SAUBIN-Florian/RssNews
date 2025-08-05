#pragma once

#include <QString>
#include <QVector>
#include <QDateTime>


class FeedItem {
public:
    FeedItem();
    ~FeedItem();

    const QString& guid() const;
    const QString& title() const;
    const QString& description() const;
    const QString& link() const;
    const QString& content() const;
    const QString& author() const;
    const QDateTime& pubDate() const;

    void setGuid(QString guid);
    void setTitle(QString title);
    void setDescription(QString description);
    void setLink(QString link);
    void setContent(QString content);
    void setAuthor(QString author);
    void setPubDate(QDateTime pub_date);

private:
    QString m_guid = "";
    QString m_title = "";
    QString m_description = "";
    QString m_link = "";
    QString m_content = "";
    QString m_author = "";
    QDateTime m_pubdate;
};

class Feed {
public:
    Feed();
    ~Feed();

    const QString& title() const;
    const QString& description() const;
    const QString& link() const;
    const QString& imageUrl() const;
    const QVector<FeedItem>& items() const;

    void setTitle(QString title);
    void setDescription(QString description);
    void setLink(QString link);
    void setImageUrl(QString image_url);
    void appendItem(FeedItem& item);

private:
   QString m_title = "";
   QString m_description = "";
   QString m_link = "";
   QString m_image_url = "";
   QVector<FeedItem> m_items;
};
