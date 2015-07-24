#include "plotselect.h"
#include "ui_plotselect.h"

PlotSelect::PlotSelect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotSelect)
{
    ui->setupUi(this);
    this->setWindowTitle("Statistics & Biasing");
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
    graph->setLineStyle(QCPGraph::lsLine);
    graph->setPen(QPen(QColor(Qt::black)));
    graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    FGoverlay->setLineStyle(QCPGraph::lsNone);
    FGoverlay->setPen(QPen(QColor(Qt::blue)));
    FGoverlay->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar, 8));
    SGoverlay->setLineStyle(QCPGraph::lsNone);
    SGoverlay->setPen(QPen(QColor(Qt::red)));
    SGoverlay->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar, 8));

    // configure bottom axis to show date and time instead of number:
    ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Graph->xAxis->setDateTimeFormat("MMMM\nyyyy");
    ui->Graph->xAxis->setLabel("Date");

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
    labels.append("Growth(cm/yr)");

    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->resizeColumnsToContents();
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
        temp =new QLabel(QString::number(Result.GrowthRate.at(i)));
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
            sumFG =+ Result.GrowthRate.at(i);
            countFG++;
        }
        if(SG.at(i)->isChecked()){
            sumSG =+ Result.GrowthRate.at(i);
            countSG++;
        }
    }

    meanFG =sumFG/countFG;
    meanSG =sumSG/countSG;

    double sqFG = 0, sqSG = 0;
    double varFG = 0, varSG = 0;

    for(int i=0; i < Time.size(); i++){
        if(FG.at(i)->isChecked()){
            sqFG =+ pow((Result.GrowthRate.at(i)-meanFG), 2);
        }
        if(SG.at(i)->isChecked()){
            sqSG =+ pow((Result.GrowthRate.at(i)-meanSG), 2);
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

    double p = Student_t_Density(t_stat, v);


    ui->textBrowser->append("   __________________________________________________\n");
    ui->textBrowser->append("   Student t test for two samples (unequal variances)");
    ui->textBrowser->append("   __________________________________________________\n");
    ui->textBrowser->append("   Number of Observations (Fast Growth)\t= "+QString::number(countFG));
    ui->textBrowser->append("   Fast Growth Mean\t\t\t= "+QString::number(meanFG));
    ui->textBrowser->append("   Fast Growth Standard Deviation\t\t= "+QString::number(sqrt(varFG)));
    ui->textBrowser->append("   Number of Observations (Slow Growth)\t= "+QString::number(countSG));
    ui->textBrowser->append("   Slow Growth Mean\t\t\t= "+QString::number(meanSG));
    ui->textBrowser->append("   Slow Growth Standard Deviation\t\t= "+QString::number(sqrt(varSG)));
    ui->textBrowser->append("   Degrees of freedom\t\t\t= "+QString::number(v));
    ui->textBrowser->append("   Pooled Standard Deviation\t\t= "+QString::number(sp));
    ui->textBrowser->append("   T Statistic\t\t\t\t= "+QString::number(t_stat)+"\n");
    ui->textBrowser->append("   Probability that difference is due to chance\t= "+QString::number(p)+"\n");

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
