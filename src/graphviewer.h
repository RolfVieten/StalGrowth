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
    void graphresult(DataItem Data,Results Result);

private:
    Ui::GraphViewer *ui;
};

#endif // GRAPHVIEWER_H
