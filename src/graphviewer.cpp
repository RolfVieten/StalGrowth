#include "graphviewer.h"
#include "ui_graphviewer.h"

GraphViewer::GraphViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphViewer)
{
    ui->setupUi(this);
    ui->Graph->clearGraphs();
}

GraphViewer::~GraphViewer()
{
    delete ui;
}

