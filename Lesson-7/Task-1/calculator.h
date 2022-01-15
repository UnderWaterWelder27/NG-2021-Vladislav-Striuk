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

    double saveLeftOperand;
    double saveRightOperand;
    bool checkOperatorInput;
    QString saveLastOperation;

private slots:
    void numInput();
    void dotInput();

    void unaryOpearation();
    void inMemoryOperation();
    bool calculateOperation(double rightOperand, QString opButton);

    void wrongAction();
    void expressionResult();
    void clearLabel();
};
#endif // CALCULATOR_H
