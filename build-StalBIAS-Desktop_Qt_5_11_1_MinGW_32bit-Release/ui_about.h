/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(595, 497);
        verticalLayout = new QVBoxLayout(About);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(About);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(32);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        textBrowser = new QTextBrowser(About);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        pushButton = new QPushButton(About);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "Dialog", nullptr));
        label->setText(QApplication::translate("About", "StalGrowth", nullptr));
        textBrowser->setHtml(QApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<h1 style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Serif','serif'; font-size:24pt; font-weight:600; color:#000000; background-color:transparent;\">StalGrowth</span></h1>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\""
                        ">StalGrowth is a Open Source and Cross Platform program designed to calculate theoretical growth rates. It is based on physical parameters which influence carbonate precipitation rates (Cave air pCO2, Ca2+-ion-concentration, temperature, drip-rate and water-film thickness). This enables StalGrowth to untangle the complex interaction to identify and quantify seasonal growth rate changes. We use a formula by Baker et al., 1998 found in the paper</span><span style=\" color:#000000; background-color:transparent;\">\302\240</span><a href=\"http://www.sciencedirect.com/science/article/pii/S0016703797003438\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; text-decoration: underline; color:#000000; background-color:transparent;\">&quot;Testing theoretically predicted stalagmite growth rate with Recent annually laminated samples: Implications for past stalagmite deposition&quot;</span></a><span style=\" co"
                        "lor:#000000; background-color:transparent;\">\302\240</span><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\">to deduce the empirical growth of a stalagmite given certain conditions from cave monitoring observations.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<h2 style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><a name=\"user-content-features\"></a><span style=\" font-family:'Liberation Serif','serif'; font-size:18pt; f"
                        "ont-weight:600; color:#000000; background-color:transparent;\">F</span><span style=\" font-family:'Liberation Serif','serif'; font-size:18pt; font-weight:600; color:#000000; background-color:transparent;\">eatures</span></h2>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Import from CSV files</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-seri"
                        "f','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Calculation of seasonal growth averages</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Auto sorting of the data into different seasons</span> </li>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\"><li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\""
                        ">Fast growth / Slow growth (user-specified season)</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Winter / Summer ( Nominal Equinoxes)</span> </li></ul>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Graphic display of input parameters and results</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; marg"
                        "in-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Interactive date and growth-rate reader</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Student's T-testing for significance of the season growth rates</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial'"
                        ",'sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Identification of periods of no-growth or dissolution</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Estimation of seasonal growth bias</span></li></ul>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:1; text-indent:0px; line-height:115%; font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<h2 style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0p"
                        "x; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><a name=\"user-content-how-to-use\"></a><span style=\" font-family:'Liberation Serif','serif'; font-size:18pt; font-weight:600; color:#000000; background-color:transparent;\">H</span><span style=\" font-family:'Liberation Serif','serif'; font-size:18pt; font-weight:600; color:#000000; background-color:transparent;\">ow to use:</span></h2>\n"
"<ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Download using the download zip button on the right.</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px"
                        "; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Open the StalGrowth.exe in the Windows Binary Folder.</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Load your CSV via the load file button.</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont"
                        "','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">If it loaded correctly (see Input File section for more information) Press the Statistics or Graph Button on the bottom.</span></li></ol>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<h2 style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><a name=\"user-content-equations\"></a><span style=\" font-family:'Liberation Serif','serif'; font-size:18pt; font-weight:600; color:#000000; background-color:transparent;\">E</span><span style=\" font-family:'Liberation Serif','serif'; font-"
                        "size:18pt; font-weight:600; color:#000000; background-color:transparent;\">quations:</span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\">Empirical Growth Equation:</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Mono','monospace'; font-size:10pt; color:#000000; background-color:transparent;\">R0 = 1174 = 1174*(cCa - appcCa) * (FilmThickness/DripInt) *(1.0 - e^exp)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0p"
                        "x; font-family:'Liberation Mono','monospace'; font-size:10pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Mono','monospace'; font-size:10pt; color:#000000; background-color:transparent;\">Where exp:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Mono','monospace'; font-size:10pt; color:#000000; background-color:transparent;\"> </span><span style=\" font-family:'SFMono-Regular','Consolas','Liberation Mono','Menlo','monospace'; font-size:10pt; color:#000000; background-color:transparent;\">exp = (-1.0 * (alpha/FilmThickess) * DripInterval)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-righ"
                        "t:0px; -qt-block-indent:0; text-indent:0px; font-family:'SFMono-Regular','Consolas','Liberation Mono','Menlo','monospace'; font-size:10pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Mono','monospace'; font-size:10pt; color:#000000; background-color:transparent;\">Where alpha:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Mono','monospace'; font-size:10pt; color:#000000; background-color:transparent;\"> </span><span style=\" font-family:'SFMono-Regular','Consolas','Liberation Mono','Menlo','monospace'; font-size:10pt; color:#000000; background-color:transparent;\">alpha= (0.52 + (0.04*Temp) + (0.004*Temp^2)) * 10^-7;</span></p>\n"
"<p style=\"-qt-par"
                        "agraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SFMono-Regular','Consolas','Liberation Mono','Menlo','monospace'; font-size:10pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\">Apparent Calcium Concentration</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Mono','monospace'; font-size:10pt; color:#000000; background-color:transparent;\">appcCa = (5.872* pCO2^0.2526)+((-0.0167*Temp"
                        ")+1.5146)) * 0.5;</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\">Averaging, Variance, Standard Deviation use the standard formulas.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<h2 style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><a name"
                        "=\"user-content-input-file\"></a><span style=\" font-family:'Liberation Serif','serif'; font-size:18pt; font-weight:600; color:#000000; background-color:transparent;\">I</span><span style=\" font-family:'Liberation Serif','serif'; font-size:18pt; font-weight:600; color:#000000; background-color:transparent;\">nput File</span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\">The input file of this program is a CSV file with a Header, in the following format:</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Mono','monospace';"
                        " font-size:10pt; color:#000000; background-color:transparent;\">Timestamp,Drip Interval (s),Error (s),Film Thickness (m),Error (m),Temperature (degC),Error (degC),pCO2 (atm),Error (atm),cCa (mol/m3),Error (mol/m3)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><span style=\" font-family:'Liberation Mono','monospace'; font-size:10pt; color:#000000; background-color:transparent;\">04/28/2005 00:00:00,4,1,0.0001,0.00005,18.27007299,0.2,0.000669456,0.00003,2.02345153,0.01</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji'"
                        ",'Segoe UI Emoji'; font-size:12pt; color:#000000;\">Timestamp: Must be written: [MM/DD/YYYY 00:00:00] Specific time is a feature we plan on including</span></li></ul>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:1; text-indent:0px; line-height:115%; font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<h3 style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:transparent;\"><a name=\"user-content-to-do-list\"></a><span style=\" font-family:'Liberation Serif','serif'; font-size:14pt; font-weight:600; color:#000000; background-color:transparent;\">T</span><span style=\" font-family:'Liberation Serif','serif'; font-size:14pt; font-weight:600; color:#000000; background-color:transparent;\">o Do list:</"
                        "span></h3>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Export graphs as jpg, svg, tiff.</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Add additional controls to customize seasons better.</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin"
                        "-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Support for daily observations.</span> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">Bug fixes.</span></li></ul>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:1; text-indent:0px; line-height:115%; font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe"
                        " UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<hr />\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\">If anyone is interested in this proyect or would like to help, contact us!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin"
                        "-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\">Credits:</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">The AlgLib Commutiny @\302\240</span><a href=\"http://www.alglib.net/\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple C"
                        "olor Emoji','Segoe UI Emoji'; font-size:12pt; text-decoration: underline; color:#000080;\">https://www.alglib.net/</span></a> </li>\n"
"<li style=\" background-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000;\">The QT Community @\302\240</span><a href=\"http://qt-project.org/\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; text-decoration: underline; color:#000000;\">https://qt-project.org/</span></a></li>\n"
"<li style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; text-decoration: underline; color:#000000; backgr"
                        "ound-color:transparent;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%;\">Emanuel Eichhammer<span style=\" text-decoration:none;\"> for QCustomPlot @ https://www.qcustomplot.com</span></li></ul>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:1; text-indent:0px; line-height:115%; font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:transparent;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><span style=\" font-family:'-apple-system','BlinkMacSystemFont','Segoe UI','Helvetica','Arial','sans-serif','Apple Color Emoji','Segoe UI Emoji'; font-size:12pt; color:#000000; background-color:t"
                        "ransparent;\">Thanks, Rolf &amp; Fran89.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:115%; background-color:transparent;\"><br /><br /></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("About", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
