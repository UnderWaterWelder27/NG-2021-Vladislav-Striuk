#include "spinboxessum.h"
#include "ui_spinboxessum.h"

SpinBoxesSum::SpinBoxesSum(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpinBoxesSum)
{
    ui->setupUi(this);
    ui->s_result->setReadOnly(true);

    connect (ui->s_firstOperand, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpinBoxesSum::changeBoxValue);
    connect (ui->s_secondOperand, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpinBoxesSum::changeBoxValue);
}

SpinBoxesSum::~SpinBoxesSum()
{
    delete ui;
}

void SpinBoxesSum::changeBoxValue()
{
    ui->s_result->setValue(ui->s_firstOperand->value() + ui->s_secondOperand->value());
}

