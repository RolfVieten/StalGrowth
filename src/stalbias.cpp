#include "stalbias.h"
#include "ui_stalbias.h"

StalBIAS::StalBIAS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StalBIAS)
{
    ui->setupUi(this);
    Debug = false;
    model = new QStandardItemModel(0,0);
    newmodel = new QStandardItemModel(0,0);
    ui->mainToolBar->hide();
    ui->textBrowser->hide();
    this->setWindowTitle("StalGrowth");
    DProc = false;
}

StalBIAS::~StalBIAS()
{
    delete ui;
}

void StalBIAS::on_actionLoad_CSV_triggered()
{
    model->clear();

    DProc = false;
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
    Data.clear();

    newmodel->setHorizontalHeaderItem(0,new QStandardItem("Date Time"));
    newmodel->setHorizontalHeaderItem(1,new QStandardItem("Drip Interval (sec)"));
    newmodel->setHorizontalHeaderItem(2,new QStandardItem("Film Thickness (m)"));
    newmodel->setHorizontalHeaderItem(3,new QStandardItem("Temperature (C)"));
    newmodel->setHorizontalHeaderItem(4,new QStandardItem("pCO2 (atm)"));
    newmodel->setHorizontalHeaderItem(5,new QStandardItem("cCa (mol/m3)"));

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
    if(DProc) {
        GV = new GraphViewer;
        GV->setAttribute(Qt::WA_DeleteOnClose);
        GV->setresult(Data,Result);
        GV->show();
    }
}

void StalBIAS::on_actionCalculate_Growth_Rate_triggered()
{
    Result.clear();
    Result = CalcRes(Data);
    DProc = true;

    model->clear();
    model->setHorizontalHeaderItem(0,new QStandardItem("Date Time"));
    model->setHorizontalHeaderItem(1,new QStandardItem("Drip Interval (sec)"));
    model->setHorizontalHeaderItem(2,new QStandardItem("Film Thickness (m)"));
    model->setHorizontalHeaderItem(3,new QStandardItem("Temperature (C)"));
    model->setHorizontalHeaderItem(4,new QStandardItem("pCO2 (atm)"));
    model->setHorizontalHeaderItem(5,new QStandardItem("cCa (mol/m3)"));
    model->setHorizontalHeaderItem(6,new QStandardItem("Apparent cCa (mol/m3)"));
    model->setHorizontalHeaderItem(7,new QStandardItem("Growth Rate (m/yr)"));

    for (int i=0 ;i < Data.lenght(); i++){
        QList<QStandardItem*> temp;
        temp = newmodel->takeRow(0);
        temp.append(new QStandardItem(
                        QString::number(Result.AppcCa.at(i),'g',4)
                        + " +/- "
                        +QString::number(Result.AppcCaErr.at(i),'g',2)
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
            double appcCa, GrowthRate, exponent, alpha;
            double appcCaErr, Emin, Emax, erralpha;
            double exponentMax, exponentMin,GroErr;

            // Main Calculations
            appcCa = ((5.872*pow(data.pCO2.at(i),0.2526))
                      +((-0.0167*data.Temp.at(i))+1.5146))
                    *0.5;

            alpha = (0.52 + (0.04*data.Temp.at(i)) + (0.004*pow(data.Temp.at(i),2.0))) * pow(10.0,-7.0);           
            exponent = (-1.0 * (alpha/data.FilmThick.at(i)) * data.DripInt.at(i));
            GrowthRate = 1174*(data.cCa.at(i) - appcCa) * (data.FilmThick.at(i)/data.DripInt.at(i))
                    *(1.0 - exp(exponent));

            if (GrowthRate <= 0 ){
                GrowthRate = 0;
            }

            // Error Calculations.
            appcCaErr = ((0.2526*(data.pCO2Err.at(i)/data.pCO2.at(i))+(data.TempErr.at(i)/data.Temp.at(i))))*appcCa;
            erralpha = ((data.TempErr.at(i)/data.Temp.at(i))*3.0)*alpha;
            exponentMin = (-1.0 * ((alpha-erralpha)/(data.FilmThick.at(i)-data.FilmErr.at(i))) *
                          (data.DripInt.at(i)+data.DripErr.at(i)));
            exponentMax = (-1.0 * ((alpha+erralpha)/(data.FilmThick.at(i)+data.FilmErr.at(i))) *
                          (data.DripInt.at(i)-data.DripErr.at(i)));

            Emin=1174*((data.cCa.at(i) - data.cCaErr.at(i))-(appcCa+appcCaErr)) *
                    ((data.FilmThick.at(i)-data.FilmErr.at(i))/(data.DripInt.at(i)+data.DripErr.at(i))) *
                    (1.0 - exp(exponentMin));

            Emax=1174*((data.cCa.at(i) + data.cCaErr.at(i))-(appcCa-appcCaErr)) *
                    ((data.FilmThick.at(i)+data.FilmErr.at(i))/(data.DripInt.at(i)-data.DripErr.at(i))) *
                    (1.0 - exp(exponentMax));
            GroErr = Emax - ((Emax+Emin)/2);


            temp.AppcCa.append(appcCa);
            temp.AppcCaErr.append(appcCaErr);
            temp.GrowthRate.append(GrowthRate);
            temp.GrowthErr.append(GroErr);
        }
    }
    return temp;
}

void StalBIAS::on_actionDebug_Mode_triggered()
{
    Debug = !Debug;
    if(Debug){
        ui->textBrowser->hide();
    } else {
        ui->textBrowser->show();
    }
}

void StalBIAS::on_CalcGrap_clicked()
{
    if(!DProc){
        on_actionCalculate_Growth_Rate_triggered();
    }
    on_actionGraph_Viewer_triggered();
    GV->on_pushButton_clicked();
}

void StalBIAS::on_statistic_clicked()
{
    if(!DProc){
        on_actionCalculate_Growth_Rate_triggered();
    }
    PS = new PlotSelect;
    PS->setAttribute(Qt::WA_DeleteOnClose);
    PS->setresult(Data,Result);
    PS->show();
    PS->setGraph();
}

void StalBIAS::on_actionAbout_triggered()
{
    AB = new About;
    AB->show();
}
