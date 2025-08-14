#include <QApplication>

#include "gui/MainWindow.h"
#include "src/RssParser.h"
#include "src/Feed.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow window;

    // TODO: Remove it (debug purpose only)
    Feed feeder = Feed();
    RssParser* parser = RssParser::getInstance();
    parser->extract_tokens_from_file("./rss.xml", feeder);
    // end

    window.show();
    return app.exec();
}
