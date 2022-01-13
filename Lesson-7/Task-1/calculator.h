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

private slots:
    void numInput();
    void dotInput();
    void operationPercentage();
    void operators();
    void clearLabel();
    void resultExpression();

    /*bool checkOperatorInput;*/
};
#endif // CALCULATOR_H
