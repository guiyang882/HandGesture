/********************************************************************************
** Form generated from reading UI file 'threshold.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLD_H
#define UI_THRESHOLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Threshold
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboBox_algorithm;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBox_type;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *horizontalSlider_thresholdvalue;

    void setupUi(QWidget *Threshold)
    {
        if (Threshold->objectName().isEmpty())
            Threshold->setObjectName(QStringLiteral("Threshold"));
        Threshold->resize(400, 120);
        verticalLayout = new QVBoxLayout(Threshold);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(Threshold);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(140, 16777215));

        horizontalLayout->addWidget(label_3);

        comboBox_algorithm = new QComboBox(Threshold);
        comboBox_algorithm->setObjectName(QStringLiteral("comboBox_algorithm"));

        horizontalLayout->addWidget(comboBox_algorithm);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(Threshold);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(140, 0));
        label->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_3->addWidget(label);

        comboBox_type = new QComboBox(Threshold);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        horizontalLayout_3->addWidget(comboBox_type);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Threshold);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(140, 0));

        horizontalLayout_2->addWidget(label_2);

        horizontalSlider_thresholdvalue = new QSlider(Threshold);
        horizontalSlider_thresholdvalue->setObjectName(QStringLiteral("horizontalSlider_thresholdvalue"));
        horizontalSlider_thresholdvalue->setMaximum(255);
        horizontalSlider_thresholdvalue->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_thresholdvalue);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Threshold);

        QMetaObject::connectSlotsByName(Threshold);
    } // setupUi

    void retranslateUi(QWidget *Threshold)
    {
        Threshold->setWindowTitle(QApplication::translate("Threshold", "Threshold", Q_NULLPTR));
        label_3->setText(QApplication::translate("Threshold", "Threshold Algorithm", Q_NULLPTR));
        comboBox_algorithm->clear();
        comboBox_algorithm->insertItems(0, QStringList()
         << QApplication::translate("Threshold", "Basic", Q_NULLPTR)
         << QApplication::translate("Threshold", "Adaptive", Q_NULLPTR)
         << QApplication::translate("Threshold", "Watershed", Q_NULLPTR)
        );
        label->setText(QApplication::translate("Threshold", "Threshold Type", Q_NULLPTR));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("Threshold", "THRESH_BINARY", Q_NULLPTR)
         << QApplication::translate("Threshold", "THRESH_BINARY_INV", Q_NULLPTR)
         << QApplication::translate("Threshold", "THRESH_TRUNC", Q_NULLPTR)
         << QApplication::translate("Threshold", "THRESH_TOZERO", Q_NULLPTR)
         << QApplication::translate("Threshold", "THRESH_TOZERO_INV", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Threshold", "Threshold Value", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Threshold: public Ui_Threshold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLD_H
