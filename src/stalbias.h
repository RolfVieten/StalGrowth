#ifndef STALBIAS_H
#define STALBIAS_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <cmath>
#include "dataitem.h"
#include "graphviewer.h"
#include "plotselect.h"

namespace Ui {
class StalBIAS;
}

class StalBIAS : public QMainWindow
{
    Q_OBJECT

public:
    explicit StalBIAS(QWidget *parent = 0);
    ~StalBIAS();

private slots:
    void on_actionLoad_CSV_triggered();

    void on_actionGraph_Viewer_triggered();

    void on_actionCalculate_Growth_Rate_triggered();

    void on_actionDebug_Mode_triggered();

    void on_CalcGrap_clicked();

    void on_statistic_clicked();

private:
    Ui::StalBIAS *ui;
    QList<QStringList> csv;
    QStandardItemModel *model;
    QStandardItemModel *newmodel;
    QList<QStandardItem*> standardItemList;

    // This stores the model individually
    DataItem Data;
    Results Result;

    // Calculate Results
    Results CalcRes(DataItem data);

    // Grapth Viewer
    GraphViewer GV;
    PlotSelect PS;


    // Debug Bool
    bool Debug;

    // Convertion Function
    void convert_to_customData();

    // Check CSV
    void checkString(QString &temp, QChar character = 0, bool First = false);
};

#endif // STALBIAS_H
