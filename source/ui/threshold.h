#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <QWidget>

namespace Ui {
class Threshold;
}

class Threshold : public QWidget
{
    Q_OBJECT

public:
    explicit Threshold(QWidget *parent = 0);
    ~Threshold();

private slots:
    void on_comboBox_algorithm_currentIndexChanged(int index);

    void on_comboBox_type_currentIndexChanged(int index);

    void on_horizontalSlider_thresholdvalue_valueChanged(int value);

private:
    Ui::Threshold *ui;
};

#endif // THRESHOLD_H
