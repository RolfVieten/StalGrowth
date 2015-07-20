#ifndef GRAPHVIEWER_H
#define GRAPHVIEWER_H
#include "dataitem.h"
#include <QWidget>
#include "qcustomplot.h"
#include "customseason.h"

namespace Ui {
class GraphViewer;
}

class GraphViewer : public QWidget
{
    Q_OBJECT

public:
    explicit GraphViewer(QWidget *parent = 0);
    ~GraphViewer();
    void setresult(DataItem data,Results result);
    void setGraph();

private slots:
    void on_pushButton_clicked();

    void on_yrmk_clicked();

    void on_ssmk_clicked();

    void onMouseMoveGraph(QMouseEvent* evt);

    void on_cseason_clicked();

    void oncsaccept();

private:
    Ui::GraphViewer *ui;
    CustomSeason *cs;
    DataItem Data;
    Results Result;
    QList<Avg> LAvg;
    QList<double> Time;
    QList<double> Growthincm;
    QList<QCPItemLine*> yrs;
    QList<QCPItemRect*> rct;
    QCPAxisRect *wideAxisRect1; // OutputAxisRectangle
    QCPGraph *mainGraph42; // Average square plot
    QCPItemTracer *tracer;

};

#endif // GRAPHVIEWER_H
