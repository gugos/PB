#include "TableManager.h"
#include "CustomWidgets.h"

#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QColorDialog>

TableManager::TableManager(QWidget* parent) : QWidget(parent) {
    setupGUI();
}

void TableManager::setActiveTable(QTableWidget* table) {
    this->table = table;
}

void TableManager::setupGUI() {
    QVBoxLayout* layout = new QVBoxLayout;
    QHBoxLayout* tableItemManageLayout = new QHBoxLayout;
    QHBoxLayout* sortTableManageLayout = new QHBoxLayout;
    QHBoxLayout* searchManageLayout = new QHBoxLayout;
    QHBoxLayout* colorPickerLayout = new QHBoxLayout;

    submissionDateEdit = new QDateEdit;
    submissionDateEdit->setDate(QDate::currentDate());
    submissionDateEdit->setDisplayFormat("yyyy/MM/dd");
    submissionDateEdit->setCalendarPopup(true);
    referenceLineEdit = new QLineEdit;
    applicantNameLineEdit = new QLineEdit;
    passportLineEdit = new QLineEdit;
    daysInSafeLineEdit = new QLineEdit;

    QPushButton* removeButton = new QPushButton("Remove");
    QPushButton* addButton = new QPushButton("Add");

    connect(removeButton, SIGNAL(clicked()), SLOT(removeFromTable()));
    connect(addButton, SIGNAL(clicked()), SLOT(addToTable()));

    sortComboBox = new QComboBox;
    for(int i = 0; i < TableColumnCount; ++i) {
        sortComboBox->insertItem(i, QString("Column #%1").arg(i + 1));
    }

    QPushButton* sortButton = new QPushButton("Sort Table");
    connect(sortButton, SIGNAL(clicked()), SLOT(sortTable()));

    searchLineEdit = new QLineEdit;
    QPushButton* searchButton = new QPushButton("Search");
    connect(searchButton, SIGNAL(clicked(bool)), SLOT(searchInTable()));

    defaultColorLabel = new QLabel;
    defaultColorLabel->setStyleSheet("background-color: rgb(255,128,0)");
    QPushButton* pickColorButton = new QPushButton("Pick Color");
    connect(pickColorButton, SIGNAL(clicked()), SLOT(pickColor()));
    scannedBarcodeLineEdit = new QLineEdit;
    connect(scannedBarcodeLineEdit, SIGNAL(textChanged(QString)), SLOT(searchBarcode(QString)));

    layout->addWidget(new QLabel(Column1Header));
    layout->addWidget(submissionDateEdit);
    layout->addWidget(new QLabel(Column2Header));
    layout->addWidget(referenceLineEdit);
    layout->addWidget(new QLabel(Column4Header));
    layout->addWidget(applicantNameLineEdit);
    layout->addWidget(new QLabel(Column5Header));
    layout->addWidget(passportLineEdit);
    layout->addWidget(new QLabel(Column6Header));
    layout->addWidget(daysInSafeLineEdit);
    tableItemManageLayout->addWidget(removeButton);
    tableItemManageLayout->addWidget(addButton);
    layout->addLayout(tableItemManageLayout);
    layout->addWidget(new QLabel("Sort by"));
    sortTableManageLayout->addWidget(sortComboBox);
    sortTableManageLayout->addWidget(sortButton);
    layout->addLayout(sortTableManageLayout);
    layout->addWidget(new QLabel("Search for Match"));
    layout->addWidget(searchLineEdit);
    searchManageLayout->setAlignment(Qt::AlignRight);
    searchManageLayout->addWidget(searchButton);
    layout->addLayout(searchManageLayout);
    colorPickerLayout->addWidget(defaultColorLabel);
    colorPickerLayout->addWidget(pickColorButton);
    layout->addLayout(colorPickerLayout);
    layout->addWidget(new QLabel("Scan Barcode"));
    layout->addWidget(scannedBarcodeLineEdit);
    layout->addStretch(1);
    layout->setMargin(0);
    setLayout(layout);
    setFixedWidth(335);
}

void TableManager::removeFromTable() {
    if(!table) {
        return;
    }

    table->removeRow(table->currentRow());
}

void TableManager::addToTable() {
    if(!table) {
        return;
    }

    QString submissionDate = QString("%1T00:00:00").arg(submissionDateEdit->date().toString("yyyy-MM-dd"));
    table->insertRow(table->rowCount());
    int row = table->rowCount() - 1;
    table->setItem(row, SubmissionIndex, new QTableWidgetItem(submissionDate));
    table->setItem(row, ReferenceIndex, new QTableWidgetItem(referenceLineEdit->text()));
    table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(applicantNameLineEdit->text()));
    table->setItem(row, PassportIndex, new QTableWidgetItem(passportLineEdit->text()));
    QString daysInSafe = daysInSafeLineEdit->text();
    table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(daysInSafe.isEmpty() ? "0" : daysInSafe));
}

void TableManager::sortTable() {
    if(!table) {
        return;
    }

    table->sortByColumn(sortComboBox->currentIndex());
}

void TableManager::searchInTable() {
    QString text = searchLineEdit->text();
    if(text.isEmpty() || !table) {
        return;
    }

    QList<QTableWidgetItem*> foundList = table->findItems(text, Qt::MatchContains);
    table->clearSelection();
    for(int i = 0; i < foundList.size(); ++i) {
        table->scrollToItem(foundList[i]);
        foundList[i]->setSelected(true);
    }
}

void TableManager::pickColor() {
    QColor currentColor = defaultColorLabel->palette().background().color();
    QColor color = QColorDialog::getColor(currentColor);
    if(color.isValid()) {
        defaultColorLabel->setStyleSheet(QString("background-color: %1").arg(color.name()));
    }
}

void TableManager::searchBarcode(const QString& scannedBarcode) {
    if(!table || scannedBarcode.isEmpty()) {
        return;
    }

    QTableWidgetItem* item = table->item(0, BarcodeIndex);
    if(!item) {
        return;
    }

    if(scannedBarcode.length() != item->text().length()) {
        return;
    }

    for(int i = 0; i < table->rowCount(); ++i) {
        if(QString::compare(scannedBarcode, table->item(i, BarcodeIndex)->text(), Qt::CaseInsensitive) == 0) {
            QColor color = defaultColorLabel->palette().background().color();
            table->item(i, ReferenceIndex)->setBackgroundColor(color);
            table->item(i, BarcodeIndex)->setBackgroundColor(color);
            table->item(i, ApplicantNameIndex)->setBackgroundColor(color);
            table->scrollToItem(table->item(i, BarcodeIndex));
            scannedBarcodeLineEdit->clear();
            break;
        }
    }
}
