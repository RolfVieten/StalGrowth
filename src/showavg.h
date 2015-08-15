#ifndef SHOWAVG_H
#define SHOWAVG_H
#include "dataitem.h"
#include <QWidget>
#include <QStandardItemModel>

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

private:
    Ui::ShowAvg *ui;
    bool cseason;
    QStandardItemModel *model;
};

#endif // SHOWAVG_H
