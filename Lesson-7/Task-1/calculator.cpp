#include "calculator.h"
#include "ui_calculator.h"

double first_number = 0;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    //checkOperatorInput = true;
    ui->setupUi(this);

/// NUMBERS CLICK
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
    connect (ui->b_operatorPercentage, &QPushButton::clicked, this, &Calculator::operationPercentage);
    connect (ui->b_operatorFraction, &QPushButton::clicked, this, &Calculator::operationPercentage);
    connect (ui->b_operatorPlusMinus, &QPushButton::clicked, this, &Calculator::operationPercentage);
    connect (ui->b_operatorPow, &QPushButton::clicked, this, &Calculator::operationPercentage);
    connect (ui->b_operatorSqrt, &QPushButton::clicked, this, &Calculator::operationPercentage);

/// BINARY OPERATIONS
//  ADDITIVE
    connect (ui->b_operatorAdd, &QPushButton::clicked, this, &Calculator::operators);
    connect (ui->b_operatorSubtract, &QPushButton::clicked, this, &Calculator::operators);

//  MULTIPLICATIVE
    connect (ui->b_operatorMultiply, &QPushButton::clicked, this, &Calculator::operators);
    connect (ui->b_operatorDivide, &QPushButton::clicked, this, &Calculator::operators);

    ui->b_operatorAdd->setCheckable(true);
    ui->b_operatorSubtract->setCheckable(true);
    ui->b_operatorMultiply->setCheckable(true);
    ui->b_operatorDivide->setCheckable(true);

    connect (ui->b_operatorEqual, &QPushButton::clicked, this, &Calculator::resultExpression);
}

Calculator::~Calculator()
{
    delete ui;
}

/*
    REALIZED FUNCTIONS :
void Calculator::numInput();
void Calculator::dotInput();
void Calculator::clearLabel();



*/


void Calculator::numInput()
{
    QPushButton *numButton = (QPushButton*)sender();
    double fullNum = (ui->e_expressionInput->text() + numButton->text()).toDouble();
    QString numString = QString::number(fullNum, 'g', 15);
    ui->e_expressionInput->setText(numString);
    ui->e_expressionOutput->setText(ui->e_expressionOutput->text() + numButton->text());
}

void Calculator::dotInput()
{
    //if (checkOperatorInput)
        //ui->e_expressionInput->setText("0");
    if (ui->e_expressionInput->text().contains('.') == false)
    {
        ui->e_expressionInput->setText(ui->e_expressionInput->text() + '.');
        ui->e_expressionOutput->setText(ui->e_expressionOutput->text() + '.');
    }
    //checkOperatorInput = false;
}


void Calculator::operationPercentage()                                      // does not ready
{
    //if (checkOperatorInput)
    //{
        double percentNum = (ui->e_expressionInput->text().toDouble()) * 0.01;
        QString numString = QString::number(percentNum, 'g', 15);
        ui->e_expressionInput->setText(numString);
    //}
    //else
        //ui->e_expressionInput->setText("ERROR");
    ui->e_expressionOutput->setText(ui->e_expressionOutput->text() + "%");
}

void Calculator::operators()                                                // does not ready
{
    QPushButton *operatorButton = (QPushButton*)sender();
    first_number = ui->e_expressionInput->text().toDouble();
    ui->e_expressionInput->setText("");
    operatorButton->setChecked(true);
}

void Calculator::clearLabel()
{
    QPushButton *clearButton = (QPushButton*)sender();

    if (clearButton->text() == "AC")
    {
        ui->e_expressionInput->setText("0");
        ui->e_expressionOutput->setText("");
        //checkOperatorInput = true;
    }
    else if (clearButton->text() == "C")
    {
        //if (checkOperatorInput)
            //return;
        //else
        //{
            ui->e_expressionInput->setText(ui->e_expressionInput->text().left(ui->e_expressionInput->text().size() - 1));
            ui->e_expressionOutput->setText(ui->e_expressionInput->text());
            if (ui->e_expressionInput->text().isEmpty())
            {
                ui->e_expressionInput->setText("0");
                ui->e_expressionOutput->setText("");
                //checkOperatorInput = true;
            }
        //}
    }
}

void Calculator::resultExpression()
{
    double second_number = ui->e_expressionInput->text().toDouble(),
           result = 0;

    if (ui->b_operatorAdd->isChecked())
    {
        result = first_number + second_number;
        ui->b_operatorAdd->setChecked(false);
    }
    else if (ui->b_operatorSubtract->isChecked())
    {
        result = first_number - second_number;
        ui->b_operatorSubtract->setChecked(false);
    }
    else if (ui->b_operatorMultiply->isChecked())
    {
        result = first_number * second_number;
        ui->b_operatorMultiply->setChecked(false);
    }
    else if (ui->b_operatorDivide->isChecked())
    {
        result = first_number / second_number;
        ui->b_operatorDivide->setChecked(false);
    }

    QString resultString = QString::number(result, 'g', 15);
    ui->e_expressionInput->setText(resultString);
}


