#include "graphviewer.h"
#include "ui_graphviewer.h"

GraphViewer::GraphViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphViewer)
{
    ui->setupUi(this);
    ui->Graph->clearGraphs();
    this->setWindowTitle("Results Graph");
    ui->Graph->addLayer("boxes",ui->Graph->layer("grid"),QCustomPlot::limBelow);
    cs = new CustomSeason(this);
}

GraphViewer::~GraphViewer()
{
    delete ui;
}

void GraphViewer::setresult(const DataItem data, const Results result){
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

// Set up the Graph
void GraphViewer::setGraph(){
    ui->Graph->clearGraphs();
    ui->Graph->plotLayout()->clear();

    // Input
    wideAxisRect = new QCPAxisRect(ui->Graph);
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
    wideAxisRect1 = new QCPAxisRect(ui->Graph);
    wideAxisRect1->setupFullAxesBox(true);
    wideAxisRect1->addAxis(QCPAxis::atLeft); // add an extra axis on the left and color its numbers
    wideAxisRect1->axis(QCPAxis::atLeft,0)->setLabel("Growth Rate (m/yr)");
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
    QCPRange tmprange, tmprange1;

    // Input Graph
    //Temp
    QCPGraph *mainGraph1 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
    mainGraph1->setPen(QPen(Qt::black));
    mainGraph1->setLineStyle(QCPGraph::lsLine);
    mainGraph1->setDataValueError(Time.toVector(),Data.Temp.toVector(),Data.TempErr.toVector(),Data.TempErr.toVector());
    mainGraph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));
    mainGraph1->setErrorType(QCPGraph::etValue);
    mainGraph1->setErrorPen(QPen(Qt::black));
    mainGraph1->rescaleAxes();
    tmprange = wideAxisRect->axis(QCPAxis::atLeft,0)->range();
    wideAxisRect->axis(QCPAxis::atLeft,0)->setRangeLower(tmprange.lower-0.4);
    wideAxisRect->axis(QCPAxis::atLeft,0)->setRangeUpper(tmprange.upper+0.4);

    // pCO2
    QCPGraph *mainGraph2 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft, 1));
    mainGraph2->setPen(QPen(Qt::red));
    mainGraph2->setLineStyle(QCPGraph::lsLine);
    mainGraph2->setDataValueError(Time.toVector(),Data.pCO2.toVector(),Data.pCO2Err.toVector(),Data.pCO2Err.toVector());
    mainGraph2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));
    mainGraph2->setErrorType(QCPGraph::etValue);
    mainGraph2->setErrorPen(QPen(Qt::red));
    mainGraph2->rescaleAxes();

    // cCa
    QCPGraph *mainGraph3 = ui->Graph->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft, 2));
    mainGraph3->setPen(QPen(Qt::green));
    mainGraph3->setLineStyle(QCPGraph::lsLine);
    mainGraph3->setDataValueError(Time.toVector(),Data.cCa.toVector(),Data.cCaErr.toVector(),Data.cCaErr.toVector());
    mainGraph3->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));
    mainGraph3->setErrorType(QCPGraph::etValue);
    mainGraph3->setErrorPen(QPen(Qt::green));
    mainGraph3->rescaleAxes();

    // Output Graph
    //Growth
    QCPGraph *mainGraph12 = ui->Graph->addGraph(wideAxisRect1->axis(QCPAxis::atBottom), wideAxisRect1->axis(QCPAxis::atLeft));
    mainGraph12->setPen(QPen(Qt::black));
    mainGraph12->setLineStyle(QCPGraph::lsLine);
    mainGraph12->setDataValueError(Time.toVector(),Result.GrowthRate.toVector(),Result.GrowthErr.toVector(),Result.GrowthErr.toVector());
    mainGraph12->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    mainGraph12->setErrorType(QCPGraph::etValue);
    mainGraph12->setErrorPen(QPen(Qt::black));
    mainGraph12->rescaleAxes();

    // pCO2
    QCPGraph *mainGraph22 = ui->Graph->addGraph(wideAxisRect1->axis(QCPAxis::atBottom), wideAxisRect1->axis(QCPAxis::atLeft, 1));
    mainGraph22->setPen(QPen(Qt::red));
    mainGraph22->setLineStyle(QCPGraph::lsLine);
    mainGraph22->setDataValueError(Time.toVector(),Result.AppcCa.toVector(),Result.AppcCaErr.toVector(),Result.AppcCaErr.toVector());
    mainGraph22->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));
    mainGraph22->setErrorType(QCPGraph::etValue);
    mainGraph22->setErrorPen(QPen(Qt::red));
    mainGraph22->rescaleAxes();
    tmprange = wideAxisRect1->axis(QCPAxis::atLeft, 1)->range();

    // cCa
    QCPGraph *mainGraph32 = ui->Graph->addGraph(wideAxisRect1->axis(QCPAxis::atBottom), wideAxisRect1->axis(QCPAxis::atLeft, 1));
    mainGraph32->setPen(QPen(Qt::green));
    mainGraph32->setLineStyle(QCPGraph::lsLine);
    mainGraph32->setDataValueError(Time.toVector(),Data.cCa.toVector(),Data.cCaErr.toVector(),Data.cCaErr.toVector());
    mainGraph32->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));
    mainGraph32->setErrorType(QCPGraph::etValue);
    mainGraph32->setErrorPen(QPen(Qt::green));
    mainGraph32->rescaleAxes();;
    tmprange1 = wideAxisRect1->axis(QCPAxis::atLeft, 1)->range();
    // Normalize cCa Range
    if(tmprange.upper >= tmprange1.upper)
        wideAxisRect1->axis(QCPAxis::atLeft, 1)->setRangeUpper(tmprange.upper+0.1);
    else
        wideAxisRect1->axis(QCPAxis::atLeft, 1)->setRangeUpper(tmprange1.upper+0.1);
    if(tmprange.lower <= tmprange1.lower)
        wideAxisRect1->axis(QCPAxis::atLeft, 1)->setRangeLower(tmprange.lower-0.1);
    else
        wideAxisRect1->axis(QCPAxis::atLeft, 1)->setRangeLower(tmprange1.lower-0.1);

    // Add Average Graph
    mainGraph42 = ui->Graph->addGraph(wideAxisRect1->axis(QCPAxis::atBottom), wideAxisRect1->axis(QCPAxis::atLeft));

    // Create a tracer
    tracer = new QCPItemTracer(ui->Graph);
    ui->Graph->addItem(tracer);
    tracer->setClipToAxisRect(true);
    tracer->setClipAxisRect(wideAxisRect1);
    tracer->setGraph(wideAxisRect1->graphs().at(0));
    tracer->setInterpolating(true);
    tracer->setStyle(QCPItemTracer::tsCircle);
    tracer->setPen(QPen(Qt::black));
    tracer->setBrush(Qt::black);
    tracer->setSize(7);

    // Connect Graph to mouse
    connect(ui->Graph,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(onMouseMoveGraph(QMouseEvent*)));

    ui->Graph->replot();
}

// On Plot button Clicked
void GraphViewer::on_pushButton_clicked()
{
    // Create Graph
    setGraph();
}

// Function creates yearly marks
void GraphViewer::on_yrmk_clicked() {

    // Get the range
    QCPRange xrange;
    xrange = wideAxisRect1->axis(QCPAxis::atBottom)->range();
    QDateTime low, high, temp;
    low.setTime_t(xrange.lower);
    high.setTime_t(xrange.upper);

    // Start the loop
    QCPItemLine *newline, *newline1;
    for(int i = low.date().year(); i < high.date().year() + 2; i++){
        temp.setDate(QDate(i,1,1));

        // Check if within range
        if (temp > low && temp < high){

            newline = new QCPItemLine(ui->Graph);
            newline1 = new QCPItemLine(ui->Graph);

            // To input
            newline->setClipToAxisRect(true);
            newline->setClipAxisRect(wideAxisRect);
            newline->start->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
            newline->end->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
            newline->start->setCoords(temp.toTime_t(),QCPRange::minRange);
            newline->end->setCoords(temp.toTime_t(),QCPRange::maxRange);
            newline->setPen(QPen(QColor(Qt::blue)));

            // To output
            newline1->setClipToAxisRect(true);
            newline1->setClipAxisRect(wideAxisRect1);
            newline1->start->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
            newline1->end->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
            newline1->start->setCoords(temp.toTime_t(),QCPRange::minRange);
            newline1->end->setCoords(temp.toTime_t(),QCPRange::maxRange);
            newline1->setPen(QPen(QColor(Qt::blue)));

            // Add
            ui->Graph->addItem(newline);
            ui->Graph->addItem(newline1);
        }
    }
    ui->Graph->replot();
}

// Create summer/winter boxes
void GraphViewer::on_ssmk_clicked(){

    // Clear old Variables
    LAvg.clear();
    mainGraph42->clearData();

    // Get the range
    QCPRange xrange;
    xrange = wideAxisRect1->axis(QCPAxis::atBottom)->range();
    QDateTime low, high, summereqn, wintereqn;
    low.setTime_t(xrange.lower);
    high.setTime_t(xrange.upper);

    // Check Range

    // Start the loop
    QCPItemRect *newrect;
    int j = 0;
    for(int i = low.date().year(); i < high.date().year() + 2; i++){
        summereqn.setDate(QDate(i,3,20));
        wintereqn.setDate(QDate(i,9,22));

        // Check if within range
        if (summereqn < low){
            newrect = new QCPItemRect(ui->Graph);
            rct.append(newrect);
            rct.at(j)->setClipToAxisRect(false);
            rct.at(j)->setBrush(QBrush(QColor(Qt::yellow)));
            rct.at(j)->setClipAxisRect(wideAxisRect1);
            rct.at(j)->topLeft->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
            rct.at(j)->topLeft->setCoords(low.toTime_t(),100);
            if (wintereqn > high){
                rct.at(j)->bottomRight->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
                rct.at(j)->bottomRight->setCoords(high.toTime_t(),-100);
                rct.at(j)->setLayer("boxes");
                j++;
            } else {
                rct.at(j)->bottomRight->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
                rct.at(j)->bottomRight->setCoords(wintereqn.toTime_t(),-100);
                rct.at(j)->setLayer("boxes");
                j++;
            }
        } else if (summereqn < high){
            newrect = new QCPItemRect(ui->Graph);
            rct.append(newrect);
            rct.at(j)->setClipToAxisRect(false);
            rct.at(j)->setClipAxisRect(wideAxisRect1);
            rct.at(j)->setBrush(QBrush(QColor(Qt::yellow)));
            rct.at(j)->topLeft->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
            rct.at(j)->topLeft->setCoords(summereqn.toTime_t(),100);
            if (wintereqn > high){
                rct.at(j)->bottomRight->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
                rct.at(j)->bottomRight->setCoords(high.toTime_t(),-100);
                rct.at(j)->setLayer("boxes");
                j++;
            } else {
                rct.at(j)->bottomRight->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
                rct.at(j)->bottomRight->setCoords(wintereqn.toTime_t(),-100);
                rct.at(j)->setLayer("boxes");
                j++;
            }
        }
    }

    // Average start
    QList<time_t> split;

    // Determines averages
    for(int i = low.date().year(); i < high.date().year() + 2; i++){
        summereqn.setDate(QDate(i,3,20));
        wintereqn.setDate(QDate(i,9,22));

        if (summereqn < low){
            split.append(low.toTime_t());
            if (wintereqn > high){
                split.append(high.toTime_t());
            } else {
                split.append(wintereqn.toTime_t());
            }
        } else if (summereqn < high){
            split.append(summereqn.toTime_t());
            if (wintereqn > high){
                split.append(high.toTime_t());
            } else {
                split.append(wintereqn.toTime_t());
            }
        }
    }

    // Adds start/end points
    if(split.last() != high.toTime_t()){
        split.append(high.toTime_t());
    }
    if(split.first() != low.toTime_t()){
        split.prepend(low.toTime_t());
    }

    // Determine Average
    int k = 0;
    for(int i = 0; i < (split.size()-1); i++){
        Avg temp;
        temp.setdate(split.at(k),split.at(k+1));
        for(int l = 0; l < Result.GrowthRate.size(); l++){
            if( Data.DateTimes.at(l).toTime_t() >= split.at(k) && Data.DateTimes.at(l).toTime_t() < split.at(k+1)){
                temp.data.append(Result.GrowthRate.at(l));
            }
        }
        temp.calc();
        LAvg.append(temp);
        k++;
    }

    // Add Average Points
    mainGraph42->setLineStyle(QCPGraph::lsNone);
    mainGraph42->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare,QColor(Qt::black),QColor(Qt::black), 8));

    for(int i = 0; i < LAvg.size(); i++){
        mainGraph42->addData(LAvg.at(i).dated,LAvg.at(i).mean);
    }
    //mainGraph12->setErrorType(QCPGraph::etValue);
    //mainGraph12->setErrorPen(QPen(Qt::black));

    // END Average

    ui->Graph->replot();
}

// What to do when custom season prompt is accepted
void GraphViewer::oncsaccept(){

    // Set Start/End
    QDate start = cs->start;
    QDate end = cs->end;

    // Clear old variables
    LAvg.clear();
    mainGraph42->clearData();
    rct.clear();
    rct1.clear();

    // Debug info, it's discreet
    ui->datel->setText(end.toString("MMM/dd"));
    ui->growthl->setText(start.toString("MMM/dd"));

    // Get the range
    QCPRange xrange;
    xrange = wideAxisRect1->axis(QCPAxis::atBottom)->range();
    QDateTime low, high, startd, endd;
    low.setTime_t(xrange.lower);
    high.setTime_t(xrange.upper);

    // Start the loop
    QCPItemRect *newrect, *newrect1;
    int j = 0;
    for(int i = low.date().year(); i < high.date().year() + 2; i++){
        // Set Date
        startd.setDate(QDate(i,start.month(),start.day()));
        endd.setDate(QDate(i,end.month(),end.day()));

        // Start Rectangle
        newrect = new QCPItemRect(ui->Graph);
        newrect1= new QCPItemRect(ui->Graph);

        if(startd <= low){
            rct.append(newrect);
            rct.at(j)->setClipAxisRect(wideAxisRect);
            rct.at(j)->setClipToAxisRect(true);
            rct.at(j)->setBrush(QBrush(QColor(Qt::yellow)));
            rct.at(j)->topLeft->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
            rct.at(j)->topLeft->setCoords(low.toTime_t(),100);

            rct1.append(newrect1);
            rct1.at(j)->setClipAxisRect(wideAxisRect1);
            rct1.at(j)->setClipToAxisRect(true);
            rct1.at(j)->setBrush(QBrush(QColor(Qt::yellow)));
            rct1.at(j)->topLeft->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
            rct1.at(j)->topLeft->setCoords(low.toTime_t(),100);

            // End Rectangle
            if (endd <= high) {
                rct.at(j)->bottomRight->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
                rct.at(j)->bottomRight->setCoords(endd.toTime_t(),-100);
                rct.at(j)->setLayer("boxes");

                rct1.at(j)->bottomRight->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
                rct1.at(j)->bottomRight->setCoords(endd.toTime_t(),-100);
                rct1.at(j)->setLayer("boxes");

                j++;
            } else {
                rct.at(j)->bottomRight->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
                rct.at(j)->bottomRight->setCoords(high.toTime_t(),-100);
                rct.at(j)->setLayer("boxes");

                rct1.at(j)->bottomRight->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
                rct1.at(j)->bottomRight->setCoords(high.toTime_t(),-100);
                rct1.at(j)->setLayer("boxes");

                j++;
            }
        } else {
            rct.append(newrect);
            rct.at(j)->setClipAxisRect(wideAxisRect);
            rct.at(j)->setClipToAxisRect(true);
            rct.at(j)->setBrush(QBrush(QColor(Qt::yellow)));
            rct.at(j)->topLeft->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
            rct.at(j)->topLeft->setCoords(startd.toTime_t(),100);

            rct1.append(newrect1);
            rct1.at(j)->setClipAxisRect(wideAxisRect1);
            rct1.at(j)->setClipToAxisRect(true);
            rct1.at(j)->setBrush(QBrush(QColor(Qt::yellow)));
            rct1.at(j)->topLeft->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
            rct1.at(j)->topLeft->setCoords(startd.toTime_t(),100);

            // End Rectangle
            if (endd <= high) {
                rct.at(j)->bottomRight->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
                rct.at(j)->bottomRight->setCoords(endd.toTime_t(),-100);
                rct.at(j)->setLayer("boxes");

                rct1.at(j)->bottomRight->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
                rct1.at(j)->bottomRight->setCoords(endd.toTime_t(),-100);
                rct1.at(j)->setLayer("boxes");

                j++;
            } else {
                rct.at(j)->bottomRight->setAxes(wideAxisRect->axis(QCPAxis::atBottom),wideAxisRect->axis(QCPAxis::atLeft));
                rct.at(j)->bottomRight->setCoords(high.toTime_t(),-100);
                rct.at(j)->setLayer("boxes");

                rct1.at(j)->bottomRight->setAxes(wideAxisRect1->axis(QCPAxis::atBottom),wideAxisRect1->axis(QCPAxis::atLeft));
                rct1.at(j)->bottomRight->setCoords(high.toTime_t(),-100);
                rct1.at(j)->setLayer("boxes");

                j++;
            }
        }

    }


    // Average
    QList<time_t> split; // Split Boxes

    // Same code as above sets where to split the data
    for(int i = low.date().year(); i < high.date().year() + 2; i++){
        startd.setDate(QDate(i,start.month(),start.day()));
        endd.setDate(QDate(i,end.month(),end.day()));

        if (startd < low){
            split.append(low.toTime_t());
            if (endd > high){
                split.append(high.toTime_t());
            } else {
                split.append(endd.toTime_t());
            }
        } else if (startd < high){
            split.append(startd.toTime_t());
            if (endd > high){
                split.append(high.toTime_t());
            } else {
                split.append(endd.toTime_t());
            }
        }
    }

    // Adds start and end variables
    if(split.last() != high.toTime_t()){
        split.append(high.toTime_t());

    }
    if(split.first() != low.toTime_t()){
        split.prepend(low.toTime_t());
    }

    // Determines the Averages
    int k = 0;
    for(int i = 0; i < (split.size()-1); i++){
        Avg temp;
        temp.setdate(split.at(k),split.at(k+1));
        for(int l = 0; l < Result.GrowthRate.size(); l++){
            if( Data.DateTimes.at(l).toTime_t() >= split.at(k) && Data.DateTimes.at(l).toTime_t() < split.at(k+1)){
                temp.data.append(Result.GrowthRate.at(l));
            }
        }
        temp.calc();
        LAvg.append(temp);
        k++;
    }

    // Add Points
    mainGraph42->setLineStyle(QCPGraph::lsNone);
    mainGraph42->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare,QColor(Qt::black),QColor(Qt::black), 8));

    for(int i = 0; i < LAvg.size(); i++){
        mainGraph42->addData(LAvg.at(i).dated,LAvg.at(i).mean);
    }
    //mainGraph12->setErrorType(QCPGraph::etValue);
    //mainGraph12->setErrorPen(QPen(Qt::black));

    // END Average

    ui->Graph->replot();
}

// Tracer shows time and growth Rate
void GraphViewer::onMouseMoveGraph(QMouseEvent* evt) {
    if(!wideAxisRect1->graphs().at(0)->data()->empty()){
        double yv;
        int xg;


        xg =wideAxisRect1->axis(QCPAxis::atBottom)->pixelToCoord(evt->pos().x());
        //yg =wideAxisRect1->axis(QCPAxis::atLeft)->pixelToCoord(evt->pos().y());

        tracer->setGraphKey(xg);
        ui->Graph->replot();
        yv = tracer->position->value();

        QDateTime temp;
        temp = QDateTime::fromTime_t(xg);
        ui->growthl->setText(QString::number(yv));
        ui->datel->setText(temp.toString("dd/MMM/yyyy"));
    }
}

// What to do when we click Custom Season
void GraphViewer::on_cseason_clicked()
{
    cs->show();
    connect(cs,SIGNAL(accepted()),this,SLOT(oncsaccept()));
}

