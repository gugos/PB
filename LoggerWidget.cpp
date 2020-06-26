#include "LoggerWidget.h"
#include <QVBoxLayout>
#include <QTime>

CustomHighlighter::CustomHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent) {
}

void CustomHighlighter::setHighlighterFormat(const QTextCharFormat& format) {
    this->format = format;
}

void CustomHighlighter::resetFormat() {
    this->format = QTextCharFormat();
}

void CustomHighlighter::highlightBlock(const QString& text) {
    if(text.isEmpty()) {
        return;
    }

    int start = 0;
    if(currentBlockState() == LAST) {
        setFormat(start, text.length(), queue.dequeue());
    } else if(currentBlockState() == FORMATTED) {
        setFormat(start, text.length(), previousFormat);
        setCurrentBlockState(LAST);
        queue.enqueue(format);
    } else {
        setFormat(start, text.length(), format);
        previousFormat = format;
        setCurrentBlockState(FORMATTED);
    }
}

LoggerWidget::LoggerWidget(QWidget* parent) : QWidget(parent) {
    textEdit = new QPlainTextEdit;
    textEdit->setMaximumBlockCount(blockCount);
    textEdit->setReadOnly(true);
    highlighter = new CustomHighlighter(textEdit->document());
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    setLayout(layout);
}

LoggerWidget::~LoggerWidget() {
}

void LoggerWidget::setFormat(const QTextCharFormat &format) {
    highlighter->setHighlighterFormat(format);
}

void LoggerWidget::resetFormat() {
    highlighter->resetFormat();
}

void LoggerWidget::appendText(const QString& text, Log::Type type) {
    QTextCharFormat format;
    switch(type) {
    case Log::Type::Error:
        format.setForeground(Qt::red);
        break;
    case Log::Type::Default:
        format.setForeground(Qt::black);
        break;
    case Log::Type::Success:
        format.setForeground(Qt::darkGreen);
        break;
    default:
        resetFormat();
    }

    setFormat(format);
    QString dateTime = QTime::currentTime().toString();
    textEdit->appendPlainText(QString("%1 %2").arg(dateTime).arg(text));
}

