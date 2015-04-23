#include "graphviewer.h"
#include "ui_graphviewer.h"

GraphViewer::GraphViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphViewer)
{
    ui->setupUi(this);
    ui->Graph->clearGraphs();
}

GraphViewer::~GraphViewer()
{
    delete ui;
}

void GraphViewer::setresult(DataItem data, Results result){
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

void GraphViewer::setGraph(){
    ui->Graph->plotLayout()->clear();
    // Input
    QCPAxisRect *wideAxisRect = new QCPAxisRect(ui->Graph);
    wideAxisRect->setupFullAxesBox(true);
    wideAxisRect->addAxis(QCPAxis::atLeft)->setTickLabelColor(Qt::red); // add an extra axis on the left and color its numbers
    wideAxisRect->addAxis(QCPAxis::atLeft)->setTickLabelColor(Qt::green); // add an extra axis on the left and color its numbers
    wideAxisRect->axis(QCPAxis::atLeft,0)->setLabel("Temperature (C)");
    wideAxisRect->axis(QCPAxis::atLeft,1)->setLabel("CO2 (atm)");
    wideAxisRect->axis(QCPAxis::atLeft,2)->setLabel("cCa (mol/m3)");
    wideAxisRect->axis(QCPAxis::atBottom)->setTickLabelType(QCPAxis::ltDateTime);
    wideAxisRect->axis(QCPAxis::atBottom)->setDateTimeFormat("MMMM\nyyyy");
    wideAxisRect->axis(QCPAxis::atBottom)->setLabel("Date");

    // Output
    QCPAxisRect *wideAxisRect1 = new QCPAxisRect(ui->Graph);
    wideAxisRect1->addAxis(QCPAxis::atLeft)->setTickLabelColor(Qt::red); // add an extra axis on the left and color its numbers
    wideAxisRect1->axis(QCPAxis::atLeft,0)->setLabel("Growth Rate (cm/yr)");
    wideAxisRect1->axis(QCPAxis::atLeft,1)->setLabel("Ca (Red Apparent; Green Real)(mol/m3)");
    wideAxisRect1->axis(QCPAxis::atBottom)->setTickLabelType(QCPAxis::ltDateTime);
    wideAxisRect1->axis(QCPAxis::atBottom)->setDateTimeFormat("MMMM\nyyyy");

    // Sync Margins
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->Graph);
    wideAxisRect->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
    wideAxisRect1->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);

    // Add to the Plot
    ui->Graph->plotLayout()->addElement(0,0,wideAxisRect);
    ui->Graph->plotLayout()->addElement(1,0,wideAxisRect1);

    // Main Graph1
    //Temp
    QCPGraph *mainGraph1 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
    mainGraph1->setPen(QPen(Qt::black));
    mainGraph1->setLineStyle(QCPGraph::lsLine);
    //mainGraph1->setData(Time.toVector(), Data.Temp.toVector());
    mainGraph1->setDataValueError(Time.toVector(),Data.Temp.toVector(),Data.TempErr.toVector(),Data.TempErr.toVector());
    mainGraph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 4));
    mainGraph1->setErrorType(QCPGraph::etValue);
    mainGraph1->setErrorPen(QPen(Qt::black));
    mainGraph1->rescaleAxes();

    // pCO2
    QCPGraph *mainGraph2 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft, 1));
    mainGraph2->setPen(QPen(Qt::red));
    mainGraph2->setLineStyle(QCPGraph::lsLine);
    //mainGraph2->setData(Time.toVector(),Data.pCO2.toVector());
    mainGraph2->setDataValueError(Time.toVector(),Data.pCO2.toVector(),Data.pCO2Err.toVector(),Data.pCO2Err.toVector());
    mainGraph2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 4));
    mainGraph2->setErrorType(QCPGraph::etValue);
    mainGraph2->setErrorPen(QPen(Qt::red));
    mainGraph2->rescaleAxes();

    // cCa
    QCPGraph *mainGraph3 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft, 2));
    mainGraph3->setPen(QPen(Qt::green));
    mainGraph3->setLineStyle(QCPGraph::lsLine);
    //mainGraph3->setData(Time.toVector(),Data.cCa.toVector());
    mainGraph3->setDataValueError(Time.toVector(),Data.cCa.toVector(),Data.cCaErr.toVector(),Data.cCaErr.toVector());
    mainGraph3->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 4));
    mainGraph3->setErrorType(QCPGraph::etValue);
    mainGraph3->setErrorPen(QPen(Qt::green));
    mainGraph3->rescaleAxes();

    // Main Graph 2
    //Temp
    QCPGraph *mainGraph12 = ui->Graph->addGraph(wideAxisRect1->axis(QCPAxis::atBottom), wideAxisRect1->axis(QCPAxis::atLeft));
    mainGraph12->setPen(QPen(Qt::black));
    mainGraph12->setLineStyle(QCPGraph::lsLine);
    mainGraph12->setData(Time.toVector(), Growthincm.toVector());
    mainGraph12->rescaleAxes();
    // pCO2
    QCPGraph *mainGraph22 = ui->Graph->addGraph(wideAxisRect1->axis(QCPAxis::atBottom), wideAxisRect1->axis(QCPAxis::atLeft, 1));
    mainGraph22->setPen(QPen(Qt::red));
    mainGraph22->setLineStyle(QCPGraph::lsLine);
    mainGraph22->setData(Time.toVector(),Result.AppcCa.toVector());
    // cCa
    QCPGraph *mainGraph32 = ui->Graph->addGraph(wideAxisRect1->axis(QCPAxis::atBottom), wideAxisRect1->axis(QCPAxis::atLeft, 1));
    mainGraph32->setPen(QPen(Qt::green));
    mainGraph32->setLineStyle(QCPGraph::lsLine);
    mainGraph32->setData(Time.toVector(),Data.cCa.toVector());


    ui->Graph->replot();
}

void GraphViewer::on_pushButton_clicked()
{
    setGraph();
}
