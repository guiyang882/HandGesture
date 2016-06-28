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
