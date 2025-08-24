#include <QObject>

#include "FeedRepository.h"
#include "RssParser.h"


FeedRepository* FeedRepository::m_instance = nullptr;

FeedRepository* FeedRepository::getInstance(QWidget* parent) {
    if (m_instance == nullptr) m_instance = new FeedRepository(parent);
    return m_instance;
}

FeedRepository::FeedRepository(QWidget* parent, RssParser* parser): QObject{parent}, m_parser(parser) {
    
}

FeedRepository::~FeedRepository() {}

RssParser* FeedRepository::parser() { return m_parser; }
void FeedRepository::setParser(RssParser* parser) { m_parser = parser; }
