#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <QWidget>

class QTableWidget;
class QComboBox;
class QLineEdit;
class QDateEdit;
class QLabel;

class TableManager : public QWidget {
    Q_OBJECT
public:
    explicit TableManager(QWidget* parent = nullptr);

    void setActiveTable(QTableWidget*);

private:
    QTableWidget* table;
    QDateEdit* submissionDateEdit;
    QLineEdit* referenceLineEdit;
    QLineEdit* applicantNameLineEdit;
    QLineEdit* passportLineEdit;
    QLineEdit* daysInSafeLineEdit;
    QComboBox* sortComboBox;
    QLineEdit* searchLineEdit;
    QLabel* defaultColorLabel;
    QLineEdit* scannedBarcodeLineEdit;

    void setupGUI();

private slots:
    void removeFromTable();
    void addToTable();
    void sortTable();
    void searchInTable();
    void pickColor();
    void searchBarcode(const QString&);
};

#endif // TABLEMANAGER_H
