/********************************************************************************
** Form generated from reading UI file 'stalbias.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STALBIAS_H
#define UI_STALBIAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StalBIAS
{
public:
    QAction *actionDebug_Mode;
    QAction *actionAbout;
    QAction *actionLoad_CSV;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFIle;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StalBIAS)
    {
        if (StalBIAS->objectName().isEmpty())
            StalBIAS->setObjectName(QStringLiteral("StalBIAS"));
        StalBIAS->resize(685, 473);
        actionDebug_Mode = new QAction(StalBIAS);
        actionDebug_Mode->setObjectName(QStringLiteral("actionDebug_Mode"));
        actionAbout = new QAction(StalBIAS);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLoad_CSV = new QAction(StalBIAS);
        actionLoad_CSV->setObjectName(QStringLiteral("actionLoad_CSV"));
        centralWidget = new QWidget(StalBIAS);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        StalBIAS->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StalBIAS);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 685, 25));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QStringLiteral("menuFIle"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        StalBIAS->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StalBIAS);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StalBIAS->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StalBIAS);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StalBIAS->setStatusBar(statusBar);

        menuBar->addAction(menuFIle->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFIle->addAction(actionLoad_CSV);
        menuHelp->addAction(actionDebug_Mode);
        menuHelp->addAction(actionAbout);

        retranslateUi(StalBIAS);

        QMetaObject::connectSlotsByName(StalBIAS);
    } // setupUi

    void retranslateUi(QMainWindow *StalBIAS)
    {
        StalBIAS->setWindowTitle(QApplication::translate("StalBIAS", "StalBIAS", 0));
        actionDebug_Mode->setText(QApplication::translate("StalBIAS", "Debug Mode", 0));
        actionAbout->setText(QApplication::translate("StalBIAS", "About", 0));
        actionLoad_CSV->setText(QApplication::translate("StalBIAS", "Load CSV", 0));
        menuFIle->setTitle(QApplication::translate("StalBIAS", "FIle", 0));
        menuHelp->setTitle(QApplication::translate("StalBIAS", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class StalBIAS: public Ui_StalBIAS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STALBIAS_H
