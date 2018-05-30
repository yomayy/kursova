#include "debug.h"


void debugPrint(QString val){


    qDebug().noquote() << "[DEBUG] ---------------------------------";
    qDebug().noquote() << "";
    qDebug().noquote() << val;
    qDebug().noquote() << "";
    qDebug().noquote() << "-----------------------------------------";

}
