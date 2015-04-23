#ifndef GRAPHVIEWER_H
#define GRAPHVIEWER_H
#include "dataitem.h"
#include <QWidget>

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

private:
    Ui::GraphViewer *ui;
    DataItem Data;
    Results Result;
    QList<double> Time;
    QList<double> Growthincm;
};

#endif // GRAPHVIEWER_H
