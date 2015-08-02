#include "dataitem.h"

Results::Results(){
}

Results::~Results(){
}

void Results::clear(){
    GrowthRate.clear();
    GrowthErr.clear();
    AppcCa.clear();
    AppcCaErr.clear();
}

DataItem::DataItem()
{
}

DataItem::~DataItem()
{
}

bool DataItem::is_valid(){
    if( (DripInt.length() == DripErr.length())
            && (FilmThick.length() == FilmErr.length())
            && (Temp.length() == TempErr.length())
            && (pCO2.length() == pCO2Err.length())
            && (cCa.length() == cCaErr.length()))
        return true;
    else
        return false;
}

int DataItem::lenght(){
    if(is_valid())
        return DateTimes.length();
    else
        return 0;
}

void DataItem::clear(){
    DateTimes.clear();
    DripInt.clear();
    DripErr.clear();
    FilmThick.clear();
    FilmErr.clear();
    Temp.clear();
    TempErr.clear();
    pCO2.clear();
    pCO2Err.clear();
    cCa.clear();
    cCaErr.clear();
}

Avg::Avg(){
    dated =0;
}

void Avg::calc(){
    double sum, xvar;
    for(int i = 0; i < data.size(); i++){
        sum += data.at(i);
    }
    mean = sum/data.size();

    for(int i = 0; i < data.size(); i++){
        xvar += pow((data.at(i)- mean), 2);
    }
    variance = xvar/(data.size()-1);
    sd = pow(variance,2);
}

void Avg::setdate(time_t start, time_t end){
    time_t tdate;
    tdate = (start + end) / 2;
    date.fromTime_t(tdate);
    dated = tdate;
}
