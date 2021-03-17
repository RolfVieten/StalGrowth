/********************************************************************************
** Form generated from reading UI file 'graphviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHVIEWER_H
#define UI_GRAPHVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_GraphViewer
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *Graph;
    QHBoxLayout *horizontalLayout;
    QLabel *GL;
    QLabel *growthl;
    QFrame *line;
    QLabel *DL;
    QLabel *datel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *savepng;
    QFrame *line_3;
    QPushButton *cseason;
    QPushButton *ssmk;
    QPushButton *yrmk;
    QPushButton *ErrorBar;
    QPushButton *pushButton;

    void setupUi(QWidget *GraphViewer)
    {
        if (GraphViewer->objectName().isEmpty())
            GraphViewer->setObjectName(QStringLiteral("GraphViewer"));
        GraphViewer->resize(1078, 435);
        verticalLayout = new QVBoxLayout(GraphViewer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Graph = new QCustomPlot(GraphViewer);
        Graph->setObjectName(QStringLiteral("Graph"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Graph->sizePolicy().hasHeightForWidth());
        Graph->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Graph);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        GL = new QLabel(GraphViewer);
        GL->setObjectName(QStringLiteral("GL"));

        horizontalLayout->addWidget(GL);

        growthl = new QLabel(GraphViewer);
        growthl->setObjectName(QStringLiteral("growthl"));

        horizontalLayout->addWidget(growthl);

        line = new QFrame(GraphViewer);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        DL = new QLabel(GraphViewer);
        DL->setObjectName(QStringLiteral("DL"));

        horizontalLayout->addWidget(DL);

        datel = new QLabel(GraphViewer);
        datel->setObjectName(QStringLiteral("datel"));

        horizontalLayout->addWidget(datel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(GraphViewer);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        savepng = new QPushButton(GraphViewer);
        savepng->setObjectName(QStringLiteral("savepng"));

        horizontalLayout->addWidget(savepng);

        line_3 = new QFrame(GraphViewer);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        cseason = new QPushButton(GraphViewer);
        cseason->setObjectName(QStringLiteral("cseason"));

        horizontalLayout->addWidget(cseason);

        ssmk = new QPushButton(GraphViewer);
        ssmk->setObjectName(QStringLiteral("ssmk"));

        horizontalLayout->addWidget(ssmk);

        yrmk = new QPushButton(GraphViewer);
        yrmk->setObjectName(QStringLiteral("yrmk"));

        horizontalLayout->addWidget(yrmk);

        ErrorBar = new QPushButton(GraphViewer);
        ErrorBar->setObjectName(QStringLiteral("ErrorBar"));

        horizontalLayout->addWidget(ErrorBar);

        pushButton = new QPushButton(GraphViewer);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GraphViewer);

        QMetaObject::connectSlotsByName(GraphViewer);
    } // setupUi

    void retranslateUi(QWidget *GraphViewer)
    {
        GraphViewer->setWindowTitle(QApplication::translate("GraphViewer", "Form", nullptr));
        GL->setText(QApplication::translate("GraphViewer", "Growth Rate:", nullptr));
        growthl->setText(QString());
        DL->setText(QApplication::translate("GraphViewer", "Date: ", nullptr));
        datel->setText(QString());
        pushButton_2->setText(QApplication::translate("GraphViewer", "Save CSV", nullptr));
        savepng->setText(QApplication::translate("GraphViewer", "Save PNG", nullptr));
        cseason->setText(QApplication::translate("GraphViewer", "Custom Season", nullptr));
        ssmk->setText(QApplication::translate("GraphViewer", "Add Seasons", nullptr));
        yrmk->setText(QApplication::translate("GraphViewer", "Add year marks", nullptr));
        ErrorBar->setText(QApplication::translate("GraphViewer", "Toggle ErrorBars", nullptr));
        pushButton->setText(QApplication::translate("GraphViewer", "Clear/Plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphViewer: public Ui_GraphViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVIEWER_H
