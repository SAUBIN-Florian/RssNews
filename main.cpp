#include <QApplication>

#include "gui/MainWindow.h"
#include "src/FeedRepository.h"
#include "src/RssParser.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow window;

    RssParser* parser = new RssParser();
    FeedRepository* repository = FeedRepository::getInstance(&window);
    repository->setParser(parser);

    window.show();
    return app.exec();
}
