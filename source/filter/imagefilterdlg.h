#ifndef IMAGEFILTERDLG_H
#define IMAGEFILTERDLG_H

#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include <opencv/cvwimage.h>
#include <opencv/cxcore.h>

#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>

#include <QDialog>
#include "../video/handgesturedialog.h"

namespace Ui {
class ImageFilterDlg;
}

class HandGestureDialog;
class ImageFilterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ImageFilterDlg(QWidget *parent = 0);
    ~ImageFilterDlg();

public slots:
    void fetchImage(IplImage* img);

private slots:
    void on_horizontalSlider_B_valueChanged(int value);

    void on_horizontalSlider_R_valueChanged(int value);

    void on_horizontalSlider_G_valueChanged(int value);

private:
    Ui::ImageFilterDlg *ui;

};

#endif // IMAGEFILTERDLG_H
