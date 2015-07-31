#ifndef DATAITEM_H
#define DATAITEM_H

#include <QDateTime>
#include <QList>
#include <cmath>

class Results{
public:
    Results();
    ~Results();
    QList<double>         GrowthRate;
    QList<double>         GrowthErr;
    QList<double>         AppcCa;
    QList<double>         AppcCaErr;
    void clear();
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
    void clear();
};

class Avg{
public:
    Avg();
    double mean;
    double variance;
    double sd;
    bool growth;
    QDateTime date;
    double dated;
    QList<double> data;
    void calc();
    void setdate(time_t start, time_t end);
};

#endif // DATAITEM_H
