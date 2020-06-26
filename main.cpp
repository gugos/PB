#include <QApplication>
#include "MainWindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    app.setStyleSheet("QPushButton {"
                      "width: 150px;"
                      "}");

    MainWindow window;
    window.show();

    return app.exec();
}
