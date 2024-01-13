#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnClear_clicked();

    void on_btnInitItems_clicked();

    void on_checkBox_clicked(bool checked);

    void on_btnClearList_clicked();

    void on_btnInitCities_clicked();

    void on_comdItems_currentTextChanged(const QString &arg1);

    void on_comdCitys_currentIndexChanged(int index);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
