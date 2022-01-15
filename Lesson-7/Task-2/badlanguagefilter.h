#ifndef BADLANGUAGEFILTER_H
#define BADLANGUAGEFILTER_H

#include <QMainWindow>
#include <QTextEdit>
#include <QString>
#include <QTextCursor>

QT_BEGIN_NAMESPACE
namespace Ui { class BadLanguageFilter; }
QT_END_NAMESPACE

class BadLanguageFilter : public QMainWindow
{
    Q_OBJECT

public:
    BadLanguageFilter(QWidget *parent = nullptr);
    ~BadLanguageFilter();

private:
    Ui::BadLanguageFilter *ui;

private slots:
    void changeBadToStar();
};
#endif // BADLANGUAGEFILTER_H
