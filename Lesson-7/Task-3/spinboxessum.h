#ifndef SPINBOXESSUM_H
#define SPINBOXESSUM_H

#include <QMainWindow>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class SpinBoxesSum; }
QT_END_NAMESPACE

class SpinBoxesSum : public QMainWindow
{
    Q_OBJECT

public:
    SpinBoxesSum(QWidget *parent = nullptr);
    ~SpinBoxesSum();

private:
    Ui::SpinBoxesSum *ui;

private slots:
    void changeBoxValue();
};
#endif // SPINBOXESSUM_H
