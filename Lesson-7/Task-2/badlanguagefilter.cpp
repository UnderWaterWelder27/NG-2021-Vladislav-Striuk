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
    QTextEdit *inputText = ui->e_badLanguageDestroyer;
    QChar c = inputText->toPlainText().back();
    ui->l_editProcess->setText(c);

    //ui->e_badLanguageDestroyer->insertPlainText("___");
    //ui->e_badLanguageDestroyer->setText("___");
    //ui->e_badLanguageDestroyer->setPlainText("___");
}

