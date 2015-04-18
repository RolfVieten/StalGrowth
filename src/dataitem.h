#ifndef DATAITEM_H
#define DATAITEM_H

#include <QDateTime>
#include <QList>

struct Results{
    QList<double>         GrowthRate;
    QList<double>         GrowthErr;
    QList<double>         AppcCa;
    QList<double>         AppcCaErr;
};

class DataItem{
public:
    DataItem();
    ~DataItem();
    QList<QDateTime>      DateTimes;
    QList<double>         DripInt;
    QList<double>         DripErr;
    QList<double>         FilmThick;
    QList<double>         FilmErr;
    QList<double>         Temp;
    QList<double>         TempErr;
    QList<double>         pCO2;
    QList<double>         pCO2Err;
    QList<double>         cCa;
    QList<double>         cCaErr;
    bool is_valid();
    int lenght();
};

#endif // DATAITEM_H
