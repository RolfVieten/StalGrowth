/********************************************************************************
** Form generated from reading UI file 'showavg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWAVG_H
#define UI_SHOWAVG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowAvg
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QWidget *ShowAvg)
    {
        if (ShowAvg->objectName().isEmpty())
            ShowAvg->setObjectName(QStringLiteral("ShowAvg"));
        ShowAvg->resize(300, 406);
        horizontalLayout = new QHBoxLayout(ShowAvg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView = new QTableView(ShowAvg);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);


        retranslateUi(ShowAvg);

        QMetaObject::connectSlotsByName(ShowAvg);
    } // setupUi

    void retranslateUi(QWidget *ShowAvg)
    {
        ShowAvg->setWindowTitle(QApplication::translate("ShowAvg", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowAvg: public Ui_ShowAvg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWAVG_H
