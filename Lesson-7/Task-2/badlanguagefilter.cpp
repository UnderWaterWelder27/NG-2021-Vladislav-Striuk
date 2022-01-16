#include "badlanguagefilter.h"
#include "ui_badlanguagefilter.h"

BadLanguageFilter::BadLanguageFilter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BadLanguageFilter)
{
    ui->setupUi(this);
    connect (ui->e_badLanguageDestroyer, &QTextEdit::textChanged, this, &BadLanguageFilter::changeBadToStar);
}

BadLanguageFilter::~BadLanguageFilter()
{
    delete ui;
}

void BadLanguageFilter::changeBadToStar()
{
    QString userInputText = ui->e_badLanguageDestroyer->toPlainText();
    if (userInputText.indexOf("fuck", 0, Qt::CaseInsensitive) == -1) {
        return;
    }
    userInputText.replace("fuck", "****", Qt::CaseInsensitive);

    int cursorPosition = ui->e_badLanguageDestroyer->textCursor().position();               // save last cursor position

    disconnect (ui->e_badLanguageDestroyer, &QTextEdit::textChanged, this, &BadLanguageFilter::changeBadToStar);
    ui->e_badLanguageDestroyer->setText(userInputText);
    connect (ui->e_badLanguageDestroyer, &QTextEdit::textChanged, this, &BadLanguageFilter::changeBadToStar);

    QTextCursor cursor = ui->e_badLanguageDestroyer->textCursor();                          // take text cursor
    cursor.setPosition(cursorPosition);                                                     // set position to last saved
    ui->e_badLanguageDestroyer->setTextCursor(cursor);                                      // set cursor in text

}

