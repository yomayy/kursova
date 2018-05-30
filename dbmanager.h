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

    bool setFav(QString id);
    bool unsetFav(QString id);

    vector<BookRecord> search(BookRecord rec);

private:
    QSqlDatabase m_db;
};
