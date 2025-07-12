#include <QFile>
#include <QDebug>

#include "RssParser.h"


RssParser* RssParser::m_instance = nullptr;

RssParser::RssParser() {};
RssParser::~RssParser () {};

RssParser* RssParser::getInstance() {
    if (m_instance == nullptr) m_instance = new RssParser();
    return m_instance;
}

void RssParser::extract_token_from_file(const QString& file_path, Feed &feed) {
    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Can't open the file";
    }

    QXmlStreamReader xml(&file);
   
    //TODO: Infinite loop here, fix it
    while (xml.name() != "rss" || xml.name() != "feed" || xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if (xml.name() == "rss") {
            spec_rss2(token, feed);
            break;
        } else if(xml.name() == "feed") {
            spec_atom(token, feed);
            break;
        }
    } 

    if (xml.hasError()) {
        qWarning() << "Error XML: " << xml.errorString();
    }

    file.close();
}

void RssParser::extract_token_from_url(const QString& url, Feed &feed) {
    //TODO: Implement Network Solution

    //QXmlStreamReader xml(&file_from_url);

    //if (xml.hasError()) {
        //qWarning() << "Error XML: " << xml.errorString();
    //}
}

void RssParser::spec_rss2(QXmlStreamReader::TokenType& token, Feed& feed) {
    qDebug() << token << " spec_rss2";
}

void RssParser::spec_atom(QXmlStreamReader::TokenType& token, Feed& feed) {
    qDebug() << token << " spec_atom";
}
