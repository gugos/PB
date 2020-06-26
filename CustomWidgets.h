#ifndef CUSTOMWIDGETS_H
#define CUSTOMWIDGETS_H

#include <QTableWidgetItem>

#include "PBDefines.h"

class HighlightedIntTableWidgetItem : public QTableWidgetItem {
private:
    void highlightItemBackgroundColor() {
        bool ok;
        int count = text().toInt(&ok);
        if(!ok) {
            return;
        }

        if(count < ScaleLevel::Low) {
            setBackgroundColor(Qt::cyan);
        }
        else if(count > ScaleLevel::AboveLow && count < ScaleLevel::BelowAverage) {
            setBackgroundColor(Qt::yellow);
        }
        else if(count > ScaleLevel::AboveAverage && count < ScaleLevel::BelowHigh) {
            setBackgroundColor(Qt::magenta);
        }
        else if(count > ScaleLevel::AboveAverage) {
            setBackgroundColor(Qt::red);
        }
    }

public:
    HighlightedIntTableWidgetItem(const QString& text) {
        setText(text);
        if(!text.isEmpty()) {
            highlightItemBackgroundColor();
        }
    }

    bool operator<(const QTableWidgetItem& other) const {
        return (text().toInt() < other.text().toInt());
    }
};

#endif // CUSTOMWIDGETS_H

