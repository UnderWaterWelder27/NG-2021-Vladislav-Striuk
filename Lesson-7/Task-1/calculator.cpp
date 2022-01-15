#include "calculator.h"
#include "ui_calculator.h"

#include <cmath>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{

    saveLeftOperand = 0.0;
    saveRightOperand = 0.0;
    saveLastOperation = "";
    checkOperatorInput = true;

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
    connect (ui->b_operatorAdd, &QPushButton::clicked, this, &Calculator::inMemoryOperation);
    connect (ui->b_operatorSubtract, &QPushButton::clicked, this, &Calculator::inMemoryOperation);

    /// MULTIPLICATIVE OPERATIONS
    connect (ui->b_operatorMultiply, &QPushButton::clicked, this, &Calculator::inMemoryOperation);
    connect (ui->b_operatorDivide, &QPushButton::clicked, this, &Calculator::inMemoryOperation);

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

    if (checkOperatorInput == true)
    {
        ui->e_expressionInput->clear();
        checkOperatorInput = false;
    }

    ui->e_expressionInput->setText(ui->e_expressionInput->text()  + numButton->text());
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
    saveRightOperand = ui->e_expressionInput->text().toDouble();

    if (unarOpButton->text() == "%")
        saveRightOperand = (ui->e_expressionInput->text().toDouble()) * 0.01;

    if (unarOpButton->text() == "+-")
        saveRightOperand = (ui->e_expressionInput->text().toDouble()) * (-1);

    if (unarOpButton->text() == "1/x")
    {
        if (ui->e_expressionInput->text().toDouble() == 0)
        {
            wrongAction();
            return;
        }
        else
            saveRightOperand = 1.0 / (ui->e_expressionInput->text().toDouble());
    }

    if (unarOpButton->text() == "x^2")
        saveRightOperand = pow(ui->e_expressionInput->text().toDouble(), 2);

    if (unarOpButton->text() == "sqrt")
    {
        if (ui->e_expressionInput->text().toDouble() < 0)
        {
            wrongAction();
            return;
        }
        saveRightOperand = sqrt(ui->e_expressionInput->text().toDouble());
    }

    ui->e_expressionInput->setText(QString::number(saveRightOperand));
    checkOperatorInput = true;
}

void Calculator::inMemoryOperation()
{
    QPushButton *operationButton = (QPushButton*)sender();
    saveRightOperand = ui->e_expressionInput->text().toDouble();

    if (saveLastOperation.isEmpty() == false)
    {
        if (calculateOperation(saveRightOperand, saveLastOperation) == false)
        {
            wrongAction();
            return;
        }
        ui->e_expressionOutput->setText(ui->e_expressionOutput->text() + ui->e_expressionInput->text()+ operationButton->text());
        ui->e_expressionInput->setText(QString::number(saveLeftOperand));
        saveLastOperation = operationButton->text();
        checkOperatorInput = true;
        return;
    }

    saveLeftOperand = ui->e_expressionInput->text().toDouble();
    saveLastOperation = operationButton->text();
    ui->e_expressionOutput->setText(ui->e_expressionInput->text() + operationButton->text());
    checkOperatorInput = true;
}

bool Calculator::calculateOperation(double rightOperand, QString opButton)
{
    if (opButton == '+')
        saveLeftOperand += rightOperand;
    if (opButton == '-')
        saveLeftOperand -= rightOperand;
    if (opButton == '*')
        saveLeftOperand *= rightOperand;
    if (opButton == '/')
    {
        if (rightOperand == 0)
            return false;
        saveLeftOperand /= rightOperand;
    }
    return true;
}

void Calculator::wrongAction()
{
    ui->e_expressionInput->setText("Error");
    checkOperatorInput = false;
}

void Calculator::expressionResult()
{
    QPushButton *equalButton = (QPushButton*)sender();
    saveRightOperand = ui->e_expressionInput->text().toDouble();

    if (saveLastOperation.isEmpty() == false)
    {
        if (calculateOperation(saveRightOperand, saveLastOperation) == false)
        {
            wrongAction();
            return;
        }
        ui->e_expressionOutput->setText(QString::number(saveLeftOperand));
        ui->e_expressionInput->setText(QString::number(saveLeftOperand));

        saveLeftOperand = 0.0;
        saveRightOperand = 0.0;
        saveLastOperation.clear();
        checkOperatorInput = true;
        return;
    }

    saveLeftOperand = ui->e_expressionInput->text().toDouble();
    saveLastOperation = equalButton->text();
    ui->e_expressionOutput->setText(ui->e_expressionInput->text() + equalButton->text());
    checkOperatorInput = true;
}

void Calculator::clearLabel()
{
    QPushButton *clearButton = (QPushButton*)sender();

    if (clearButton->text() == "AC")
    {
        ui->e_expressionInput->setText("");
        ui->e_expressionOutput->setText("");
        saveLeftOperand = 0.0;
        saveRightOperand = 0.0;
        saveLastOperation.clear();
        checkOperatorInput = true;
    }

    else if (clearButton->text() == "C")
    {
        ui->e_expressionInput->setText(ui->e_expressionInput->text().left(ui->e_expressionInput->text().size() - 1));
        if (ui->e_expressionInput->text().isEmpty())
        {
            ui->e_expressionInput->setText("");
            ui->e_expressionOutput->setText("");
            checkOperatorInput = true;
        }
    }
}
