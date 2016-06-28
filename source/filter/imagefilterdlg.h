#ifndef IMAGEFILTERDLG_H
#define IMAGEFILTERDLG_H

#include <QDialog>

namespace Ui {
class ImageFilterDlg;
}

class ImageFilterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ImageFilterDlg(QWidget *parent = 0);
    ~ImageFilterDlg();

private:
    Ui::ImageFilterDlg *ui;
};

#endif // IMAGEFILTERDLG_H
