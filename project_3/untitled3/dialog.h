#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QPlainTextEdit;
class QPushButton;
class QRadioButton;
class QCheckBox;

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;

    QRadioButton *radioBlack;
    QRadioButton *radioRed;
    QRadioButton *radioBlue;

    QPlainTextEdit *txtEdit;

    QPushButton *btnOk;
    QPushButton *btnCancel;
    QPushButton *btnClose;

private slots:
    void do_chkBoxUnder(bool checked);
    void do_chkBoxItalic(bool checked);
    void do_chkBoxBold(bool checked);

    void do_setFontColor();

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
