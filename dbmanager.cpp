#include "dbmanager.h"


bool DbManager::contains(vector<QString> langs, QString lang){
         for(int k=0; k<langs.size(); k++){
             if(lang == langs[k])
                 return true;
         }
         return false;
}

vector<QString> DbManager::getLangsFromRecs(vector<BookRecord> recs){
    vector<QString> langs;
    for(int i=0; i<recs.size(); i++){
        QString tmp = recs[i].Lang.toUpper();
        if(!contains(langs, tmp))
             langs.push_back(tmp);
    }

    return langs;
}


DbManager::DbManager(QString path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
        m_db.close();

}

vector<QString> DbManager::getLangs(){
    vector<QString> result;


    BookRecord tmp;
    vector<BookRecord> recs = search(tmp, "0", "10000", "0", "10000");

    result = getLangsFromRecs(recs);

    return result;

}


bool DbManager::isOpen()
{
    return m_db.isOpen();
}


bool DbManager::add(BookRecord rec)
 {
    bool result = false;
    QString txterr;
    QTextStream err(&txterr);
    QSqlQuery query;

        query.prepare("INSERT INTO kursovaya (Title, Author, Lang, Price, Year, FAV) VALUES (:title, :author, :lang, :price, :year, 0)");
        query.bindValue(":title", rec.Title);
        query.bindValue(":author", rec.Author);
        query.bindValue(":lang", rec.Lang);
        query.bindValue(":price", rec.Price);
        query.bindValue(":year", rec.Year);

        result = query.exec();

        if(!result)
        {
            err << "Add book failed: " << endl;
            err << query.lastError().text() << endl;
            err << rec.print() << endl;
            err.flush();
            debugPrint(txterr);
        }


    return result;
}

bool DbManager::remove(QString id)
{
    bool result = false;
    QString txterr;
    QTextStream err(&txterr);
    QSqlQuery query;


    if (exist(id))
    {
        query.prepare("DELETE FROM kursovaya WHERE ID = (:ID)");
        query.bindValue(":ID", id);

        result = query.exec();
        if(!result)
        {
            err << "Remove book failed: " << endl;
            err << query.lastError().text() << endl;
            err << "ID: " << id << endl;
            err.flush();
            debugPrint(txterr);
        }
    }
    else
    {
        err << "Remove book failed: " << endl;
        err << query.lastError().text() << endl;
        err << "No such book" << endl;
        err << "ID: " << id << endl;
        err.flush();
        debugPrint(txterr);
    }

    return result;
}


bool DbManager::exist(QString id)
{
    bool result = false;
    QString txterr;
    QTextStream err(&txterr);
    QSqlQuery query;

    query.prepare("SELECT ID FROM kursovaya WHERE ID = (:ID)");
    query.bindValue(":ID", id);

    if (query.exec()){

        if (query.next())
            result = true;
        else
            result = false;

    }else{

        err << "Exist book failed: " << endl;
        err << query.lastError().text() << endl;
        err << "ID: " << id << endl;
        err.flush();
        debugPrint(txterr);

    }

    return result;
}


vector<BookRecord> DbManager::search(BookRecord rec, QString priceFrom, QString priceTo, QString yearFrom, QString yearTo){

    vector<BookRecord> recs;

    bool result;
    //QString txterr;
    //QTextStream err(&txterr);

    QSqlQuery query;


    rec.Author = "%" + rec.Author + "%";
    rec.Title = "%" + rec.Title+ "%";
    rec.Lang = "%" + rec.Lang + "%";
    rec.Fav = "%" + rec.Fav + "%";

    query.prepare("SELECT * FROM kursovaya WHERE Title LIKE :title AND Author LIKE :author AND Lang LIKE :lang AND (Price BETWEEN :priceFrom AND :priceTo) AND (Year BETWEEN :yearFrom AND :yearTo) AND Fav LIKE :fav");
     query.bindValue(":title", rec.Title);
    query.bindValue(":author", rec.Author);
    query.bindValue(":lang", rec.Lang);
    query.bindValue(":priceFrom", priceFrom);
    query.bindValue(":priceTo", priceTo);
    query.bindValue(":yearFrom", yearFrom);
    query.bindValue(":yearTo", yearTo);
    query.bindValue(":fav", rec.Fav);


    result = query.exec();

    debugPrint(query.executedQuery());
    /*
    if(!result)
    {
        err << "Search book failed: " << endl;
        err << query.lastError().text() << endl;
        err << "Search criterias are: " << endl;
        err << rec.print() << endl;
        err.flush();
        debugPrint(txterr);
    }
*/

        while(query.next()){
            QString id = query.value(0).toString();
            QString title = query.value(1).toString();
            QString author = query.value(2).toString();
            QString lang = query.value(3).toString();
            QString price = query.value(4).toString();
            QString year = query.value(5).toString();
            QString fav = query.value(6).toString();

            BookRecord rec(id, title, author, lang, price, year, fav);
            recs.push_back(rec);
        }


    return recs;
}

bool DbManager::setFav(QString id){

    bool result;
    QString txterr;
    QTextStream err(&txterr);
    QSqlQuery query;

    if (exist(id)){
        query.prepare("UPDATE kursovaya SET FAV = 1 WHERE ID = :ID");
        query.bindValue(":ID", id);

        result = query.exec();

        if(!result){
            err << "setFav book failed: " << endl;
            err << query.lastError().text() << endl;
            err << "ID: " << id;
            err.flush();
            debugPrint(txterr);
        }

    }else{

        err << "setFav book failed: " << endl;
        err << query.lastError().text() << endl;
        err << "No such book" << endl;
        err << "ID: " << id << endl;
        err.flush();
        debugPrint(txterr);
    }

   return result;
}

bool DbManager::unsetFav(QString id){

    bool result;
    QString txterr;
    QTextStream err(&txterr);
    QSqlQuery query;

    if (exist(id)){
        query.prepare("UPDATE kursovaya SET FAV = 0 WHERE ID = :ID");
        query.bindValue(":ID", id);

        result = query.exec();

        if(!result){
            err << "unsetFav book failed: " << endl;
            err << query.lastError().text() << endl;
            err << "ID: " << id;
            err.flush();
            debugPrint(txterr);
        }

    }else{

        err << "setFav book failed: " << endl;
        err << query.lastError().text() << endl;
        err << "No such book" << endl;
        err << "ID: " << id << endl;
        err.flush();
        debugPrint(txterr);
    }

    return result;
}


