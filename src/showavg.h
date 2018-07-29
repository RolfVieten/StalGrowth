#ifndef SHOWAVG_H
#define SHOWAVG_H
#include "dataitem.h"
#include <QWidget>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>


namespace Ui {
class ShowAvg;
}

class ShowAvg : public QWidget
{
    Q_OBJECT

public:
    explicit ShowAvg(bool cs = true, QWidget *parent = 0);
    ~ShowAvg();
    void setAvg(QList<Avg> LAvg);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowAvg *ui;
    bool cseason;
    QStandardItemModel *model;
    QList<Avg> myAvg;
};

#endif // SHOWAVG_H
