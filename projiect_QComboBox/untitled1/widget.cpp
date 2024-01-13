#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_btnInitItems_clicked()
{
    QIcon icon;
    ui->comdItems->clear();
    for(int i = 0; i<20; ++i)
        ui->comdItems->addItem(icon,QString("Item%1").arg(i));


}


void Widget::on_checkBox_clicked(bool checked)
{
    ui->comdItems->setEditable(checked);
}


void Widget::on_btnClearList_clicked()
{
    ui->comdItems->clear();
}


void Widget::on_btnInitCities_clicked()
{
    ui->comdCitys->clear();
    QMap<QString,int> City_Zone;
    City_Zone.insert("宜宾",001);
    City_Zone.insert("成都",002);
    City_Zone.insert("乐山",003);
    City_Zone.insert("自贡",004);
    City_Zone.insert("泸州",005);
    foreach(const QString &str,City_Zone.keys())
        ui->comdCitys->addItem(str,City_Zone.value(str));

}













void Widget::on_comdItems_currentTextChanged(const QString &arg1)
{
    ui->plainTextEdit->appendPlainText(arg1);
}


void Widget::on_comdCitys_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    QString str  = ui->comdCitys->currentText()+ui->comdCitys->currentData().toString();
    ui->plainTextEdit->appendPlainText(str);
}

