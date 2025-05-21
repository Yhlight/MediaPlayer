#include "ButtonWidget.h"

ButtonWidget::ButtonWidget(QWidget *parent) : QWidget(parent) , buttonLayout(new QHBoxLayout(this)) , prevButton(new QPushButton(this)) , nextButton(new QPushButton(this)) , playButton(new QPushButton(this)) , playMode(new QPushButton(this)) , volumeButton(new QPushButton(this)), rateButton(new QPushButton(this)), playList(new QPushButton(this)), fullScene(new QPushButton(this))
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    prevButton->setFixedSize(40, 40);
    nextButton->setFixedSize(40, 40);
    playButton->setFixedSize(40, 40);
    playMode->setFixedSize(40, 40);
    volumeButton->setFixedSize(40, 40);
    rateButton->setFixedSize(40, 40);
    playList->setFixedSize(40, 40);
    fullScene->setFixedSize(40, 40);
    prevButton->setIcon(QIcon(":/prev.png"));
    nextButton->setIcon(QIcon(":/next.png"));
    playButton->setIcon(QIcon(":/play.png"));
    playMode->setIcon(QIcon(":/line.png"));
    playMode->setObjectName("line");
    volumeButton->setIcon(QIcon(":/volume.png"));
    rateButton->setIcon(QIcon(":/speed.png"));
    playList->setIcon(QIcon(":/playlist.png"));
    fullScene->setIcon(QIcon(":/fullscene.png"));
    buttonLayout->setSpacing(0);
    buttonLayout->setContentsMargins(5, 5, 5, 5);
    buttonLayout->addWidget(prevButton);
    buttonLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(nextButton);
    buttonLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(playButton);
    buttonLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(playMode);
    buttonLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(volumeButton);
    buttonLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(rateButton);
    buttonLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(playList);
    buttonLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(fullScene);
}

void ButtonWidget::setButtonSize(int w, int h)
{
    prevButton->setFixedSize(w, h);
    nextButton->setFixedSize(w, h);
    playButton->setFixedSize(w, h);
    playMode->setFixedSize(w, h);
    volumeButton->setFixedSize(w, h);
    rateButton->setFixedSize(w, h);
    playList->setFixedSize(w, h);
    fullScene->setFixedSize(w, h);
}

void ButtonWidget::setWidgetSpacing(int spacing, int marginLeft, int marginTop, int marginRight, int marginBottom)
{
    buttonLayout->setSpacing(spacing);
    buttonLayout->setContentsMargins(marginLeft, marginTop, marginRight, marginBottom);
}
