#include "dialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>

void Dialog::do_chkBoxUnder(bool checked)
{
    QFont font  = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked)
{
    QFont font  = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked)
{
    QFont font  = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    QPalette plet = txtEdit->palette();
    if(radioBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    if(radioBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    if(radioRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    txtEdit->setPalette(plet);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    chkBoxUnder = new QCheckBox("下划线");
    chkBoxBold = new QCheckBox("加粗");
    chkBoxItalic= new QCheckBox("斜体");

    QHBoxLayout *HLay = new QHBoxLayout();
    HLay->addWidget(chkBoxBold);
    HLay->addWidget(chkBoxItalic);
    HLay->addWidget(chkBoxUnder);

    radioBlack = new QRadioButton("黑色");
    radioBlue = new QRadioButton("蓝色");
    radioRed = new QRadioButton("红色");
    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioBlue);
    HLay2->addWidget(radioRed);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("HELLO WORLD\n代码创建");
    QFont font =  txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    btnOk = new QPushButton("确认");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("退出");
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOk);
    HLay3->addStretch();
    HLay3->addWidget(btnCancel);
    HLay3->addWidget(btnClose);

    QVBoxLayout *Vlay = new QVBoxLayout();
    Vlay->addLayout(HLay);
    Vlay->addLayout(HLay2);
    Vlay->addWidget(txtEdit);
    Vlay->addLayout(HLay3);



    setLayout(Vlay);

    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxUnder(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxBold(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxItalic(bool)));

    connect(radioBlack,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));
    connect(radioRed,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));
    connect(radioBlue,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));

    connect(btnOk,SIGNAL(clicked(bool)),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked(bool)),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked(bool)),this,SLOT(close()));

    setWindowTitle("代码实现");


}

Dialog::~Dialog()
{
}

