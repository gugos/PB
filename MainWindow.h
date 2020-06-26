#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "PassportBalanceManager.h"
#include "LoggerWidget.h"
#include "PBDefines.h"

#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    PassportBalanceManager* passportBalanceManager;
    LoggerWidget* highlightedLoggerWidget;

    void setupGUI();
};

#endif // MAINWINDOW_H
