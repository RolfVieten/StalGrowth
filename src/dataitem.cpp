#include "dataitem.h"

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

