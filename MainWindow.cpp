#include "MainWindow.h"
#include "PBDefines.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    setupGUI();
}

void MainWindow::setupGUI() {
    passportBalanceManager = new PassportBalanceManager;
    highlightedLoggerWidget = new LoggerWidget;
    highlightedLoggerWidget->setFixedHeight(250);
    connect(passportBalanceManager, SIGNAL(logText(QString, Log::Type)), highlightedLoggerWidget, SLOT(appendText(QString,Log::Type)));
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(passportBalanceManager);
    layout->addWidget(highlightedLoggerWidget);
    setLayout(layout);
}

