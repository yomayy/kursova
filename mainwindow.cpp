#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(7);







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRoot(int Id, QString& Title, QString& Author, QString& Lang, int Price, int Year, int Fav)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    QString _id = QString::number(Id);
    QString _price = QString::number(Price);
    QString _year = QString::number(Year);
    QString _fav = QString::number(Fav);

    itm->setText(0,_id);
    itm->setText(1,Title);
    itm->setText(2,Author);
    itm->setText(3,Lang);
    itm->setText(4,_price);
    itm->setText(5,_year);
    itm->setText(6,_fav);




   // ui->treeWidget->addTopLevelItem(itm);


    //AddChild(itm,"one","hello");
    //AddChild(itm,"two","world");

}

void MainWindow::AddChild(QTreeWidgetItem *parent,QString name,QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Description);
    parent->addChild(itm);
}

void MainWindow::on_pushButton_clicked()
{
     ui->treeWidget->clear();

    DbManager db("kursovaya.db");


        vector<BookRecord> tmp;

        QString Title = ui->lineEdit->text();
        QString Author = ui->lineEdit_2->text();
        QString Lang = ui->lineEdit_3->text();
        QString Price = ui->lineEdit_4->text();
        QString Year = ui->lineEdit_5->text();

        if(Title == "") Title = "%";
        if(Author == "") Author = "%";
        if(Lang == "") Lang = "%";

        tmp = db.bookSearch(Title, Author, Lang, "%" + Price + "%", "%" + Year +"%");

        for(int i=0; i<tmp.size(); i++){

            BookRecord t = tmp[i];

            AddRoot(t.Id, t.Title, t.Author, t.Lang, t.Price, t.Year, t.Fav);
        }
}
