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
    }
}

void GraphViewer::setGraph(){
    ui->Graph->plotLayout()->clear();
    QCPAxisRect *wideAxisRect = new QCPAxisRect(ui->Graph);
    wideAxisRect->setupFullAxesBox(true);
    wideAxisRect->addAxis(QCPAxis::atLeft)->setTickLabelColor(Qt::red); // add an extra axis on the left and color its numbers
    wideAxisRect->addAxis(QCPAxis::atLeft)->setTickLabelColor(Qt::green); // add an extra axis on the left and color its numbers
    wideAxisRect->axis(QCPAxis::atBottom)->setTickLabelType(QCPAxis::ltDateTime);
    wideAxisRect->axis(QCPAxis::atBottom)->setDateTimeFormat("MMMM\nyyyy");
    ui->Graph->plotLayout()->addElement(0,0,wideAxisRect);
    // Main Graph
    //Temp
    QCPGraph *mainGraph1 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
    mainGraph1->setPen(QPen(Qt::black));
    mainGraph1->setLineStyle(QCPGraph::lsLine);
    mainGraph1->setData(Time.toVector(), Data.Temp.toVector());
    mainGraph1->rescaleAxes();
    // pCO2
    QCPGraph *mainGraph2 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft, 1));
    mainGraph2->setPen(QPen(Qt::red));
    mainGraph2->setLineStyle(QCPGraph::lsLine);
    mainGraph2->setData(Time.toVector(),Data.pCO2.toVector());
    mainGraph2->rescaleAxes();
    // cCa
    QCPGraph *mainGraph3 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft, 2));
    mainGraph3->setPen(QPen(Qt::green));
    mainGraph3->setLineStyle(QCPGraph::lsLine);
    mainGraph3->setData(Time.toVector(),Data.cCa.toVector());
    mainGraph3->rescaleAxes();

    ui->Graph->replot();
}

void GraphViewer::on_pushButton_clicked()
{
    setGraph();
}
