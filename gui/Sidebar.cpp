#include "Sidebar.h"

#include <QVBoxLayout>
#include <QLabel>

#include "../src/Feed.h"
#include "../src/FeedRepository.h"

Sidebar::Sidebar(QWidget* parent): QWidget(parent) {
    QVBoxLayout* sidebarLayout = new QVBoxLayout();
    this->setLayout(sidebarLayout);

    sidebarLayout->addWidget(new QLabel("Some Label"));

    // TODO: "Error can't read the file for extracting data"
    Feed feed = Feed();
    FeedRepository* repository = FeedRepository::getInstance(this);
    repository->parser()->extract_tokens_from_file("../rss.xml", feed);
    sidebarLayout->addWidget(new QLabel(feed.title()));

    sidebarLayout->addStretch();
}

Sidebar::~Sidebar() {}
