#include "customseason.h"
#include "ui_customseason.h"

CustomSeason::CustomSeason(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomSeason)
{
    ui->setupUi(this);
    ui->start->setDisplayFormat("dd/MMM");
    ui->end->setDisplayFormat("dd/MMM");
    ui->label->hide();
}

CustomSeason::~CustomSeason()
{
    delete ui;
}

void CustomSeason::on_buttonBox_accepted()
{
}

void CustomSeason::on_start_userDateChanged(const QDate &date)
{
    start = date;
    if (start >= end){
        ui->label->show();
    } else {
        ui->label->hide();
    }
}

void CustomSeason::on_end_userDateChanged(const QDate &date)
{
    end = date;
    if (start >= end){
        ui->label->show();
    } else {
        ui->label->hide();
    }
}
