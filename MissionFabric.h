#ifndef MISSIONFABRIC_H
#define MISSIONFABRIC_H

#include <QTableWidget>
#include <QStringList>
#include <QFile>
#include <QXmlStreamReader>

#include "CustomWidgets.h"

class Mission {
public:
    Mission() {}
    virtual ~Mission() {}
    virtual void parseXmlToTable(const QString&, QTableWidget*) const = 0;

protected:
    void readXmlToStreamReader(const QString& pathToXmlFile, QXmlStreamReader& reader) const {
        QFile file(pathToXmlFile);

        if(!file.open(QIODevice::ReadOnly)) {
            throw QString("Error occured while reading %1").arg(pathToXmlFile);
        }

        reader.addData(file.readAll());
        file.close();
    }
};

class Austria : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details2" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon2") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name2") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name2") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber2") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe2") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Bulgaria : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Detail" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "ApplicationDate") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "RefNo") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "StickerNo") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "ApplicantName") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "PassportNo") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "NoOfDay") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Croatia : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details3" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon3") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name3") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe3") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Czech : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details3" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon3") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name3") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe3") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Denmark : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd() && reader.name() != "table1") {
            reader.readNext();
        }

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Detail" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "ApplicationDate") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "RefNo") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "StickerNo") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "ApplicantName") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "PassportNo") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "NoOfDay") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Estonia : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details3" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon3") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name3") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_embassybarcodenumber3") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe3") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Finland : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Detail" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "ApplicationDate") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "RefNo") {
                       table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "StickerNo") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "ApplicantName") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "PassportNo") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "NoOfDay") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class France : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details3" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon3") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name3") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe3") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Germany : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details3" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon3") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name3") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe3") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Greece : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd() && reader.name() != "table1") {
            reader.readNext();
        }

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Detail" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "ApplicationDate") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "RefNo") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "StickerNo") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "ApplicantName") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "PassportNo") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "NoOfDay") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Lithuania : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details3" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon3") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name3") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe3") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }

                }
            }
        }
    }
};

class Malta : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Detail" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "ApplicationDate") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "RefNo") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "StickerNo") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "ApplicantName") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "PassportNo") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "NoOfDay") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Netherlands : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details2" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon2") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name2") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name2") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber2") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe2") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Norway : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details3" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon3") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name3") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe3") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Poland : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd() && reader.name() != "table1") {
            reader.readNext();
        }

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Detail" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "ApplicationDate") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "RefNo") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "StickerNo") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "ApplicantName") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "PassportNo") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "NoOfDay") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Portugal : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd() && reader.name() != "table1") {
            reader.readNext();
        }

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Detail" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "ApplicationDate") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "RefNo") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "StickerNo1") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "ApplicantName3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "PassportNo3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Textbox2") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Slovenia : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Details3" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "createdon3") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_name3") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Applicant_Name3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "pcl_passportnumber3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Number_Of_Days_In_Safe3") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class Sweden : public Mission {
public:
    void parseXmlToTable(const QString& pathToXmlFile, QTableWidget* table) const {
        QXmlStreamReader reader;
        readXmlToStreamReader(pathToXmlFile, reader);

        while(!reader.atEnd() && reader.name() != "table1") {
            reader.readNext();
        }

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.name() == "Detail" && reader.isStartElement()) {
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                foreach(const QXmlStreamAttribute& attribute, reader.attributes()) {
                    QString attributeName = attribute.name().toString();
                    if(attributeName == "ApplicationDate") {
                        table->setItem(row, SubmissionIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "RefNo") {
                        table->setItem(row, ReferenceIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "StickerNo1") {
                        table->setItem(row, BarcodeIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "ApplicantName3") {
                        table->setItem(row, ApplicantNameIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "PassportNo3") {
                        table->setItem(row, PassportIndex, new QTableWidgetItem(attribute.value().toString()));
                    }
                    else if(attributeName == "Textbox2") {
                        table->setItem(row, DaysInSafeIndex, new HighlightedIntTableWidgetItem(attribute.value().toString()));
                    }
                }
            }
        }
    }
};

class MissionFabric {
public:
    static Mission* getMission(const QString& missionName) {
             if(missionName == "Austria") return new Austria();
        else if(missionName == "Bulgaria") return new Bulgaria();
        else if(missionName == "Croatia") return new Croatia();
        else if(missionName == "Czech") return new Czech();
        else if(missionName == "Denmark") return new Denmark();
        else if(missionName == "Estonia") return new Estonia();
        else if(missionName == "Finland") return new Finland();
        else if(missionName == "France") return new France();
        else if(missionName == "Germany") return new Germany();
        else if(missionName == "Greece") return new Greece();
        else if(missionName == "Lithuania") return new Lithuania();
        else if(missionName == "Malta") return new Malta();
        else if(missionName == "Netherlands") return new Netherlands();
        else if(missionName == "Norway") return new Norway();
        else if(missionName == "Poland") return new Poland();
        else if(missionName == "Portugal") return new Portugal();
        else if(missionName == "Slovenia") return new Slovenia();
        else if(missionName == "Sweden") return new Sweden();
        else return nullptr;
    }
};

#endif // MISSIONFABRIC_H

