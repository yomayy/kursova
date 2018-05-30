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

    on_btSearch_clicked();
}

MainWindowTree::~MainWindowTree()
{
    delete ui;
}

void MainWindowTree::AddRoot(vector <BookRecord> recs, QString lang)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);

    itm->setText(0, lang);


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

    ui->treeWidget->addTopLevelItem(itm);


    for(int i=0; i<recs.size(); i++)
        AddChild(itm, recs[i]);



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

bool MainWindowTree::contains(vector<QString> langs, QString lang){

         for(int k=0; k<langs.size(); k++){

             if(lang == langs[k])
                 return true;


         }

         return false;


}

vector<QString> MainWindowTree::getLangsFromRecs(vector<BookRecord> recs){
    vector<QString> langs;


    for(int i=0; i<recs.size(); i++){

        QString tmp = recs[i].Lang.toUpper();

        if(!contains(langs, tmp))
             langs.push_back(tmp);

    }

    return langs;
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
    ui->treeWidget->clear();

       BookRecord rec;

       vector<BookRecord> recs; //  TODO: rename

       rec.Title = "%" + ui->txtTitle->text() + "%";
       rec.Author = "%" +  ui->txtAuthor->text() + "%";
       rec.Lang = "%" +  ui->txtLang->text() + "%";
       rec.Price = "%" +  ui->txtPrice->text() + "%";
       rec.Year = "%" +  ui->txtYear->text() + "%";
       rec.Fav = "%%";

       if(ui->checkFav->isChecked()) rec.Fav = "%1%";


       recs = db->search(rec);

       vector<QString> langs;
       langs = getLangsFromRecs(recs);



       for(int i=0; i<langs.size(); i++){
            vector<BookRecord> tmp;
            tmp = filterRecsByLang(recs, langs[i]);

           AddRoot(tmp, langs[i]);

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
