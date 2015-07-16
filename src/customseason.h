#ifndef CUSTOMSEASON_H
#define CUSTOMSEASON_H

#include <QDialog>
#include <QDate>

namespace Ui {
class CustomSeason;
}

class CustomSeason : public QDialog
{
    Q_OBJECT

public:
    explicit CustomSeason(QWidget *parent = 0);
    QDate start;
    QDate end;
    ~CustomSeason();

private slots:
    void on_buttonBox_accepted();

    void on_start_userDateChanged(const QDate &date);

    void on_end_userDateChanged(const QDate &date);

private:
    Ui::CustomSeason *ui;
};

#endif // CUSTOMSEASON_H
