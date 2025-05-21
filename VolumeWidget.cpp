#include "VolumeWidget.h"

VolumeWidget::VolumeWidget(QWidget *parent) : QWidget(parent) , volumeLayout(new QVBoxLayout(this)) , volumeSlider(new QSlider(this))
{
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(40);
    volumeSlider->setFixedSize(20, 80);
    volumeLayout->setSpacing(0);
    volumeLayout->setContentsMargins(0, 0, 0, 0);
    volumeLayout->addWidget(volumeSlider);
    this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->show();
    this->hide();
}

void VolumeWidget::setVolumeSize(int w, int h)
{
    volumeSlider->setFixedSize(w, h);
}

void VolumeWidget::setVolumeRange(int min, int max)
{
    volumeSlider->setRange(min, max);
}

void VolumeWidget::setVolumeValue(int value)
{
    volumeSlider->setValue(value);
}

void VolumeWidget::setWidgetSpacing(int spacing, int marginLeft, int marginTop, int marginRight, int marginBottom)
{
    volumeLayout->setSpacing(spacing);
    volumeLayout->setContentsMargins(marginLeft, marginTop, marginRight, marginBottom);
}
