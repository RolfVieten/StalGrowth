#ifndef GRAPHVIEWER_H
#define GRAPHVIEWER_H
#include "dataitem.h"
#include <QWidget>
#include "qcustomplot.h"
#include "showavg.h"
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
    void setresult(const DataItem data, const Results result);
    void setGraph();

public slots:
    void on_pushButton_clicked();

private slots:

    void on_yrmk_clicked();

    void on_ssmk_clicked();

    void onMouseMoveGraph(QMouseEvent* evt);

    void on_cseason_clicked();

    void oncsaccept();

private:
    Ui::GraphViewer *ui;
    CustomSeason *cs;
    ShowAvg *sa;
    DataItem Data;
    Results Result;
    QList<Avg> LAvg;
    QList<double> Time;
    QList<double> Growthincm;
    QList<QCPItemRect*> rct;
    QList<QCPItemRect*> rct1;
    QCPAxisRect *wideAxisRect;  // InputAxisRectangle
    QCPAxisRect *wideAxisRect1; // OutputAxisRectangle
    QCPGraph *mainGraph42; // Average square plot
    QCPItemTracer *tracer;
    bool tconnect;

};

#endif // GRAPHVIEWER_H
