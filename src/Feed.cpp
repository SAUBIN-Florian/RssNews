#include "Feed.h"


// Feed implementation
Feed::Feed(QString title, QString description, QString link, QString image_url)
: m_title{title}, m_description{description}, m_link{link}, m_image_url{image_url} {
    m_items = new QVector<FeedItem>();    
}

Feed::~Feed() {}

//Feed accessors / mutators
const QString& Feed::title() const { return m_title; }
const QString& Feed::description() const { return m_description; }
const QString& Feed::link() const { return m_link; }
const QString& Feed::imageUrl() const { return m_image_url; }
const QVector<FeedItem>& Feed::items() const { return *m_items; }

void Feed::appendItem(FeedItem &item) { m_items->append(item); }


//FeedItem implementation
FeedItem::FeedItem(QString guid, QString title, QString description, QString link, QString content, QString author, QDateTime pubdate)
: m_guid{guid}, m_title{title}, m_description{description}, m_link{link}, m_content{content}, m_author{author}, m_pubdate{pubdate} {}i

FeedItem::~FeedItem() {}

//Feeditem accessors / mutators
const QString& FeedItem::guid() const { return m_guid; }
const QString& FeedItem::title() const { return m_title; }
const QString& FeedItem::description() const { return m_description; }
const QString& FeedItem::content() const { return m_content; }
const QString& FeedItem::author() const { return m_author; }
const QDateTime& FeedItem::pubDate() const { return m_pubdate; }

