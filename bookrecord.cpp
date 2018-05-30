#include "bookrecord.h"

BookRecord::BookRecord(){
    this->Title = "";
    this->Author="";
    this->Lang="";
    this->Price="";
    this->Year="";
    this->Fav="";
    this->Id="";
}

BookRecord::BookRecord(
        QString Id,
        QString Title,
        QString Author,
        QString Lang,
        QString Price,
        QString Year,
        QString Fav
      )
{
    this->Title = Title;
    this->Author= Author;
    this->Lang= Lang;
    this->Price= Price;
    this->Year= Year;
    this->Fav= Fav;
    this->Id= Id;

}

QString BookRecord::print(){

    QTextStream out;

    out << endl;
    out << "Printing book:" << endl;
    out << "Id: " << Id << endl;
    out << "Title: " << Title << endl;
    out << "Author: " << Author << endl;
    out << "Lang: " << Lang << endl;
    out << "Price: " << Price << endl;
    out << "Year: " << Year << endl;
    out << "Fav: " << Fav << endl;
    out << endl;

    return *out.string();

}
