#ifndef PBDEFINES_H
#define PBDEFINES_H

#include <QString>

namespace Log {
    enum Type { Error = -1, Default = 0, Success = 1 };
}

namespace ScaleLevel {
    enum {
        Low = 10,
        AboveLow = 9,
        BelowAverage = 14,
        AboveAverage = 13,
        BelowHigh = 20,
        AboveHigh = 19
    };
}

const int SubmissionIndex = 0;
const int ReferenceIndex = 1;
const int BarcodeIndex = 2;
const int ApplicantNameIndex = 3;
const int PassportIndex = 4;
const int DaysInSafeIndex = 5;

const int TableColumnCount = 6;

const QString Column1Header("Date of Submission");
const QString Column2Header("Reference #");
const QString Column3Header("Barcode #");
const QString Column4Header("Applicant Name");
const QString Column5Header("Passport #");
const QString Column6Header("Days in Safe");

#endif // PBDEFINES_H

