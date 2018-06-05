#pragma once

#include <QMainWindow>
#include <QTreeWidget>
#include "dialogadd.h"
#include "dbmanager.h"

namespace Ui {
class MainWindowTree;
}

class MainWindowTree : public QMainWindow
{
    Q_OBJECT

public:

    DialogAdd *d;
    DbManager *db;

    void AddRoot(vector <BookRecord> recs, QString lang);
    void AddChild(QTreeWidgetItem *parent, BookRecord rec);

    QString getSelectedId();

    void fillCombo();

    vector<BookRecord> filterRecsByLang(vector<BookRecord> recs, QString lang);


    void fillColor(QTreeWidgetItem *itm);

    explicit MainWindowTree(QWidget *parent = 0);
    ~MainWindowTree();

private slots:
    void on_btSearch_clicked();

    void on_btAdd_clicked();

    void on_btDelete_clicked();

    void on_btFav_clicked();

    void on_btUnsetFav_clicked();

    void on_cmbLang_currentIndexChanged(int index);

private:
    Ui::MainWindowTree *ui;
};

