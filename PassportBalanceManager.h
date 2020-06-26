#ifndef PASSPORTBALANCEMANAGER_H
#define PASSPORTBALANCEMANAGER_H

#include "PBDefines.h"

#include <QWidget>
#include <QMap>
#include <QLineEdit>

class QPushButton;
class QTableWidget;
class QStackedWidget;
class QLineEdit;
class QDateEdit;
class QComboBox;
class TableManager;

class PassportBalanceManager : public QWidget {
    Q_OBJECT
public:
    explicit PassportBalanceManager(QWidget* parent = nullptr);

private:
    QMap<QString, int> missionsMap;
    QString currentMission;
    TableManager* tableManager;
    QStackedWidget* missionTablesStackedWidget;
    QLineEdit* missionXmlPathLineEdit;

    void init();
    void setupGUI();
    void setDefaults();
    QPushButton* createMissonButton(const QString&);
    void setDefaultButtonStyle(QPushButton*);
    void setSelectedButtonStyle(QPushButton*);
    QTableWidget* createTable();
    void parseMissionDataToTable(const QString&, QTableWidget*);

signals:
    void logText(const QString&, Log::Type);

private slots:
    void switchMission();
    void selectDirectory();
    void readToTables();
    void reloadToTable();
};

#endif // PASSPORTBALANCEMANAGER_H
