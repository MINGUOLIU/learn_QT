#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAlign_Left_clicked();

    void on_btnAlign_Center_clicked();

    void on_btnAlign_Right_clicked();

    void on_btnFont_Bold_clicked(bool checked);

    void on_btnFont_Italic_clicked(bool checked);

    void on_btnFont_UnderLine_clicked(bool checked);

    void on_ckbReadonly_clicked(bool checked);

    void on_ckbEnabled_clicked(bool checked);

    void on_ckbClear_clicked(bool checked);

    void on_rbBlack_clicked();

    void on_rbRed_clicked();

    void on_rbBlue_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
