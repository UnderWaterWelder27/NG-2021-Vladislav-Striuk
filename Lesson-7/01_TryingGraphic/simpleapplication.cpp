#include "simpleapplication.h"
#include "ui_simpleapplication.h"
#include <QMessageBox>
#include <QDebug>

SimpleApplication::SimpleApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleApplication)
{
    ui->setupUi(this);

    connect (ui->b_message, &QPushButton::clicked, this, &SimpleApplication::showSimpleMessage);
    connect (ui->b_critical, &QPushButton::clicked, this, &SimpleApplication::showCriticalMessage);
    connect (ui->b_information, &QPushButton::clicked, this, &SimpleApplication::showInformationMessage);
    connect (ui->b_warning, &QPushButton::clicked, this, &SimpleApplication::showWarningMessage);
    connect (ui->b_question, &QPushButton::clicked, this, &SimpleApplication::showQuestionMessage);
}

SimpleApplication::~SimpleApplication()
{
    delete ui;
}




void SimpleApplication::showSimpleMessage()
{ QMessageBox::about(this, "Попередження", "Займись ділом!"); }

void SimpleApplication::showCriticalMessage()
{ QMessageBox::critical(this, "Халепа", "Неймовірно! Ваш Віндовс зламався!"); }

void SimpleApplication::showInformationMessage()
{ QMessageBox::information(this, "Повідомляємо", "Ви натиснули клавішу"); }

void SimpleApplication::showWarningMessage()
{ QMessageBox::warning(this, "Тисяча чортів!", "Досить клацать!"); }

void SimpleApplication::showQuestionMessage()
{
    QMessageBox::StandardButton choose = QMessageBox::question
            (this, "Отже питання номер один", "Знахабнів, чи шо?", QMessageBox::Yes | QMessageBox::No);

    if (choose ==  QMessageBox::Yes)
    {
        QMessageBox::critical(this, "Вікно знахабнілого", "Не очікував. . .");
        QApplication::quit();
    }
    else
    {
        QMessageBox::information(this, "Повідомляємо", "Ми вас вибачаємо");
        qDebug() << "Button 'No' were clicked";
    }
}
