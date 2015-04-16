#ifndef STALBIAS_H
#define STALBIAS_H

#include <QMainWindow>

namespace Ui {
class StalBIAS;
}

class StalBIAS : public QMainWindow
{
    Q_OBJECT

public:
    explicit StalBIAS(QWidget *parent = 0);
    ~StalBIAS();

private:
    Ui::StalBIAS *ui;
};

#endif // STALBIAS_H
