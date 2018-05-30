#include "dialogadd.h"
#include "ui_dialogadd.h"

DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);

}

QString DialogAdd::getDtxtTitle(){
    return ui->DtxtTitle->text();
}
QString DialogAdd::getDtxtAuthor(){
    return ui->DtxtAuthor->text();
}
QString DialogAdd::getDtxtLang(){
    return ui->DtxtLang->text();
}
QString DialogAdd::getDtxtPrice(){
    return ui->DtxtPrice->text();
}
QString DialogAdd::getDtxtYear(){
    return ui->DtxtYear->text();
}

bool DialogAdd::getResult(){
    return result;
}


DialogAdd::~DialogAdd()
{
    delete ui;
}

void DialogAdd::on_DbtOk_clicked()
{
    result = true;

    this->close();
}

void DialogAdd::on_DbtCancel_clicked()
{
    result = false;

    this->close();
}
