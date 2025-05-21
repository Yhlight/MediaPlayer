#include "ProgressBarWidget.h"

ProgressBarWidget::ProgressBarWidget(QWidget *parent) : QWidget(parent) , progressBarLayout(new QVBoxLayout(this)) , progressBar(new QProgressBar(this))
{
    progressBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    progressBar->setFixedHeight(20);
    progressBar->setRange(0, 1);
    progressBar->setValue(0);
    progressBar->setFormat("00:00 / 00:00");
    progressBarLayout->addWidget(progressBar);
}

void ProgressBarWidget::setWidgetSpacing(int spacing, int marginLeft, int marginTop, int marginRight, int marginBottom)
{
    progressBarLayout->setSpacing(spacing);
    progressBarLayout->setContentsMargins(marginLeft, marginTop, marginRight, marginBottom);
}

void ProgressBarWidget::updateProgress(qint64 position, qint64 duration)
{
    QString currentTime;
    QString totalTime;
    if(duration / 1000 > 3600)
    {
        currentTime = QTime(0, 0).addMSecs(position).toString("hh:mm:ss");
        totalTime = QTime(0, 0).addMSecs(duration).toString("hh:mm:ss");
    }
    else
    {
        currentTime = QTime(0, 0).addMSecs(position).toString("mm:ss");
        totalTime = QTime(0, 0).addMSecs(duration).toString("mm:ss");
    }
    progressBar->setFormat(currentTime + " / " + totalTime);
    progressBar->setValue(position / 1000);
}
