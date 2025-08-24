#pragma once

#include <QXmlStreamReader>
#include <QString>

#include "Feed.h"


class RssParser {
public:
    RssParser();
    ~RssParser();

    void extract_tokens_from_file(const QString& file_path, Feed& feed);
    void extract_tokens_from_url(const QString& url, Feed& feed);

private:
    void spec_rss2(QXmlStreamReader& xml, Feed& feed);
    void spec_atom(QXmlStreamReader& xml, Feed& feed);
};
