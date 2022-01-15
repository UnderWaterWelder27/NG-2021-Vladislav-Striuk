#include "spinboxessum.h"
#include "ui_spinboxessum.h"

SpinBoxesSum::SpinBoxesSum(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpinBoxesSum)
{
    ui->setupUi(this);

    connect (ui->s_firstOperand, QOverload<int>::of(&QSpinBox::valueChanged), ui->s_result, &SpinBoxesSum::changeBoxValue);
    connect (ui->s_secondOperand, &QSpinBox::valueChanged, ui->s_result, &SpinBoxesSum::changeBoxValue);
}

SpinBoxesSum::~SpinBoxesSum()
{
    delete ui;
}

void SpinBoxesSum::changeBoxValue()
{

}

