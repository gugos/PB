#include "PassportBalanceManager.h"
#include "MissionFabric.h"
#include "LoggerWidget.h"
#include "PBDefines.h"
#include "TableManager.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QStackedWidget>
#include <QLineEdit>
#include <QHeaderView>
#include <QFileDialog>
#include <QLabel>
#include <QDateEdit>
#include <QComboBox>

PassportBalanceManager::PassportBalanceManager(QWidget *parent) : QWidget(parent) {
    init();
    setupGUI();
    setDefaults();
}

void PassportBalanceManager::init() {
    QStringList missionsList;
    missionsList << "Austria"     << "Bulgaria"  << "Croatia"
                 << "Czech"       << "Denmark"   << "Estonia"
                 << "Finland"     << "France"    << "Germany"
                 << "Greece"      << "Lithuania" << "Malta"
                 << "Netherlands" << "Norway"    << "Poland"
                 << "Portugal"    << "Slovenia"  << "Sweden";

    int value = 0;
    foreach(const QString& missionName, missionsList) {
        missionsMap.insert(missionName, value);
        ++value;
    }
}

void PassportBalanceManager::setupGUI() {
    QHBoxLayout* bodyLayout = new QHBoxLayout;
    QVBoxLayout* centralLayot = new QVBoxLayout;
    QVBoxLayout* leftSideLayout = new QVBoxLayout;
    QHBoxLayout* xmlManageLayout = new QHBoxLayout;
    QVBoxLayout* rightSideLayout = new QVBoxLayout;

    tableManager = new TableManager;
    missionTablesStackedWidget = new QStackedWidget;
    missionXmlPathLineEdit = new QLineEdit;
    missionXmlPathLineEdit->setReadOnly(true);

    QPushButton* selectDirectoryButton = new QPushButton("Select Directory");
    QPushButton* readXmlFilesButton = new QPushButton("Read All");
    QPushButton* reloadXmlFileButton = new QPushButton("Reload");

    connect(selectDirectoryButton, SIGNAL(clicked()), SLOT(selectDirectory()));
    connect(readXmlFilesButton, SIGNAL(clicked()), SLOT(readToTables()));
    connect(reloadXmlFileButton, SIGNAL(clicked()), SLOT(reloadToTable()));

    leftSideLayout->addWidget(selectDirectoryButton);

    QList<QString> missonsList = missionsMap.keys();
    for(int i = 0; i < missonsList.size(); ++i) {
        leftSideLayout->addWidget(createMissonButton(missonsList.at(i)));
        missionTablesStackedWidget->addWidget(createTable());
    }

    leftSideLayout->addStretch(1);
    xmlManageLayout->addWidget(readXmlFilesButton);
    xmlManageLayout->addWidget(reloadXmlFileButton);
    rightSideLayout->addLayout(xmlManageLayout);
    rightSideLayout->addWidget(tableManager);
    centralLayot->addWidget(missionXmlPathLineEdit);
    centralLayot->addWidget(missionTablesStackedWidget);
    bodyLayout->addLayout(leftSideLayout);
    bodyLayout->addLayout(centralLayot);
    bodyLayout->addLayout(rightSideLayout);
    setLayout(bodyLayout);
}

void PassportBalanceManager::setDefaults() {
    currentMission = "Austria";
    QPushButton* button = findChild<QPushButton*>(currentMission);
    setSelectedButtonStyle(button);
    QTableWidget* table = qobject_cast<QTableWidget*>(missionTablesStackedWidget->currentWidget());
    tableManager->setActiveTable(table);
}

QPushButton* PassportBalanceManager::createMissonButton(const QString& missionName) {
    QPushButton* button = new QPushButton(missionName);
    button->setObjectName(missionName);
    connect(button, SIGNAL(clicked()), SLOT(switchMission()));
    setDefaultButtonStyle(button);
    return button;
}

void PassportBalanceManager::switchMission() {
    QPushButton* button = findChild<QPushButton*>(currentMission);
    setDefaultButtonStyle(button);
    button = qobject_cast<QPushButton*>(sender());
    setSelectedButtonStyle(button);
    currentMission = button->objectName();
    int index = missionsMap[currentMission];
    missionTablesStackedWidget->setCurrentIndex(index);
    QTableWidget* table = qobject_cast<QTableWidget*>(missionTablesStackedWidget->currentWidget());
    tableManager->setActiveTable(table);
}

void PassportBalanceManager::setDefaultButtonStyle(QPushButton* button) {
    button->setStyleSheet(styleSheet());
    button->setStyleSheet("background-image: url(:/flags/" + button->objectName() + ".png);"
                          "background-repeat: no-repeat;"
                          "background-position: left;");
}

void PassportBalanceManager::setSelectedButtonStyle(QPushButton* button) {
    button->setStyleSheet("background-color: grey;"
                          "background-image: url(:/flags/" + button->objectName() + ".png);"
                          "background-repeat: no-repeat;"
                          "background-position: left;");
}

void PassportBalanceManager::selectDirectory() {
    QString path = QFileDialog::getExistingDirectory(
                this,
                "Open File",
                QDir::homePath(),
                QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(!path.isEmpty()) {
        missionXmlPathLineEdit->setText(path);
    }
}

void PassportBalanceManager::readToTables() {
    if(missionXmlPathLineEdit->text().isEmpty()) {
        return;
    }

    QMap<QString, int>::const_iterator it = missionsMap.constBegin();
    while(it != missionsMap.constEnd()) {
        try {
            QTableWidget* table = qobject_cast<QTableWidget*>(missionTablesStackedWidget->widget(it.value()));
            parseMissionDataToTable(it.key(), table);
        } catch(const QString& errorMessage) {
            emit logText(errorMessage, Log::Type::Error);
        }

        ++it;
    }
}

void PassportBalanceManager::reloadToTable() {
    if(missionXmlPathLineEdit->text().isEmpty()) {
        return;
    }

    try {
        QTableWidget* table = qobject_cast<QTableWidget*>(missionTablesStackedWidget->currentWidget());
        parseMissionDataToTable(currentMission, table);
    } catch(const QString& errorMessage) {
        emit logText(errorMessage, Log::Type::Error);
    }
}

void PassportBalanceManager::parseMissionDataToTable(const QString& missionName, QTableWidget* table) {
    QScopedPointer<Mission> mission(MissionFabric::getMission(missionName));
    if(!mission) {
        throw QString("No object for mission: %1").arg(missionName);
    }

    table->clearContents();
    table->setRowCount(0);
    QString pathToFile = QString("%1/%2.xml").arg(missionXmlPathLineEdit->text()).arg(missionName);
    mission->parseXmlToTable(pathToFile, table);
    table->sortByColumn(DaysInSafeIndex);
    emit logText(pathToFile, Log::Type::Success);
}

QTableWidget* PassportBalanceManager::createTable() {
    QTableWidget* table = new QTableWidget;
    table->setColumnCount(TableColumnCount);
    table->setEditTriggers(QTableWidget::NoEditTriggers);
    QHeaderView* header = table->horizontalHeader();
    header->setResizeMode(QHeaderView::Stretch);
    QStringList headersList(QStringList()
                            << Column1Header
                            << Column2Header
                            << Column3Header
                            << Column4Header
                            << Column5Header
                            << Column6Header);

    table->setHorizontalHeaderLabels(headersList);
    table->horizontalHeader()->sortIndicatorOrder();
    return table;
}

