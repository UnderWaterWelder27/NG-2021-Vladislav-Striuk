#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

    double leftOperand;
    double rightOperand;
    bool checkOperatorInput;
    bool percentActive;

private slots:
    void numInput();
    void dotInput();

    void unaryOpearation();
    void additiveOperation();
    void multiplicativeOperation();

    void wrongAction();
    void expressionResult();
    void clearLabel();
};
#endif // CALCULATOR_H
