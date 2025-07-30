#include <QObject>

#include "FeedRepository.h"
#include "RssParser.h"


FeedRepository::FeedRepository(QObject* parent, RssParser* parser): QObject{parent}, m_parser(parser) {
    
}

FeedRepository::~FeedRepository() {}
