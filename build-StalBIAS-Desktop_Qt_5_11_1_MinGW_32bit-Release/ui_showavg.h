/********************************************************************************
** Form generated from reading UI file 'showavg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWAVG_H
#define UI_SHOWAVG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowAvg
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QWidget *ShowAvg)
    {
        if (ShowAvg->objectName().isEmpty())
            ShowAvg->setObjectName(QStringLiteral("ShowAvg"));
        ShowAvg->resize(300, 406);
        verticalLayout = new QVBoxLayout(ShowAvg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(ShowAvg);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(ShowAvg);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(ShowAvg);

        QMetaObject::connectSlotsByName(ShowAvg);
    } // setupUi

    void retranslateUi(QWidget *ShowAvg)
    {
        ShowAvg->setWindowTitle(QApplication::translate("ShowAvg", "Form", nullptr));
        pushButton->setText(QApplication::translate("ShowAvg", "Save CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowAvg: public Ui_ShowAvg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWAVG_H
