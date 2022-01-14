#include "calculator.h"
#include "ui_calculator.h"

#include <cmath>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    leftOperand = 0.0;
    rightOperand = 0.0;
    checkOperatorInput = true;
    percentActive = false;

    ui->setupUi(this);

    /// NUMBERS
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

    /// DOT
    connect (ui->b_dot, &QPushButton::clicked, this, &Calculator::Calculator::dotInput);

    /// CLEAR LABEL
    connect (ui->b_backspaceLabel, &QPushButton::clicked, this, &Calculator::clearLabel);
    connect (ui->b_clearLabel, &QPushButton::clicked, this, &Calculator::clearLabel);

    /// UNARY OPERATIONS
    connect (ui->b_operatorPercentage, &QPushButton::clicked, this, &Calculator::unaryOpearation);
    connect (ui->b_operatorPlusMinus, &QPushButton::clicked, this, &Calculator::unaryOpearation);
    connect (ui->b_operatorFraction, &QPushButton::clicked, this, &Calculator::unaryOpearation);
    connect (ui->b_operatorPow, &QPushButton::clicked, this, &Calculator::unaryOpearation);
    connect (ui->b_operatorSqrt, &QPushButton::clicked, this, &Calculator::unaryOpearation);

    /// ADDITIVE OPERATIONS
    connect (ui->b_operatorAdd, &QPushButton::clicked, this, &Calculator::additiveOperation);
    connect (ui->b_operatorSubtract, &QPushButton::clicked, this, &Calculator::additiveOperation);

    /// MULTIPLICATIVE OPERATIONS
    connect (ui->b_operatorMultiply, &QPushButton::clicked, this, &Calculator::multiplicativeOperation);
    connect (ui->b_operatorDivide, &QPushButton::clicked, this, &Calculator::multiplicativeOperation);

    /// EQUAL
    connect (ui->b_operatorEqual, &QPushButton::clicked, this, &Calculator::expressionResult);
}

Calculator::~Calculator()
{
    delete ui;
}




void Calculator::numInput()
{
    QPushButton *numButton = (QPushButton*)sender();
    double fullNum = ui->e_expressionInput->text().toDouble();

    if (ui->e_expressionInput->text() == "0" && fullNum == 0.0)
        return;

    if (checkOperatorInput)
    {
        ui->e_expressionInput->clear();
        checkOperatorInput = false;
    }

    ui->e_expressionInput->setText(ui->e_expressionInput->text()  + numButton->text());

    percentActive = false;
}

void Calculator::dotInput()
{
    if (ui->e_expressionInput->text().isEmpty())
        ui->e_expressionInput->setText("0");
    if (ui->e_expressionInput->text().contains('.') == false)
    {
        ui->e_expressionInput->setText(ui->e_expressionInput->text() + '.');
    }
    checkOperatorInput = false;
}

void Calculator::unaryOpearation()
{
    QPushButton *unarOpButton = (QPushButton*)sender();
    double unaryActionNum = 0.0;

    if (unarOpButton->text() == "%")
        unaryActionNum = (ui->e_expressionInput->text().toDouble()) * 0.01;

    if (unarOpButton->text() == "+-")
        unaryActionNum = (ui->e_expressionInput->text().toDouble()) * (-1);

    if (unarOpButton->text() == "1/x")
    {
        if (ui->e_expressionInput->text().toDouble() == 0)
        {
            wrongAction();
            return;
        }
        else
            unaryActionNum = 1.0 / (ui->e_expressionInput->text().toDouble());
    }

    if (unarOpButton->text() == "x^2")
        unaryActionNum = pow(ui->e_expressionInput->text().toDouble(), 2);

    if (unarOpButton->text() == "sqrt")
    {
        if (ui->e_expressionInput->text().toDouble() < 0)
        {
            wrongAction();
            return;
        }
        unaryActionNum = sqrt(ui->e_expressionInput->text().toDouble());
    }

    QString numString = QString::number(unaryActionNum, 'g', 15);
    ui->e_expressionInput->setText(numString);
}

void Calculator::additiveOperation()
{

}

void Calculator::multiplicativeOperation()
{

}

void Calculator::wrongAction()
{
    ui->e_expressionInput->setText("Error");
    checkOperatorInput = false;
}

void Calculator::expressionResult()
{

}

void Calculator::clearLabel()
{
    QPushButton *clearButton = (QPushButton*)sender();

    if (clearButton->text() == "AC")
    {
        ui->e_expressionInput->setText("");
        checkOperatorInput = true;
    }

    else if (clearButton->text() == "C")
    {
        ui->e_expressionInput->setText(ui->e_expressionInput->text().left(ui->e_expressionInput->text().size() - 1));
        if (ui->e_expressionInput->text().isEmpty())
        {
            ui->e_expressionInput->setText("");
            checkOperatorInput = true;
        }
    }
}



