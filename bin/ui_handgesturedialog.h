/********************************************************************************
** Form generated from reading UI file 'handgesturedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDGESTUREDIALOG_H
#define UI_HANDGESTUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "stronglabel.h"

QT_BEGIN_NAMESPACE

class Ui_HandGestureDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *widget_ShowImg;
    QGridLayout *gridLayout_2;
    StrongLabel *label_CameraShow_Gray;
    QLabel *label_CameraShow;
    QSplitter *splitter;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_OpenCamera;
    QPushButton *pushButton_SnapImage;
    QPushButton *pushButton_CloseCamera;
    QPushButton *pushButton_ShowPause;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox_ShowDelay;
    QLabel *label_2;
    QComboBox *comboBox_ImageMode;
    QSplitter *splitter_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_ShowResult;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_ShowSnap;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_StartTrain;
    QPushButton *pushButton_StartGestureReg;
    QPushButton *pushButton_StartRecongnise;

    void setupUi(QDialog *HandGestureDialog)
    {
        if (HandGestureDialog->objectName().isEmpty())
            HandGestureDialog->setObjectName(QStringLiteral("HandGestureDialog"));
        HandGestureDialog->setWindowModality(Qt::NonModal);
        HandGestureDialog->resize(970, 498);
        HandGestureDialog->setMinimumSize(QSize(200, 460));
        HandGestureDialog->setMaximumSize(QSize(970, 498));
        HandGestureDialog->setModal(false);
        horizontalLayout = new QHBoxLayout(HandGestureDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(HandGestureDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(680, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_ShowImg = new QWidget(groupBox);
        widget_ShowImg->setObjectName(QStringLiteral("widget_ShowImg"));
        widget_ShowImg->setMinimumSize(QSize(660, 280));
        widget_ShowImg->setMaximumSize(QSize(660, 280));
        gridLayout_2 = new QGridLayout(widget_ShowImg);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_CameraShow_Gray = new StrongLabel(widget_ShowImg);
        label_CameraShow_Gray->setObjectName(QStringLiteral("label_CameraShow_Gray"));
        label_CameraShow_Gray->setEnabled(true);
        label_CameraShow_Gray->setMinimumSize(QSize(320, 240));
        label_CameraShow_Gray->setMaximumSize(QSize(320, 240));

        gridLayout_2->addWidget(label_CameraShow_Gray, 0, 1, 1, 1);

        label_CameraShow = new QLabel(widget_ShowImg);
        label_CameraShow->setObjectName(QStringLiteral("label_CameraShow"));
        label_CameraShow->setEnabled(true);
        label_CameraShow->setMinimumSize(QSize(320, 240));
        label_CameraShow->setMaximumSize(QSize(320, 240));

        gridLayout_2->addWidget(label_CameraShow, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_ShowImg);

        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_OpenCamera = new QPushButton(groupBox_2);
        pushButton_OpenCamera->setObjectName(QStringLiteral("pushButton_OpenCamera"));

        gridLayout_3->addWidget(pushButton_OpenCamera, 0, 0, 1, 1);

        pushButton_SnapImage = new QPushButton(groupBox_2);
        pushButton_SnapImage->setObjectName(QStringLiteral("pushButton_SnapImage"));

        gridLayout_3->addWidget(pushButton_SnapImage, 0, 1, 1, 1);

        pushButton_CloseCamera = new QPushButton(groupBox_2);
        pushButton_CloseCamera->setObjectName(QStringLiteral("pushButton_CloseCamera"));

        gridLayout_3->addWidget(pushButton_CloseCamera, 1, 0, 1, 1);

        pushButton_ShowPause = new QPushButton(groupBox_2);
        pushButton_ShowPause->setObjectName(QStringLiteral("pushButton_ShowPause"));

        gridLayout_3->addWidget(pushButton_ShowPause, 1, 1, 1, 1);

        splitter->addWidget(groupBox_2);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_ShowDelay = new QComboBox(groupBox_3);
        comboBox_ShowDelay->setObjectName(QStringLiteral("comboBox_ShowDelay"));

        gridLayout->addWidget(comboBox_ShowDelay, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_ImageMode = new QComboBox(groupBox_3);
        comboBox_ImageMode->setObjectName(QStringLiteral("comboBox_ImageMode"));

        gridLayout->addWidget(comboBox_ImageMode, 1, 1, 1, 1);

        splitter->addWidget(groupBox_3);

        verticalLayout->addWidget(splitter);


        horizontalLayout->addWidget(groupBox);

        splitter_3 = new QSplitter(HandGestureDialog);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        groupBox_5 = new QGroupBox(splitter_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(0, 160));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_ShowResult = new QLabel(groupBox_5);
        label_ShowResult->setObjectName(QStringLiteral("label_ShowResult"));
        label_ShowResult->setMinimumSize(QSize(200, 115));

        verticalLayout_3->addWidget(label_ShowResult);

        splitter_3->addWidget(groupBox_5);
        groupBox_6 = new QGroupBox(splitter_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(0, 160));
        verticalLayout_4 = new QVBoxLayout(groupBox_6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_ShowSnap = new QLabel(groupBox_6);
        label_ShowSnap->setObjectName(QStringLiteral("label_ShowSnap"));
        label_ShowSnap->setMinimumSize(QSize(220, 170));
        label_ShowSnap->setMaximumSize(QSize(220, 170));

        verticalLayout_4->addWidget(label_ShowSnap);

        splitter_3->addWidget(groupBox_6);
        groupBox_4 = new QGroupBox(splitter_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_StartTrain = new QPushButton(groupBox_4);
        pushButton_StartTrain->setObjectName(QStringLiteral("pushButton_StartTrain"));

        verticalLayout_2->addWidget(pushButton_StartTrain);

        pushButton_StartGestureReg = new QPushButton(groupBox_4);
        pushButton_StartGestureReg->setObjectName(QStringLiteral("pushButton_StartGestureReg"));

        verticalLayout_2->addWidget(pushButton_StartGestureReg);

        pushButton_StartRecongnise = new QPushButton(groupBox_4);
        pushButton_StartRecongnise->setObjectName(QStringLiteral("pushButton_StartRecongnise"));

        verticalLayout_2->addWidget(pushButton_StartRecongnise);

        splitter_3->addWidget(groupBox_4);

        horizontalLayout->addWidget(splitter_3);


        retranslateUi(HandGestureDialog);

        QMetaObject::connectSlotsByName(HandGestureDialog);
    } // setupUi

    void retranslateUi(QDialog *HandGestureDialog)
    {
        HandGestureDialog->setWindowTitle(QApplication::translate("HandGestureDialog", "\347\256\200\345\215\225\346\211\213\345\212\277\350\257\206\345\210\253", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("HandGestureDialog", "\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        label_CameraShow_Gray->setText(QApplication::translate("HandGestureDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">\346\221\204\345\203\217\345\244\264\347\232\204\346\230\276\347\244\272</span></p><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">\351\203\250\345\210\206</span></p></body></html>", Q_NULLPTR));
        label_CameraShow->setText(QApplication::translate("HandGestureDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">\346\221\204\345\203\217\345\244\264\347\232\204\346\230\276\347\244\272</span></p><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">\351\203\250\345\210\206</span></p></body></html>", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("HandGestureDialog", "\350\247\206\351\242\221\346\265\201\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_OpenCamera->setText(QApplication::translate("HandGestureDialog", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        pushButton_SnapImage->setText(QApplication::translate("HandGestureDialog", "\346\212\223\345\217\226\345\233\276\347\211\207", Q_NULLPTR));
        pushButton_CloseCamera->setText(QApplication::translate("HandGestureDialog", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        pushButton_ShowPause->setText(QApplication::translate("HandGestureDialog", "\346\232\202\345\201\234", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("HandGestureDialog", "\350\276\223\345\207\272\345\233\276\347\211\207\346\223\215\344\275\234", Q_NULLPTR));
        label->setText(QApplication::translate("HandGestureDialog", "\346\230\276\347\244\272\345\273\266\346\227\266", Q_NULLPTR));
        comboBox_ShowDelay->clear();
        comboBox_ShowDelay->insertItems(0, QStringList()
         << QApplication::translate("HandGestureDialog", "0ms", Q_NULLPTR)
         << QApplication::translate("HandGestureDialog", "100ms", Q_NULLPTR)
         << QApplication::translate("HandGestureDialog", "200ms", Q_NULLPTR)
         << QApplication::translate("HandGestureDialog", "300ms", Q_NULLPTR)
         << QApplication::translate("HandGestureDialog", "400ms", Q_NULLPTR)
         << QApplication::translate("HandGestureDialog", "500ms", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("HandGestureDialog", "\345\233\276\345\203\217\346\250\241\345\274\217", Q_NULLPTR));
        comboBox_ImageMode->clear();
        comboBox_ImageMode->insertItems(0, QStringList()
         << QApplication::translate("HandGestureDialog", "RGB", Q_NULLPTR)
         << QApplication::translate("HandGestureDialog", "HSV", Q_NULLPTR)
         << QApplication::translate("HandGestureDialog", "YCBCR", Q_NULLPTR)
         << QApplication::translate("HandGestureDialog", "YUV", Q_NULLPTR)
        );
        groupBox_5->setTitle(QApplication::translate("HandGestureDialog", "\350\257\206\345\210\253\347\273\223\346\236\234", Q_NULLPTR));
        label_ShowResult->setText(QApplication::translate("HandGestureDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\350\257\206\345\210\253\347\232\204\347\273\223\346\236\234</span></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\346\230\276\347\244\272\351\203\250\345\210\206</span></p></body></html>", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("HandGestureDialog", "\346\212\223\345\217\226\345\233\276\347\211\207", Q_NULLPTR));
        label_ShowSnap->setText(QApplication::translate("HandGestureDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\346\212\223\345\217\226\345\233\276\345\203\217</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\346\230\276\347\244\272</span></p></body></html>", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("HandGestureDialog", "\350\256\255\347\273\203\350\257\206\345\210\253", Q_NULLPTR));
        pushButton_StartTrain->setText(QApplication::translate("HandGestureDialog", "\345\274\200\345\247\213\350\256\255\347\273\203", Q_NULLPTR));
        pushButton_StartGestureReg->setText(QApplication::translate("HandGestureDialog", "\345\274\200\345\247\213\345\212\250\344\275\234\350\257\206\345\210\253", Q_NULLPTR));
        pushButton_StartRecongnise->setText(QApplication::translate("HandGestureDialog", "\345\274\200\345\247\213\346\211\213\345\212\277\350\257\206\345\210\253", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HandGestureDialog: public Ui_HandGestureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDGESTUREDIALOG_H
