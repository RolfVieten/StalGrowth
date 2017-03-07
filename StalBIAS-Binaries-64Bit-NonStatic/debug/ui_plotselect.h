/********************************************************************************
** Form generated from reading UI file 'plotselect.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTSELECT_H
#define UI_PLOTSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PlotSelect
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *Graph;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *savepng;
    QSpacerItem *horizontalSpacer;
    QPushButton *customSeason;
    QPushButton *pushButton;
    QPushButton *Sbias_button;
    QTextBrowser *textBrowser;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlotSelect)
    {
        if (PlotSelect->objectName().isEmpty())
            PlotSelect->setObjectName(QStringLiteral("PlotSelect"));
        PlotSelect->resize(937, 510);
        centralwidget = new QWidget(PlotSelect);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Graph = new QCustomPlot(centralwidget);
        Graph->setObjectName(QStringLiteral("Graph"));
        Graph->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Graph->sizePolicy().hasHeightForWidth());
        Graph->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(Graph);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        savepng = new QPushButton(centralwidget);
        savepng->setObjectName(QStringLiteral("savepng"));

        horizontalLayout_2->addWidget(savepng);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        customSeason = new QPushButton(centralwidget);
        customSeason->setObjectName(QStringLiteral("customSeason"));

        horizontalLayout_2->addWidget(customSeason);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        Sbias_button = new QPushButton(centralwidget);
        Sbias_button->setObjectName(QStringLiteral("Sbias_button"));

        horizontalLayout_2->addWidget(Sbias_button);


        verticalLayout_2->addLayout(horizontalLayout_2);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(textBrowser);


        horizontalLayout->addLayout(verticalLayout_2);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setMinimumSize(QSize(279, 0));
        tableWidget->setColumnCount(4);

        horizontalLayout->addWidget(tableWidget);

        PlotSelect->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlotSelect);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 937, 25));
        PlotSelect->setMenuBar(menubar);
        statusbar = new QStatusBar(PlotSelect);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PlotSelect->setStatusBar(statusbar);

        retranslateUi(PlotSelect);

        QMetaObject::connectSlotsByName(PlotSelect);
    } // setupUi

    void retranslateUi(QMainWindow *PlotSelect)
    {
        PlotSelect->setWindowTitle(QApplication::translate("PlotSelect", "MainWindow", 0));
        savepng->setText(QApplication::translate("PlotSelect", "Save PNG", 0));
        customSeason->setText(QApplication::translate("PlotSelect", "Auto Season", 0));
        pushButton->setText(QApplication::translate("PlotSelect", "Student's T-Test", 0));
        Sbias_button->setText(QApplication::translate("PlotSelect", "Seasonal Bias", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotSelect: public Ui_PlotSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTSELECT_H
