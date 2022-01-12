#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

/// NUMBERS CLICK ///
    connect (ui->b_num_0, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_1, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_2, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_3, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_4, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_5, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_6, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_7, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_8, &QPushButton::clicked, this, &Calculator::numInput);
    connect (ui->b_num_9, &QPushButton::clicked, this, &Calculator::numInput);

/// DOT ///
    connect (ui->b_dot, &QPushButton::clicked, this, &Calculator::Calculator::addDot);

/// CLEAR LABEL ///
    connect (ui->b_actionClear, &QPushButton::clicked, this, &Calculator::clearLabel);
    connect (ui->b_actionClearAll, &QPushButton::clicked, this, &Calculator::clearLabel);

/// OPERATIONS ///
    connect (ui->b_operatorPercentage, &QPushButton::clicked, this, &Calculator::operationPercentage);
    connect (ui->b_operatorAdd, &QPushButton::clicked, this, &Calculator::operators);
    connect (ui->b_operatorSubtract, &QPushButton::clicked, this, &Calculator::operators);
    connect (ui->b_operatorMultiply, &QPushButton::clicked, this, &Calculator::operators);
    connect (ui->b_operatorDivide, &QPushButton::clicked, this, &Calculator::operators);

    ui->b_operatorAdd->setCheckable(true);
    ui->b_operatorSubtract->setCheckable(true);
    ui->b_operatorMultiply->setCheckable(true);
    ui->b_operatorDivide->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numInput()
{
    QPushButton *numButton = (QPushButton*)sender();
    double fullNum = (ui->e_expressionInput->text() + numButton->text()).toDouble();
    QString numString = QString::number(fullNum, 'g', 15);
    ui->e_expressionInput->setText(numString);
}

void Calculator::addDot()
{
    if (ui->e_expressionInput->text().contains('.') == false)
        ui->e_expressionInput->setText(ui->e_expressionInput->text() + '.');
}

void Calculator::operationPercentage()
{
    double percentNum = (ui->e_expressionInput->text().toDouble()) * 0.01;
    QString numString = QString::number(percentNum, 'g', 15);
    ui->e_expressionInput->setText(numString);
}

void Calculator::operators()
{
    QPushButton *operatorButton = (QPushButton*)sender();
    operatorButton->setChecked(true);
}

void Calculator::clearLabel()
{
    QPushButton *clearButton = (QPushButton*)sender();

    if (clearButton->text() == "AC")
        ui->e_expressionInput->clear();
    else if (clearButton->text() == "C")
        ui->e_expressionInput->clear();
}


