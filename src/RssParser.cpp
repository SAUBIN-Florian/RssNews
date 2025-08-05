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
	return;
    }

    QXmlStreamReader xml(&file);

    while (!xml.atEnd() && !xml.hasError()) {
	xml.readNext();

	if (xml.name() == "rss") {
            spec_rss2(xml, feed);
            break;
        } else if(xml.name() == "feed") {
            spec_atom(xml, feed);
            break;
        }
    } 

    if (xml.hasError()) {
        qWarning() << "ERROR: Can't find a valid specification (RSS2 and ATOM supported): " << xml.errorString();
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
    while (!xml.atEnd()) {
	xml.readNext();

	if (xml.isStartElement() && xml.name() == "title") feed.setTitle(xml.readElementText());
	else if (xml.isStartElement() && xml.name() == "description") feed.setDescription(xml.readElementText());
	else if (xml.isStartElement() && xml.name() == "link") feed.setLink(xml.readElementText());
	//else if (xml.isStartElement() && xml.name() == "image_url") feed.setImageUrl(xml.readElementText());

	if (xml.isStartElement() && xml.name() == "item") {
	    FeedItem item = FeedItem();

	    while (!(xml.isEndElement() && xml.name() == "item") && !xml.atEnd()) {
		xml.readNext();
		if (!xml.isStartElement()) continue;

		const auto name = xml.name();
		const auto text = xml.readElementText();

		if (name == "title") item.setTitle(text);
		else if (name == "guid") item.setGuid(text);
		else if (name == "description") item.setDescription(text);
		else if (name == "link") item.setLink(text);
		else if (name == "author") item.setAuthor(text);
		//else if (name == "pubDate") item.setPubDate(text);
		else if (name == "content:encoded") item.setContent(text);
	    }
	    feed.appendItem(item);
	}
    }

    if (xml.hasError()) {
        qWarning() << "Error XML (RSS2 specifications): " << xml.errorString();
    }
}

void RssParser::spec_atom(QXmlStreamReader& xml, Feed& feed) {   
    while (!xml.atEnd()) {
	xml.readNext();

        if (xml.isStartElement() && xml.name() == "title") feed.setTitle(xml.readElementText());
	if (xml.name() == "subtitle") feed.setDescription(xml.readElementText());
	if (xml.name() == "link") {
            auto href = xml.attributes().value("href").toString();
            if (!href.isEmpty()) feed.setLink(href);
        }

        if (xml.isStartElement() && xml.name() == "entry") {
            FeedItem item;

            while (!(xml.isEndElement() && xml.name() == "entry")) {
                xml.readNext();

		const auto name = xml.name();
		const auto text = xml.readElementText();

                if (xml.isStartElement()) {
                    if (name == "title") item.setTitle(text);
                    else if (name == "summary") item.setDescription(text);
                    else if (name == "content") item.setContent(text);
                    else if (name == "link") {
                        auto href = xml.attributes().value("href").toString();
                        if (!href.isEmpty()) item.setLink(href);
		    } 
		    else if (name == "id") item.setGuid(text);
		    else if (name == "author") {
                        QString author;
                        while (!(xml.isEndElement() && name == "author")) {
                            xml.readNext();
                            if (xml.isStartElement() && name == "name") {
                                author = text;
                            }
                        }
                        item.setAuthor(author);
                    }
                }
            }
            feed.appendItem(item);
        }
    }
  
    if (xml.hasError()) {
        qWarning() << "Error XML (ATOM specifications): " << xml.errorString();
    }

}
