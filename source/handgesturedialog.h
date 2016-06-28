#ifndef HANDGESTUREDIALOG_H
#define HANDGESTUREDIALOG_H

#include <QDialog>
#include <iostream>
#include <QTimer>
#include <QTextCodec>

#include "gesture/GestureStruct.h"
#include "gesture/AIGesture.h"
#include "gesture/GestrueInfo.h"

using namespace std;
using namespace cv;

namespace Ui {
class HandGestureDialog;
}

class HandGestureDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit HandGestureDialog(QWidget *parent = 0);
    ~HandGestureDialog();
    void StartRecongizeHand(IplImage* img);

private slots:
    void readFarme();
    void on_pushButton_OpenCamera_clicked();
    void on_pushButton_SnapImage_clicked();
    void on_pushButton_CloseCamera_clicked();
    void on_pushButton_ShowPause_clicked();
    void on_pushButton_StartTrain_clicked();
    void on_pushButton_StartRecongnise_clicked();
    void on_comboBox_ShowDelay_activated(int index);
    void on_comboBox_ImageMode_activated(int index);

public:
    bool IplImage2QImage(IplImage* src, QImage& dest);
    bool QImage2IplImage(QImage& src, IplImage& dest);
    bool cvtImageShowMode(IplImage* src, IplImage* dest);

private:
    Ui::HandGestureDialog *ui;
    CAIGesture gesture;
    int isRun;

    /**CAMERA PARAMETER**/
    CvCapture *cam;
    IplImage  *frame;
    IplImage* afterSkin;

    /*Basic Control Setting*/
    QTimer    *timer;
    int time_intervals;

    // save current snap image
    IplImage* p_CurSnapImg;

    /**gesture Recongnisize**/
    string gesturename;
    CvRect track_window;
    CvBox2D track_box;
    CvMemStorage* storage;
    CvSeq* pt_seq;
    string result[8];
    int gesturecount;
    CvPoint2D32f center;//用来储存手势的质心
    float r;//手势的半径
    CvPoint* pt;
    string com_result;
    MyRect rect;
    IplImage* src_tmp[8];

public:
    enum Switch { Nothing,Recongnise,CommandGesture,Locate } status_switch;
    enum ImageShowMode {ISM_RGB, ISM_HSV, ISM_YCBCR, ISM_YUV} m_imgShowMode;
};

#endif // HANDGESTUREDIALOG_H
