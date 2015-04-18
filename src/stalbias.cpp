#include "stalbias.h"
#include "ui_stalbias.h"

StalBIAS::StalBIAS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StalBIAS)
{
    ui->setupUi(this);
    Debug = false;
    model = new QStandardItemModel(0,0);
    ui->mainToolBar->hide();
}

StalBIAS::~StalBIAS()
{
    delete ui;
}

void StalBIAS::on_actionLoad_CSV_triggered()
{
    model->clear();
    ui->tableView->setModel(model);
    QString fileName = QFileDialog::getOpenFileName (this, "Open CSV file",
                                                     QDir::currentPath(), "CSV (*.csv)");
    if(Debug)
        ui->textBrowser->append("Loading Data");
    bool First = true;
    QFile file (fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QString data = file.readAll();
        data.remove( QRegExp("\r") ); //remove all ocurrences of CR (Carriage Return)
        QString temp;
        QChar character;
        QTextStream textStream(&data);
        while (!textStream.atEnd()) {
            textStream >> character;
            if (character == ',') {
                checkString(temp, character);
            } else if (character == '\n') {
                checkString(temp, character, First);
                First = false;
            } else if (textStream.atEnd()) {
                temp.append(character);
                checkString(temp);
            } else {
                temp.append(character);
            }
        }
    }
    if(Debug)
        ui->textBrowser->append("Finished loading data");

    convert_to_customData();

}

void StalBIAS::convert_to_customData(){
    if(Debug)
        ui->textBrowser->append("Changing Data");

    QList<QStandardItem*> tempL;
    QStandardItem* temp;
    QDateTime tempdt;
    double tmpdbv, tmpdbe;


    newmodel = new QStandardItemModel(0,2);
    newmodel->setHorizontalHeaderItem(0,new QStandardItem("Date Time"));
    newmodel->setHorizontalHeaderItem(1,new QStandardItem("Drip Rate"));
    newmodel->setHorizontalHeaderItem(2,new QStandardItem("Film Thickness"));
    newmodel->setHorizontalHeaderItem(3,new QStandardItem("Temperature"));
    newmodel->setHorizontalHeaderItem(4,new QStandardItem("pC02"));
    newmodel->setHorizontalHeaderItem(5,new QStandardItem("cCa"));

    for (int i=0; i < model->rowCount(); i++) {
        tempL.clear();

        for(int j=0; j < model->columnCount(); j++){
            temp = new QStandardItem;
            temp = model->takeItem(i,j);
            switch(j){
            case 0:
                tempdt = QDateTime::fromString(temp->text(), "MM/dd/yyyy hh:mm:ss");
                Data.DateTimes.append(tempdt);
                tempL.append(new QStandardItem(tempdt.toString()));
                break;
            case 1:
                tmpdbv = temp->text().toDouble();
                Data.DripInt.append(tmpdbv);
                break;
            case 2:
                tmpdbe = temp->text().toDouble();
                Data.DripErr.append(tmpdbe);
                tempL.append(new QStandardItem(
                                 QString::number(tmpdbv)
                                 + " +/- "
                                 +QString::number(tmpdbe)
                                 ));
                tmpdbe = tmpdbv = 0;
                break;
            case 3:
                tmpdbv = temp->text().toDouble();
                Data.FilmThick.append(tmpdbv);
                break;
            case 4:
                tmpdbe = temp->text().toDouble();
                Data.FilmErr.append(tmpdbe);
                tempL.append(new QStandardItem(
                                 QString::number(tmpdbv)
                                 + " +/- "
                                 +QString::number(tmpdbe)
                                 ));
                tmpdbe = tmpdbv = 0;
                break;
            case 5:
                tmpdbv = temp->text().toDouble();
                Data.Temp.append(tmpdbv);
                break;
            case 6:
                tmpdbe = temp->text().toDouble();
                Data.TempErr.append(tmpdbe);
                tempL.append(new QStandardItem(
                                 QString::number(tmpdbv)
                                 + " +/- "
                                 +QString::number(tmpdbe)
                                 ));
                tmpdbe = tmpdbv = 0;
                break;
            case 7:
                tmpdbv = temp->text().toDouble();
                Data.pCO2.append(tmpdbv);
                break;
            case 8:
                tmpdbe = temp->text().toDouble();
                Data.pCO2Err.append(tmpdbe);
                tempL.append(new QStandardItem(
                                 QString::number(tmpdbv)
                                 + " +/- "
                                 +QString::number(tmpdbe)
                                 ));
                tmpdbe = tmpdbv = 0;
                break;
            case 9:
                tmpdbv = temp->text().toDouble();
                Data.cCa.append(tmpdbv);
                break;
            case 10:
                tmpdbe = temp->text().toDouble();
                Data.cCaErr.append(tmpdbe);
                tempL.append(new QStandardItem(
                                 QString::number(tmpdbv)
                                 + " +/- "
                                 +QString::number(tmpdbe)
                                 ));
                tmpdbe = tmpdbv = 0;
                break;
            }
            delete temp;
        }

        newmodel->appendRow(tempL);
    }
    ui->tableView->setModel(newmodel);
    ui->tableView->resizeColumnsToContents();

    if(Debug)
        ui->textBrowser->append("Finished changing data");
}

void StalBIAS::checkString(QString &temp, QChar character, bool First)
{
    if(temp.count("\"")%2 == 0) {
        //if (temp.size() == 0 && character != ',') //problem with line endings
        //    return;
        if (temp.startsWith( QChar('\"')) && temp.endsWith( QChar('\"') ) ) {
             temp.remove( QRegExp("^\"") );
             temp.remove( QRegExp("\"$") );
        }
        //FIXME: will possibly fail if there are 4 or more reapeating double quotes
        temp.replace("\"\"", "\"");
        QStandardItem *item = new QStandardItem(temp);
        standardItemList.append(item);
        if (character != QChar(',') && First){
            for (int i = 0; i < standardItemList.size(); i++){
                model->setHorizontalHeaderItem(i,standardItemList.at(i));
            }
            standardItemList.clear();
        }
        if (character != QChar(',') && !First) {
            model->appendRow(standardItemList);
            standardItemList.clear();
        }
        temp.clear();
    } else {
        temp.append(character);
    }
}



void StalBIAS::on_actionGraph_Viewer_triggered()
{
    GV.show();
}

void StalBIAS::on_actionCalculate_Growth_Rate_triggered()
{
    Result = CalcRes(Data);

    delete model;
    model = new QStandardItemModel(0,2);
    model->setHorizontalHeaderItem(0,new QStandardItem("Date Time"));
    model->setHorizontalHeaderItem(1,new QStandardItem("Drip Rate"));
    model->setHorizontalHeaderItem(2,new QStandardItem("Film Thickness"));
    model->setHorizontalHeaderItem(3,new QStandardItem("Temperature"));
    model->setHorizontalHeaderItem(4,new QStandardItem("pC02"));
    model->setHorizontalHeaderItem(5,new QStandardItem("cCa"));
    model->setHorizontalHeaderItem(6,new QStandardItem("Apparent cCa"));
    model->setHorizontalHeaderItem(7,new QStandardItem("Growth Rate"));

    for (int i=0 ;i < Data.lenght(); i++){
        QList<QStandardItem*> temp;
        temp = newmodel->takeRow(0);
        temp.append(new QStandardItem(
                        QString::number(Result.AppcCa.at(i))
                        + " +/- "
                        +QString::number(Result.AppcCaErr.at(i))
                        ));
        temp.append(new QStandardItem(
                        QString::number(Result.GrowthRate.at(i))
                        + " +/- "
                        +QString::number(Result.GrowthErr.at(i))
                        ));
        model->appendRow(temp);
    }

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

Results StalBIAS::CalcRes(DataItem data){
    if(Debug){
        ui->textBrowser->append(
                    QString::number(data.DateTimes.length())
                    +" "+
                    QString::number(data.DripInt.length())
                    +" "+
                    QString::number(data.DripErr.length())
                    +" "+
                    QString::number(data.FilmThick.length())
                    +" "+
                    QString::number(data.FilmErr.length())
                    +" "+
                    QString::number(data.Temp.length())
                    +" "+
                    QString::number(data.TempErr.length())
                    +" "+
                    QString::number(data.pCO2.length())
                    +" "+
                    QString::number(data.pCO2Err.length())
                    +" "+
                    QString::number(data.cCa.length())
                    +" "+
                    QString::number(data.cCaErr.length()));
    }

    Results temp;
    if(data.is_valid()){
        ui->textBrowser->append("WAS VALID");
        for (int i = 0; i < data.lenght(); i++){
            double appcCa, GrowthRate, alpha;
            appcCa = 0.5*((5.872*pow(data.pCO2.at(i),0.2526))+(-0.0167*data.Temp.at(i)+1.5146))*0.0000001;
            alpha = (-1*((0.52+0.04*data.Temp.at(i)+0.004*pow(data.Temp.at(i),2)*pow(10,-7))/data.FilmThick.at(i))*data.DripInt.at(i));
            GrowthRate = 1174*(data.cCa.at(i)-appcCa)*(data.FilmThick.at(i)/data.DripInt.at(i))
                    *(1-pow(enumber,alpha));
            temp.AppcCa.append(appcCa);
            temp.AppcCaErr.append(0);
            temp.GrowthRate.append(GrowthRate);
            temp.GrowthErr.append(0);
        }
    }
    return temp;
}

void StalBIAS::on_actionDebug_Mode_triggered()
{
    Debug = !Debug;
}
