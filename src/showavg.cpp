#include "showavg.h"
#include "ui_showavg.h"

ShowAvg::ShowAvg(bool cs, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ShowAvg),
    cseason(cs)
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
    model->setHorizontalHeaderItem(2,new QStandardItem("Average GrowthRate m/yr"));
    model->setHorizontalHeaderItem(3,new QStandardItem("Standard Deviation m/yr"));
    model->setHorizontalHeaderItem(4,new QStandardItem(" # Data"));
    myAvg = LAvg;

    for (int i = 0; i < LAvg.size(); i++){
        if(LAvg.at(i).data.size() != 0){
            QList<QStandardItem*> temp;
            temp.append(new QStandardItem(QDateTime().fromTime_t(LAvg.at(i).dated).toString("yyyy/MM/dd")));
            if(cseason){
                if(LAvg.at(i).slow){
                    temp.append(new QStandardItem("Slow Growth Season"));
                } else {
                    temp.append(new QStandardItem("Fast Growth Season"));
                }
            } else {
                if(LAvg.at(i).slow){
                    temp.append(new QStandardItem("Summer Growth Season"));
                } else {
                    temp.append(new QStandardItem("Winter Growth Season"));
                }
            }
            temp.append(new QStandardItem(QString::number(LAvg.at(i).mean,'f', 7)));
            temp.append(new QStandardItem(QString::number(LAvg.at(i).sd,'e', 3)));
            temp.append(new QStandardItem(QString::number(LAvg.at(i).data.size())));
            model->appendRow(temp);
            temp.clear();
        }
    }
    ui->tableView->resizeColumnsToContents();
}

void ShowAvg::on_pushButton_clicked()
{
    QFile savef;
    QString fileName = QFileDialog::getSaveFileName(this,"Save as:",QDir::currentPath(),"*.csv");
    savef.setFileName(fileName);
    if (!savef.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&savef);
    out << "Date/Time"
        << ", "
        << "Growth Season"
        << ", "
        << "Avg Growth Rate (m/yr)"
        << ", "
        << "Standard Deviation (m/yr)"
        << ", "
        << "# Data points"
        << "\n";
    for (int i = 0; i < myAvg.size(); i++){
         if(myAvg.at(i).data.size() != 0){
         out << QDateTime().fromTime_t(myAvg.at(i).dated).toString("yyyy/MM/dd")
             << ",";
            if(cseason){
                if(myAvg.at(i).slow){
                    out << "Slow Growth Season" << "," ;
                } else {
                    out << "Fast Growth Season" << "," ;
                }
            } else {
                if(myAvg.at(i).slow){
                    out << "Summer Growth Season" << ",";
                } else {
                    out << "Winter Growth Season" << ",";
                }
            }
            out << QString::number(myAvg.at(i).mean,'f', 7) << ",";
            out << QString::number(myAvg.at(i).sd,'e', 3) << ",";
            out << QString::number(myAvg.at(i).data.size()) << ",";
            out << "\n";
        }
    }
    savef.close();
}
