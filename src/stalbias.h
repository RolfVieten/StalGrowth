#ifndef STALBIAS_H
#define STALBIAS_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>

namespace Ui {
class StalBIAS;
}

struct DataItem{
    QList<QDateTime>      DateTimes;
    QList<double>         DripInt;
    QList<double>         DripErr;
    QList<double>         FilmThick;
    QList<double>         FilmErr;
    QList<double>         Temp;
    QList<double>         TempErr;
    QList<double>         pCO2;
    QList<double>         pCO2Err;
    QList<double>         cCa;
    QList<double>         cCaErr;
};

struct Results{

};

class StalBIAS : public QMainWindow
{
    Q_OBJECT

public:
    explicit StalBIAS(QWidget *parent = 0);
    ~StalBIAS();

private slots:
    void on_actionLoad_CSV_triggered();

    void on_actionChange_Data_triggered();

private:
    Ui::StalBIAS *ui;
    QList<QStringList> csv;
    QStandardItemModel *model;
    QStandardItemModel *newmodel;
    QList<QStandardItem*> standardItemList;

    // This stores the model individually
    DataItem Data;

    // Debug Bool
    bool Debug;

    // Convertion Function
    void convert_to_customData();

    // Check CSV
    void checkString(QString &temp, QChar character = 0, bool First = false);
};

#endif // STALBIAS_H
