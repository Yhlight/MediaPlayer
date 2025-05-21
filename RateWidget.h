#ifndef RATEWIDGET_H
#define RATEWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QVector>

class RateWidget : public QWidget
{
    friend class MainWidget;
public:
    explicit RateWidget(QWidget *parent = nullptr);
    ~RateWidget();

private:
    QBoxLayout *rateLayout;
    QVector<QPair<QString, qreal>> *rates;
    QVector<QPushButton*> *rateButtonGroup;
};

#endif // RATEWIDGET_H
