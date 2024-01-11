#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAlign_Left_clicked()
{
    ui->textBrowser->setAlignment(Qt::AlignLeft);
}


void MainWindow::on_btnAlign_Center_clicked()
{
    ui->textBrowser->setAlignment(Qt::AlignCenter);

}


void MainWindow::on_btnAlign_Right_clicked()
{
     ui->textBrowser->setAlignment(Qt::AlignRight);
}


void MainWindow::on_btnFont_Bold_clicked(bool checked)
{
    QFont font  = ui->textBrowser->font();
    font.setBold(checked);
    ui->textBrowser->setFont(font);
}


void MainWindow::on_btnFont_Italic_clicked(bool checked)
{
    QFont font  = ui->textBrowser->font();
    font.setItalic(checked);
    ui->textBrowser->setFont(font);
}


void MainWindow::on_btnFont_UnderLine_clicked(bool checked)
{
    QFont font  = ui->textBrowser->font();
    font.setUnderline(checked);
    ui->textBrowser->setFont(font);
}


void MainWindow::on_ckbReadonly_clicked(bool checked)
{
    ui->textBrowser->setReadOnly(checked);
}


void MainWindow::on_ckbEnabled_clicked(bool checked)
{
    ui->textBrowser->setEnabled(checked);
}


void MainWindow::on_ckbClear_clicked(bool checked)
{
    ui->textBrowser->setAutoFillBackground(checked);
}


void MainWindow::on_rbBlack_clicked()
{
    QPalette plet  = ui->textBrowser->palette();
    plet.setColor(QPalette::Text,Qt::black);
    ui->textBrowser->setPalette(plet);
}


void MainWindow::on_rbRed_clicked()
{
    QPalette plet  = ui->textBrowser->palette();
    plet.setColor(QPalette::Text,Qt::red);
    ui->textBrowser->setPalette(plet);
}


void MainWindow::on_rbBlue_clicked()
{
    QPalette plet  = ui->textBrowser->palette();
    plet.setColor(QPalette::Text,Qt::blue);
    ui->textBrowser->setPalette(plet);
}

