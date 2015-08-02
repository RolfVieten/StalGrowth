/********************************************************************************
** Form generated from reading UI file 'customseason.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMSEASON_H
#define UI_CUSTOMSEASON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CustomSeason
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *title;
    QLabel *startl;
    QDateEdit *start;
    QLabel *Endl;
    QDateEdit *end;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CustomSeason)
    {
        if (CustomSeason->objectName().isEmpty())
            CustomSeason->setObjectName(QStringLiteral("CustomSeason"));
        CustomSeason->resize(496, 219);
        verticalLayout = new QVBoxLayout(CustomSeason);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        title = new QLabel(CustomSeason);
        title->setObjectName(QStringLiteral("title"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, title);

        startl = new QLabel(CustomSeason);
        startl->setObjectName(QStringLiteral("startl"));

        formLayout->setWidget(1, QFormLayout::LabelRole, startl);

        start = new QDateEdit(CustomSeason);
        start->setObjectName(QStringLiteral("start"));

        formLayout->setWidget(1, QFormLayout::FieldRole, start);

        Endl = new QLabel(CustomSeason);
        Endl->setObjectName(QStringLiteral("Endl"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Endl);

        end = new QDateEdit(CustomSeason);
        end->setObjectName(QStringLiteral("end"));

        formLayout->setWidget(2, QFormLayout::FieldRole, end);


        verticalLayout->addLayout(formLayout);

        label = new QLabel(CustomSeason);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(CustomSeason);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CustomSeason);
        QObject::connect(buttonBox, SIGNAL(accepted()), CustomSeason, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CustomSeason, SLOT(reject()));

        QMetaObject::connectSlotsByName(CustomSeason);
    } // setupUi

    void retranslateUi(QDialog *CustomSeason)
    {
        CustomSeason->setWindowTitle(QApplication::translate("CustomSeason", "Dialog", 0));
        title->setText(QApplication::translate("CustomSeason", "Slow Growth Season Setup", 0));
        startl->setText(QApplication::translate("CustomSeason", "Start season", 0));
        Endl->setText(QApplication::translate("CustomSeason", "End season", 0));
        label->setText(QApplication::translate("CustomSeason", "<html><head/><body><p><span style=\" color:#ff0000;\">Start season date must be before end season date</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class CustomSeason: public Ui_CustomSeason {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMSEASON_H
