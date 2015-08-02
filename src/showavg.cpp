#include "showavg.h"
#include "ui_showavg.h"

ShowAvg::ShowAvg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowAvg)
{
    ui->setupUi(this);
    model = new QStandardItemModel(0,4,this);
    ui->tableView->setModel(model);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("Average List");
}

ShowAvg::~ShowAvg()
{
    delete ui;
}

void ShowAvg::setAvg(QList<Avg> LAvg){
    model->setHorizontalHeaderItem(0,new QStandardItem("Date Time"));
    model->setHorizontalHeaderItem(1,new QStandardItem("Growth Season"));
    model->setHorizontalHeaderItem(2,new QStandardItem("Average GrowthRate mm/yr"));
    model->setHorizontalHeaderItem(3,new QStandardItem("Standard Deviation mm/yr"));
    model->setHorizontalHeaderItem(4,new QStandardItem(" # Data"));


    for (int i = 0; i < LAvg.size(); i++){
        if(LAvg.at(i).sd != 0){
            QList<QStandardItem*> temp;
            temp.append(new QStandardItem(QDateTime().fromTime_t(LAvg.at(i).dated).toString("yyyy/MM/dd")));
            if(LAvg.at(i).slow){
                temp.append(new QStandardItem("Slow Growth Season"));
            } else {
                temp.append(new QStandardItem("Fast Growth Season"));
            }
            temp.append(new QStandardItem(QString::number(LAvg.at(i).mean*1000)));
            temp.append(new QStandardItem(QString::number(LAvg.at(i).sd*1000)));
            temp.append(new QStandardItem(QString::number(LAvg.at(i).data.size())));
            model->appendRow(temp);
            temp.clear();
        }
    }
    ui->tableView->resizeColumnsToContents();
}
