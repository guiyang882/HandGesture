#include "imagefilterdlg.h"
#include "ui_imagefilterdlg.h"

ImageFilterDlg::ImageFilterDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageFilterDlg)
{
    ui->setupUi(this);
}

ImageFilterDlg::~ImageFilterDlg()
{
    delete ui;
}

void ImageFilterDlg::fetchImage(IplImage *img) {
    QImage image;
    HandGestureDialog::IplImage2QImage(img, image);

    image = image.scaled(320,240);
    ui->label_threshold->setPixmap(QPixmap::fromImage(image));
}

void ImageFilterDlg::on_horizontalSlider_B_valueChanged(int value)
{

}

void ImageFilterDlg::on_horizontalSlider_R_valueChanged(int value)
{

}

void ImageFilterDlg::on_horizontalSlider_G_valueChanged(int value)
{

}
