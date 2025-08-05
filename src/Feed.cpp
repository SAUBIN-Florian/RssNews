#include "Feed.h"


// Feed implementation
Feed::Feed() {
    m_items = QVector<FeedItem>();    
}

Feed::~Feed() {}

//Feed accessors / mutators
const QString& Feed::title() const { return m_title; }
const QString& Feed::description() const { return m_description; }
const QString& Feed::link() const { return m_link; }
const QString& Feed::imageUrl() const { return m_image_url; }
const QVector<FeedItem>& Feed::items() const { return m_items; }

void Feed::setTitle(QString title) { m_title = title; }
void Feed::setDescription(QString description) { m_description = description; }
void Feed::setLink(QString link) { m_link = link; }
void Feed::setImageUrl(QString image_url) { m_image_url = image_url; }
void Feed::appendItem(FeedItem& item) { m_items.append(item); }

//FeedItem implementation
FeedItem::FeedItem() {}
FeedItem::~FeedItem() {}

//Feeditem accessors / mutators
const QString& FeedItem::guid() const { return m_guid; }
const QString& FeedItem::title() const { return m_title; }
const QString& FeedItem::description() const { return m_description; }
const QString& FeedItem::content() const { return m_content; }
const QString& FeedItem::author() const { return m_author; }
const QDateTime& FeedItem::pubDate() const { return m_pubdate; }

void FeedItem::setGuid(QString guid) { m_guid = guid; }
void FeedItem::setTitle(QString title) { m_title = title; }
void FeedItem::setDescription(QString description) { m_description = description; }
void FeedItem::setLink(QString link) { m_link = link; }
void FeedItem::setContent(QString content) { m_content = content; }
void FeedItem::setAuthor(QString author) { m_author = author; }
void FeedItem::setPubDate(QDateTime pub_date) { m_pubdate = pub_date; }
