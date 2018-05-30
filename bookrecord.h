#pragma once

#include <QString>
#include <QDebug>
#include <iostream>
#include <sstream>


using namespace std;

class BookRecord
{
public:
    BookRecord(
            QString Id,
            QString Title,
            QString Author,
            QString Lang,
            QString Price,
            QString Year,
            QString Fav
            );

    BookRecord();

    QString Title;
    QString Author;
    QString Lang;
    QString Price;
    QString Year;
    QString Fav;
    QString Id;

    QString print();
};

