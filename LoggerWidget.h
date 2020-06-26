#ifndef LOGGERWIDGET_H
#define LOGGERWIDGET_H

#include "PBDefines.h"

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QQueue>
#include <QPlainTextEdit>

class CustomHighlighter : public QSyntaxHighlighter {
    Q_OBJECT
public:
    explicit CustomHighlighter(QTextDocument* parent = nullptr);
    void setHighlighterFormat(const QTextCharFormat& format);
    void resetFormat();

private:
    QTextCharFormat format;
    QTextCharFormat previousFormat;
    QQueue<QTextCharFormat> queue;
    enum { FORMATTED = 1, LAST = 2 };

protected:
    void highlightBlock(const QString& text);
};

class LoggerWidget : public QWidget {
    Q_OBJECT
public:
    explicit LoggerWidget(QWidget* parent = nullptr);
    ~LoggerWidget();
    void setFormat(const QTextCharFormat& format);
    void resetFormat();

public slots:
    void appendText(const QString&, Log::Type type = Log::Type::Default);

private:
    QPlainTextEdit* textEdit;
    CustomHighlighter* highlighter;
    const int blockCount = 150;
};


#endif // LOGGERWIDGET_H

