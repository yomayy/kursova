#pragma once

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

#include <vector>
#include <sstream>

#include "debug.h"
#include "bookrecord.h"

using namespace std;

class DbManager
{
public:

    DbManager(QString path);
    ~DbManager();

    bool isOpen();
    bool add(BookRecord rec);
    bool remove(QString id);
    bool exist(QString id);
    vector<QString> getLangs();

    bool setFav(QString id);
    bool unsetFav(QString id);

    vector<BookRecord> search(BookRecord rec, QString priceFrom, QString priceTo, QString yearFrom, QString yearTo);

private:

    bool contains(vector<QString> langs, QString lang);
    vector<QString> getLangsFromRecs(vector<BookRecord> recs);


    QSqlDatabase m_db;
};
