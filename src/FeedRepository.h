#pragma once

#include <QSqlDatabase>
#include <QObject>
#include <QWidget>
#include <QVector>

#include "RssParser.h"
#include "Feed.h"


//SINGLETON PATTERN
class FeedRepository: public QObject {
    Q_OBJECT

public:
    static FeedRepository* getInstance(QWidget* parent = nullptr);
    RssParser* parser();
    void setParser(RssParser* parser);

    QVector<Feed> getAllFeeds();
    Feed getFeedById(int id);
    void saveFeed(Feed* new_feed);
    void updateFeed(int id, Feed* feed);
    void deleteFeed(int id);

private:
    FeedRepository(QWidget* parent = nullptr, RssParser* parser = nullptr);
    ~FeedRepository();

private:
    static FeedRepository* m_instance;
    QSqlDatabase* m_db;
    RssParser* m_parser;
};
