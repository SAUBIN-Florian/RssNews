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

void RssParser::extract_tokens_from_file(const QString& file_path, Feed &feed) {
    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Can't open the file";
    }

    QXmlStreamReader xml(&file);
    //TODO: Fix infinite loop here: 
    while (!xml.atEnd() || !xml.hasError()) {
        if (xml.name() == "rss") {
            spec_rss2(xml, feed);
            break;
        } else if(xml.name() == "feed") {
            spec_atom(xml, feed);
            break;
        }
    } 

    if (xml.hasError()) {
        qWarning() << "Error XML: " << xml.errorString();
    }

    file.close();
}

void RssParser::extract_tokens_from_url(const QString& url, Feed &feed) {
    //TODO: Implement Network Solution

    //QXmlStreamReader xml(&file_from_url);

    //if (xml.hasError()) {
        //qWarning() << "Error XML: " << xml.errorString();
    //}
}

void RssParser::spec_rss2(QXmlStreamReader& xml, Feed& feed) {
    QXmlStreamReader::TokenType token = xml.readNext();
    
    qDebug() << token << " spec_rss2";

    if (xml.hasError()) {
        qWarning() << "Error XML: " << xml.errorString();
    }

}

void RssParser::spec_atom(QXmlStreamReader& xml, Feed& feed) {
    QXmlStreamReader::TokenType token = xml.readNext();
    
    qDebug() << token << " spec_atom";

    if (xml.hasError()) {
        qWarning() << "Error XML: " << xml.errorString();
    }

}
