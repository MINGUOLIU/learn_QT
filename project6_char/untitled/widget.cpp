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


void Widget::on_btnCharJudge_clicked()
{
    QString str = ui->editStr->text();
    if(str.isEmpty()) return;
    for(qint16 i = 0;i<str.size();i++){
        QChar ch = str.at(i);
        char16_t uniCode = ch.unicode();

        QString chStr(ch);
        QString info = chStr+QString::asprintf("\t,Unicode编码=0x%X",uniCode);
        ui->plainTextEdit->appendPlainText(info);
    }
}


void Widget::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_btnGetChars_clicked()
{
    QString str = ui->editChar->text();
    if(str.isEmpty()) return;

    QChar ch = str.at(0);
    char16_t uniCode = ch.unicode();

    QString info = str+QString::asprintf("\t,Unicode编码=0x%X",uniCode);
    ui->plainTextEdit->appendPlainText(info);

    ui->chkDigit->setChecked(ch.isDigit());
    ui->chkLetter->setChecked(ch.isLetter());
    ui->chkLower->setChecked(ch.isLower());
    ui->chkMark->setChecked(ch.isMark());
    ui->chkPunct->setChecked(ch.isPunct());
    ui->chkSpace->setChecked(ch.isSpace());
    ui->chkSymbol->setChecked(ch.isSymbol());
    ui->chkUpper->setChecked(ch.isUpper());
    ui->chkLetterOrNumber->setChecked(ch.isLetterOrNumber());

}

