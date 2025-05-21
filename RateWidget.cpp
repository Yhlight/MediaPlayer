#include "RateWidget.h"

RateWidget::RateWidget(QWidget *parent) : QWidget(parent), rateLayout(new QVBoxLayout(this)), rates(new QVector<QPair<QString, qreal>>), rateButtonGroup(new QVector<QPushButton*>)
{
    *rates = {
        {"0.5x", 0.5},
        {"1.0x", 1.0},
        {"1.25x", 1.25},
        {"1.5x", 1.5},
        {"2.0x", 2.0},
    };

    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    for(auto rate : *rates)
    {
        QPushButton *button = new QPushButton(rate.first, this);
        button->setFixedSize(60, 20);
        rateButtonGroup->push_back(button);
        rateLayout->addWidget(button);
    }
    this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->show();
    this->hide();
}

RateWidget::~RateWidget()
{
    if(rates != nullptr)
    {
        delete rates;
        rates = nullptr;
    }

    if(rateButtonGroup != nullptr)
    {
        delete rateButtonGroup;
        rateButtonGroup = nullptr;
    }
}
