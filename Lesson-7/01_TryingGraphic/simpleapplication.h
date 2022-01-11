#ifndef SIMPLEAPPLICATION_H
#define SIMPLEAPPLICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SimpleApplication; }
QT_END_NAMESPACE

class SimpleApplication : public QMainWindow
{
    Q_OBJECT

public:
    SimpleApplication(QWidget *parent = nullptr);
    ~SimpleApplication();

private:
    Ui::SimpleApplication *ui;

private slots:
    void showSimpleMessage();
    void showCriticalMessage();
    void showInformationMessage();
    void showWarningMessage();
    void showQuestionMessage();
};
#endif // SIMPLEAPPLICATION_H
