#include <QApplication>

#include "mainwindow.h"

#include "src/RssParser.h"
#include "src/Feed.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow window;

    Feed feeder = Feed();
    RssParser* parser = RssParser::getInstance();
    parser->extract_tokens_from_file("./rss.xml", feeder);
    
    window.show();
    return app.exec();
}
