#pragma once

#include <QSqlDatabase>
#include <QObject>
#include <QVector>

#include "RssParser.h"
#include "Feed.h"


class FeedRepository: public QObject {
    Q_OBJECT

public:
    explicit FeedRepository(QObject* parent = nullptr, RssParser* parser = nullptr);
    ~FeedRepository();
    
    QVector<Feed> getAllFeeds();
    Feed getFeedById(int id);
    void saveFeed(Feed* new_feed);
    void updateFeed(int id, Feed* feed);
    void deleteFeed(int id);

private:
    QSqlDatabase* m_db;
    RssParser* m_parser;
};
