#include "threshold.h"
#include "ui_threshold.h"

Threshold::Threshold(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Threshold)
{
    ui->setupUi(this);
}

Threshold::~Threshold()
{
    delete ui;
}

void Threshold::on_comboBox_algorithm_currentIndexChanged(int index)
{

}

void Threshold::on_comboBox_type_currentIndexChanged(int index)
{

}

void Threshold::on_horizontalSlider_thresholdvalue_valueChanged(int value)
{

}
