#pragma once

#include <QDialog>

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = 0);
    ~DialogAdd();

    QString getDtxtTitle();
    QString getDtxtAuthor();
    QString getDtxtLang();
    QString getDtxtPrice();
    QString getDtxtYear();
    bool getResult();


private slots:
    void on_DbtOk_clicked();

    void on_DbtCancel_clicked();

private:

    bool result;

    Ui::DialogAdd *ui;
};

