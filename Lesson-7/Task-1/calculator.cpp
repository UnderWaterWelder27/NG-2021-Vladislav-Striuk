#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect (ui->b_num_0, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_1, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_2, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_3, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_4, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_5, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_6, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_7, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_8, &QPushButton::clicked, this, &Calculator::clickNumber);
    connect (ui->b_num_9, &QPushButton::clicked, this, &Calculator::clickNumber);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::clickNumber()
{
    QPushButton *numButton = (QPushButton *)sender();
    ui->e_expressionInput->setText(numButton->text());
}

