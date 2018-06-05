#include "mainwindowtree.h"
#include "ui_mainwindowtree.h"
#include "dbmanager.h"
#include "dialogadd.h"
#include <iostream>
#include <QDebug>


MainWindowTree::MainWindowTree(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTree)
{
    ui->setupUi(this);
     db = new DbManager("../kursovaya.db");

    ui->treeWidget->setColumnCount(7);

    QStringList names;
    names.append("ID");
    names.append("Title");
    names.append("Author");
    names.append("Language");
    names.append("Price ($)");
    names.append("Year");
    names.append("Favourites");

    ui->treeWidget->setHeaderLabels(names);

    fillCombo();
    on_btSearch_clicked();
}

void MainWindowTree::fillCombo(){


    vector<QString> langs = db->getLangs();

    ui->cmbLang->clear();

    ui->cmbLang->addItem("");
    for(auto val: langs)
        ui->cmbLang->addItem(val);
}

MainWindowTree::~MainWindowTree()
{
    delete ui;
}

void MainWindowTree::AddRoot(vector <BookRecord> recs, QString lang)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, lang);

    fillColor(itm);


    ui->treeWidget->addTopLevelItem(itm);
    for(int i=0; i<recs.size(); i++)
        AddChild(itm, recs[i]);



}


void MainWindowTree::fillColor(QTreeWidgetItem *itm){


    QColor color(137, 199, 182);
    QBrush br(color);

    for(int i=0; i<6; i++)
        itm->setBackground(i, br);

    QColor color2(255, 255, 255);
    QBrush fv(color2);

    for(int i=0; i<6; i++)
        itm->setTextColor(i, color2);


    QColor color3(121, 152, 201);
    QBrush fv1(color3);
    itm->setBackground(6, fv1);


}

void MainWindowTree::AddChild(QTreeWidgetItem *parent, BookRecord rec)
{


    QTreeWidgetItem *itm = new QTreeWidgetItem();

    itm->setText(0,rec.Id);
    itm->setText(1,rec.Title);
    itm->setText(2,rec.Author);
    itm->setText(3,rec.Lang);
    itm->setText(4,rec.Price);
    itm->setText(5,rec.Year);

    QColor colorFv(233, 50, 50);
    if(rec.Fav == "1")
    {
        itm->setTextColor(6,colorFv);
        itm->setText(6,"♥");
    }

    QColor color(173, 132, 199);
    QBrush br(color);

    for(int i=0; i<6; i++)
        itm->setBackground(i, br);

    QColor color2(121, 152, 201);
    QBrush fv(color2);
    itm->setBackground(6, fv);

    parent->addChild(itm);
}


vector<BookRecord> MainWindowTree::filterRecsByLang(vector<BookRecord> recs, QString lang){

        vector<BookRecord> filtered;

        for(int k=0; k<recs.size(); k++){
            QString tmp = recs[k].Lang.toUpper();

             if(tmp == lang)
                 filtered.push_back(recs[k]);

        }

        return filtered;
}

void MainWindowTree::on_btSearch_clicked()
{

    vector<BookRecord> recs;
    BookRecord rec;
    vector<QString> langs;

        // Filling criterias
       rec.Title = ui->txtTitle->text();
       rec.Author = ui->txtAuthor->text();
       rec.Lang = ui->cmbLang->currentText();
       if(ui->checkFav->isChecked()) rec.Fav = "1";

       QString priceFrom = ui->sbPriceFrom->text();
       QString priceTo = ui->sbPriceTo->text();
       QString yearFrom = ui->sbYearFrom->text();
       QString yearTo = ui->sbYearTo->text();

       recs = db->search(rec, priceFrom, priceTo, yearFrom, yearTo);
       langs = db->getLangs();

       ui->treeWidget->clear();

       for(auto lang: langs){
            vector<BookRecord> tmp;
            tmp = filterRecsByLang(recs, lang);

            if(tmp.size()) AddRoot(tmp, lang);
       }
}

void MainWindowTree::on_btAdd_clicked()
{
    BookRecord rec;

    d = new DialogAdd();
    d->setModal(true);
    d->exec();

    rec.Title = d->getDtxtTitle();
    rec.Author =  d->getDtxtAuthor();
    rec.Lang =  d->getDtxtLang();
    rec.Price =  d->getDtxtPrice();
    rec.Year =  d->getDtxtYear();

    if(d->getResult() == true){
        db->add(rec);

    }else{

    }



    fillCombo();
    on_btSearch_clicked();



    delete d;

}

QString MainWindowTree::getSelectedId(){

    QModelIndex index = ui->treeWidget->currentIndex();
    QModelIndex index2 = index.sibling(index.row(), 0);

    QVariant data = ui->treeWidget->model()->data(index2);
    QString text = data.toString();

    return text;

}

void MainWindowTree::on_btDelete_clicked()
{


    db->remove(getSelectedId());


    fillCombo();
    on_btSearch_clicked();

}

void MainWindowTree::on_btFav_clicked()
{

    db->setFav(getSelectedId());
    on_btSearch_clicked();


}

void MainWindowTree::on_btUnsetFav_clicked()
{
    db->unsetFav(getSelectedId());
    on_btSearch_clicked();

}

void MainWindowTree::on_cmbLang_currentIndexChanged(int index)
{
    on_btSearch_clicked();

}
