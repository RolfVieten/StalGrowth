#include "plotselect.h"
#include "ui_plotselect.h"

PlotSelect::PlotSelect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotSelect)
{
    ui->setupUi(this);
    this->setWindowTitle("Statistics & Biasing");
    cs = new CustomSeason(this);
    ui->Graph->addLayer("boxes",ui->Graph->layer("grid"),QCustomPlot::limBelow);
    Savg = Favg = 0;
    csran = false;
}

PlotSelect::~PlotSelect()
{
    delete ui;
}

void PlotSelect::setresult(const DataItem data, const Results result){
    Data = data;
    Result = result;
    for (int i = 0; i < Data.DateTimes.length();i++){
        double temp;
        temp = Data.DateTimes.at(i).toTime_t();
        Time.append(temp);
        temp = Result.GrowthRate.at(i) * 100;
        Growthincm.append(temp);
    }
}

void PlotSelect::setGraph(){
    graph = ui->Graph->addGraph();
    FGoverlay = ui->Graph->addGraph();
    SGoverlay = ui->Graph->addGraph();
    mainGraph42 = ui->Graph->addGraph();
    graph->setLineStyle(QCPGraph::lsLine);
    graph->setPen(QPen(QColor(Qt::black)));
    graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    FGoverlay->setLineStyle(QCPGraph::lsNone);
    FGoverlay->setPen(QPen(QColor(Qt::blue)));
    FGoverlay->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar, 8));
    SGoverlay->setLineStyle(QCPGraph::lsNone);
    SGoverlay->setPen(QPen(QColor(Qt::red)));
    SGoverlay->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar, 8));
    mainGraph42->setLineStyle(QCPGraph::lsLine);
    mainGraph42->setPen(QPen(QColor(Qt::black)));
    mainGraph42->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare, 6));

    // configure bottom axis to show date and time instead of number:
    ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Graph->xAxis->setDateTimeFormat("MMMM\nyyyy");
    mainX = ui->Graph->xAxis;
    ui->Graph->xAxis->setLabel("Date");
    ui->Graph->yAxis->setLabel("Growth Rate (m/yr)");

    // add data
    graph->setDataValueError(Time.toVector(),Result.GrowthRate.toVector(),Result.GrowthErr.toVector(),Result.GrowthErr.toVector());
    graph->setErrorType(QCPGraph::etValue);
    graph->setErrorPen(QPen(Qt::black));
    ui->Graph->rescaleAxes();
    ui->Graph->replot();

    //Setup table
    QStringList labels;
    labels.append("FG");
    labels.append("SG");
    labels.append("Date");
    labels.append("Growth(m/yr)");

    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->resizeColumnsToContents();
    //ui->textBrowser->append(QString::number(ui->tableWidget->childrenRect().width()));
    FG.clear();
    SG.clear();

    for(int i= 0; i < Time.size(); i++){
        //QCheckBox *FGb, *SGb;
        //FGb = new QCheckBox();
        //SGb = new QCheckBox();
        mycheck *FGb, *SGb;
        FGb = new mycheck(i);
        SGb = new mycheck(i);
        ui->tableWidget->insertRow(i);
        QLabel *temp, *date;
        temp =new QLabel(QString::number(Result.GrowthRate.at(i),'f', 7));
        temp->setAlignment(Qt::AlignHCenter);
        date =new QLabel(Data.DateTimes.at(i).toString("yyyy/MM/dd"));
        date->setAlignment(Qt::AlignHCenter);
        ui->tableWidget->setCellWidget(i,0, FGb);
        ui->tableWidget->setCellWidget(i,1, SGb);
        ui->tableWidget->setCellWidget(i,2, date);
        ui->tableWidget->setCellWidget(i,3, temp);
        FG.append(FGb);
        SG.append(SGb);
        connect(FGb,SIGNAL(toggled(bool,int)),this,SLOT(fgclicked(bool,int)));
        connect(SGb,SIGNAL(toggled(bool,int)),this,SLOT(sgclicked(bool,int)));
    }

    ui->tableWidget->resizeColumnsToContents();
    /*QSize temp;
    temp.setWidth(ui->tableWidget->childrenRect().width());
    temp.setHeight(ui->tableWidget->height());
    ui->tableWidget->resize(temp);*/

}

void PlotSelect::fgclicked(bool clicked, int row){
    if(clicked){
        if(SG.at(row)->isChecked()){
            SG.at(row)->setChecked(false);
            SGoverlay->removeData(Time.at(row));
            ui->Graph->replot();
        }
        FGoverlay->addData(Time.at(row),Result.GrowthRate.at(row));
        ui->Graph->replot();
    }
    if(!clicked){
        FGoverlay->removeData(Time.at(row));
        ui->Graph->replot();
    }
}

void PlotSelect::sgclicked(bool clicked, int row){
    if(clicked){
        if(FG.at(row)->isChecked()){
            FG.at(row)->setChecked(false);
            FGoverlay->removeData(Time.at(row));
            ui->Graph->replot();
        }
        SGoverlay->addData(Time.at(row),Result.GrowthRate.at(row));
        ui->Graph->replot();
    }
    if(!clicked){
        SGoverlay->removeData(Time.at(row));
        ui->Graph->replot();
    }
}

void PlotSelect::seasonality_test(){
    double sumFG = 0 , sumSG = 0;
    double meanFG = 0, meanSG = 0 ;
    int countFG =0 , countSG = 0;

    for(int i=0; i < Time.size(); i++){
        if(FG.at(i)->isChecked()){
            sumFG += Result.GrowthRate.at(i);
            countFG++;
        }
        if(SG.at(i)->isChecked()){
            sumSG += Result.GrowthRate.at(i);
            countSG++;
        }
    }

    meanFG =sumFG/countFG;
    meanSG =sumSG/countSG;

    double sqFG = 0, sqSG = 0;
    double varFG = 0, varSG = 0;

    for(int i=0; i < Time.size(); i++){
        if(FG.at(i)->isChecked()){
            sqFG += pow((Result.GrowthRate.at(i)-meanFG), 2);
        }
        if(SG.at(i)->isChecked()){
            sqSG += pow((Result.GrowthRate.at(i)-meanSG), 2);
        }
    }

    varFG = sqFG/(countFG -1);
    varSG = sqSG/(countSG -1);

    // Degrees of freedom:
    double v = countFG + countSG - 2;

    // Pooled variance:
    double sp = sqrt(((countFG-1) * varFG + (countSG-1) * varSG) / v);

    // t-statistic:
    double t_stat = (meanFG - meanSG) / (sp * sqrt(1.0 / countFG + 1.0 / countSG));

    // p (probabitily)
    double p = alglib::studenttdistribution(v, -1*t_stat);

    double z95 = alglib::invstudenttdistribution(v, 0.95);
    double z99 = alglib::invstudenttdistribution(v, 0.99);

    #ifdef __linux__
    ui->textBrowser->append("   __________________________________________________\n");
    ui->textBrowser->append("   Student t test for two samples (unequal variances)");
    ui->textBrowser->append("   __________________________________________________\n");
    ui->textBrowser->append("   Number of Observations (Fast Growth)\t= "+QString::number(countFG));
    ui->textBrowser->append("   Fast Growth Mean (m/yr)\t\t= "+QString::number(meanFG,'f', 7));
    ui->textBrowser->append("   Fast Growth Standard Deviation\t\t= "+QString::number(sqrt(varFG),'e', 3));
    ui->textBrowser->append("   Number of Observations (Slow Growth)\t= "+QString::number(countSG));
    ui->textBrowser->append("   Slow Growth Mean (m/yr)\t\t= "+QString::number(meanSG,'f', 7));
    ui->textBrowser->append("   Slow Growth Standard Deviation\t\t= "+QString::number(sqrt(varSG),'e', 3));
    ui->textBrowser->append("   Degrees of freedom\t\t\t= "+QString::number(v));
    ui->textBrowser->append("   Pooled Standard Deviation\t\t= "+QString::number(sp,'e',3));
    ui->textBrowser->append("   T Statistic\t\t\t\t= "+QString::number(t_stat));
    ui->textBrowser->append("   Z (95%,"+QString::number(v)+") Statistic\t\t\t= "+QString::number(z95));
    ui->textBrowser->append("   Z (99%,"+QString::number(v)+") Statistic\t\t\t= "+QString::number(z99)+"\n");
    ui->textBrowser->append("   Probability means are the same (p-value)\t= "+QString::number(p)+"\n");
    #elif _WIN32
    ui->textBrowser->append("   __________________________________________________\n");
    ui->textBrowser->append("   Student t test for two samples (unequal variances)");
    ui->textBrowser->append("   __________________________________________________\n");
    ui->textBrowser->append("   Number of Observations (Fast Growth)\t= "+QString::number(countFG));
    ui->textBrowser->append("   Fast Growth Mean (m/yr)\t\t= "+QString::number(meanFG,'f', 7));
    ui->textBrowser->append("   Fast Growth Standard Deviation\t= "+QString::number(sqrt(varFG),'e', 3));
    ui->textBrowser->append("   Number of Observations (Slow Growth)\t= "+QString::number(countSG));
    ui->textBrowser->append("   Slow Growth Mean (m/yr)\t\t= "+QString::number(meanSG,'f', 7));
    ui->textBrowser->append("   Slow Growth Standard Deviation\t="+QString::number(sqrt(varSG),'e', 3));
    ui->textBrowser->append("   Degrees of freedom\t\t= "+QString::number(v));
    ui->textBrowser->append("   Pooled Standard Deviation\t\t= "+QString::number(sp,'e',3));
    ui->textBrowser->append("   T Statistic\t\t\t= "+QString::number(t_stat));
    ui->textBrowser->append("   Z (95%,"+QString::number(v)+") Statistic\t\t= "+QString::number(z95));
    ui->textBrowser->append("   Z (99%,"+QString::number(v)+") Statistic\t\t= "+QString::number(z99)+"\n");
    ui->textBrowser->append("   Probability means are the same (p-value)\t= "+QString::number(p)+"\n");
    #else
    #endif

    Favg = meanFG;
    Savg = meanSG;

}

mycheck::mycheck(int rown, QWidget *parent) : QCheckBox(parent){
    row = rown;
    connect(this,SIGNAL(toggled(bool)),this,SLOT(togcustom(bool)));
}

void mycheck::togcustom(bool checked){
    emit toggled(checked, row);
}

void PlotSelect::on_pushButton_clicked()
{
    seasonality_test();
}

void PlotSelect::on_customSeason_clicked() {
    cs = new CustomSeason;
    cs->setAttribute(Qt::WA_DeleteOnClose);
    cs->show();
    connect(cs,SIGNAL(accepted()),this,SLOT(season_accepted()));
}

void PlotSelect::season_accepted(){

    // Set Start/End
    start = cs->start;
    end = cs->end;
    csran = true;

    // Set AxisRect
    QCPAxisRect *wideAxisRect;
    wideAxisRect = ui->Graph->axisRect();

    // Clear old variables
    LAvg.clear();
    mainGraph42->clearData();

    // Get the range
    QCPRange xrange;
    xrange = mainX->range();

    QDateTime low, high, startd, endd, endf;
    low.setTime_t(xrange.lower);
    high.setTime_t(xrange.upper);

    // Debug info
    //ui->textBrowser->append(start.toString("MMM/dd"));
    //ui->textBrowser->append(end.toString("MMM/dd"));
    //ui->textBrowser->append(low.toString("MMM/dd"));
    //ui->textBrowser->append(high.toString("MMM/dd"));

    // Start the loop
    QCPItemRect *newrect;
    for(int i = low.date().year(); i < high.date().year() + 2; i++){
        // Set Date
        startd.setDate(QDate(i,start.month(),start.day()));
        endd.setDate(QDate(i,end.month(),end.day()));

        // Start Rectangle
        newrect = new QCPItemRect(ui->Graph);

        if(startd <= low){

            newrect->setClipAxisRect(wideAxisRect);
            newrect->setClipToAxisRect(true);
            newrect->setBrush(QBrush(QColor(Qt::yellow)));
            newrect->topLeft->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
            newrect->topLeft->setCoords(low.toTime_t(),100);


            // End Rectangle
            if (endd <= high) {
                newrect->bottomRight->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
                newrect->bottomRight->setCoords(endd.toTime_t(),-100);
                newrect->setLayer("boxes");
            } else {
                newrect->bottomRight->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
                newrect->bottomRight->setCoords(high.toTime_t(),-100);
                newrect->setLayer("boxes");
            }
        } else {

            newrect->setClipAxisRect(wideAxisRect);
            newrect->setClipToAxisRect(true);
            newrect->setBrush(QBrush(QColor(Qt::yellow)));
            newrect->topLeft->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
            newrect->topLeft->setCoords(startd.toTime_t(),100);

            // End Rectangle
            if (endd <= high) {
                newrect->bottomRight->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
                newrect->bottomRight->setCoords(endd.toTime_t(),-100);
                newrect->setLayer("boxes");

            } else {
                newrect->bottomRight->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
                newrect->bottomRight->setCoords(high.toTime_t(),-100);
                newrect->setLayer("boxes");

            }
        }

    }

    // Average
    QList<TBox> split; // Split Boxes
    bool first = true;

    // Same code as above sets where to split the data
    for(int i = low.date().year(); i < high.date().year() + 2; i++){
        // Set Date
        startd.setDate(QDate(i,start.month(),start.day()));
        endd.setDate(QDate(i,end.month(),end.day()));
        endf.setDate(QDate(i+1,start.month(),start.day()));

        if(startd <= low){
            TBox temp;
            temp.Slow = true;
            temp.Begin = low;
            first = false;

            if (endd <= high){
                temp.End = endd;
                split.append(temp);
            }
            else{
                temp.End = high;
                split.append(temp);
            }

        } else {
            TBox temp;
            if (first) {
                TBox tempf;
                tempf.Begin = low;
                tempf.End = startd;
                tempf.Slow = false;
                split.append(tempf);
                first = false;
            }

            temp.Slow = true;
            temp.Begin = startd;

            if (endd <= high) {
                temp.End = endd;
                split.append(temp);
            }
            else {
                temp.End = high;
                split.append(temp);
            }
        }

        if(endd <= low){
            TBox temp;
            temp.Slow = false;
            temp.Begin = low;

            if (endf <= high) {
                temp.End = endf;
                split.append(temp);
            }
            else {
                temp.End = high;
                split.append(temp);
            }

        } else {
            TBox temp;
            temp.Slow = false;
            temp.Begin = endd;

            if (endf <= high) {
                temp.End = endf;
                split.append(temp);
            }
            else {
                temp.End = high;
                split.append(temp);
            }
        }

    }

    // Determines the Averages
    for(int i = 0; i < split.size(); i++){
        Avg temp;

        temp.setdate(split.at(i).Begin,split.at(i).End);
        temp.slow = split.at(i).Slow;
        for(int l = 0; l < Result.GrowthRate.size(); l++){
            if( Data.DateTimes.at(l) >= split.at(i).Begin && Data.DateTimes.at(l) <= split.at(i).End){
                temp.data.append(Result.GrowthRate.at(l));
                if(split.at(i).Slow){
                    SG.at(l)->click();
                } else {
                    FG.at(l)->click();
                }
            }
        }
        temp.calc();
        LAvg.append(temp);
    }

    // Add Points
    mainGraph42->setLineStyle(QCPGraph::lsNone);
    mainGraph42->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare,QColor(Qt::black),QColor(Qt::black), 8));

    for(int i = 0; i < LAvg.size(); i++){
        mainGraph42->addData(LAvg.at(i).dated,LAvg.at(i).mean);
    }

    // Show Averages
    sa = new ShowAvg;
    sa->setAvg(LAvg);
    sa->setAttribute(Qt::WA_DeleteOnClose);
    sa->show();

    // END Average
    on_pushButton_clicked();

    ui->Graph->replot();
}

void PlotSelect::on_Sbias_button_clicked() {

    if (csran){
        qint64 between = 0;
        qint64 remaining = 0;

        between = start.daysTo(end);
        remaining = 365 - between;
        double fastgt, slowgt, total;
        fastgt = Favg*(1.0/365.0)*(double)remaining;
        slowgt = Savg*(1.0/365.0)*(double)between;
        total = fastgt + slowgt;
        int percentF, percentS;
        percentF = (fastgt/total)*100;
        percentS = (slowgt/total)*100;

        /* Debug info
    ui->textBrowser->append(start.toString("MMM/dd"));
    ui->textBrowser->append(end.toString("MMM/dd"));
    ui->textBrowser->append(QString::number(Savg));
    ui->textBrowser->append(QString::number(Favg));
    ui->textBrowser->append(QString::number(between));
    ui->textBrowser->append(QString::number(remaining));
    */
        if (slowgt >= 0)
        {
            ui->textBrowser->append("   __________________________________________________\n");
            ui->textBrowser->append("   Bias for current T-test Selection                   ");
            ui->textBrowser->append("   Seasons                                             ");
            ui->textBrowser->append("   FG:  "+end.toString("MMM/dd")+"  -  "+start.toString("MMM/dd")+
                                    "  "+QString::number(remaining)+" days");
            ui->textBrowser->append("   SG:  "+start.toString("MMM/dd")+"  -  "+end.toString("MMM/dd")+
                                    "  "+QString::number(between)+" days");
            ui->textBrowser->append("   __________________________________________________\n");
            ui->textBrowser->append("Growth rate in m/yr for the Fast Growth\t= "+
                                    QString::number(Favg,'f', 7));
            ui->textBrowser->append("Growth in m over the Fast Growth Season\t= "+
                                    QString::number(fastgt,'f', 7));
            ui->textBrowser->append("Growth rate in m/yr for the Slow Growth\t= "+
                                    QString::number(Savg,'f', 7));
            ui->textBrowser->append("Growth in m over the Slow Growth Season:\t= "+
                                    QString::number(slowgt,'f', 7));
            ui->textBrowser->append("Total growth over the year: \t\t= "+
                                    QString::number(total,'f', 7));
            ui->textBrowser->append("Percent Growth over Fast Growth Season\t= "+
                                    QString::number(percentF)+"%");
            ui->textBrowser->append("Percent Growth over Slow Growth Season\t= "+
                                    QString::number(percentS)+"%");
        } else {
            ui->textBrowser->append("   __________________________________________________\n");
            ui->textBrowser->append("   Bias for current T-test Selection                   ");
            ui->textBrowser->append("   Seasons                                             ");
            ui->textBrowser->append("   FG:  "+end.toString("MMM/dd")+"  -  "+start.toString("MMM/dd")+
                                    "  "+QString::number(remaining)+" days");
            ui->textBrowser->append("   SG:  "+start.toString("MMM/dd")+"  -  "+end.toString("MMM/dd")+
                                    "  "+QString::number(between)+" days");
            ui->textBrowser->append("   __________________________________________________\n");
            ui->textBrowser->append("Growth rate in m/yr for the Fast Growth\t= "+
                                    QString::number(Favg,'f', 7));
            ui->textBrowser->append("Growth in m over the Fast Growth Season\t= "+
                                    QString::number(fastgt,'f', 7));
            ui->textBrowser->append("Growth rate in m/yr for the Slow Growth\t= "+
                                    QString::number(Savg,'f', 7));
            ui->textBrowser->append("Dissolved in m over the Slow Growth Season:\t= "+
                                    QString::number(slowgt,'f', 7));
            ui->textBrowser->append("Total growth over the year: \t\t= "+
                                    QString::number(total,'f', 7));
            ui->textBrowser->append("Percent Growth over Fast Growth Season\t= "+
                                    QString::number(percentF+percentS)+"%");
            ui->textBrowser->append("Percent Dissoved over Slow Growth Season\t= "+
                                    QString::number(-1*percentS)+"%");
        }
    } else {

        ui->textBrowser->append("Please run Auto Season first");
    }

}
