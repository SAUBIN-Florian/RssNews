#pragma once

#include <QXmlStreamReader>
#include <QString>

#include "Feed.h"


class RssParser {
public:
    static RssParser* getInstance();
    void extract_token_from_file(const QString& file_path, Feed& feed);
    void extract_token_from_url(const QString& url, Feed& feed);

private:
    RssParser();
    ~RssParser();
    void spec_rss2(QXmlStreamReader::TokenType& token, Feed& feed);
    void spec_atom(QXmlStreamReader::TokenType& token, Feed& feed);

private:
    static RssParser* m_instance;
};
