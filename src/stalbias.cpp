#include "stalbias.h"
#include "ui_stalbias.h"

StalBIAS::StalBIAS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StalBIAS)
{
    ui->setupUi(this);
    ui->mainToolBar->hide();
}

StalBIAS::~StalBIAS()
{
    delete ui;
}
