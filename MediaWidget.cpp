#include "MediaWidget.h"

MediaWidget::MediaWidget(QWidget *parent) : QWidget(parent) , videoLayout(new QVBoxLayout(this)) , media(new QMediaPlayer(this)) , audio(new QAudioOutput(this)) , video(new VideoContainer(this))
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    audio->setVolume(0.4);
    video->setAspectRatioMode(Qt::KeepAspectRatio);
    media->setAudioOutput(audio);
    media->setVideoOutput(video);
    videoLayout->setSpacing(0);
    videoLayout->setContentsMargins(5, 5, 5, 5);
    videoLayout->addWidget(video);
}

MediaWidget::MediaWidget(QWidget *parent, const QString& fileName) : QWidget(parent) , videoLayout(new QVBoxLayout(this)) , media(new QMediaPlayer(this)) , audio(new QAudioOutput(this)) , video(new VideoContainer(this))
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    audio->setVolume(0.4);
    video->setAspectRatioMode(Qt::KeepAspectRatio);
    media->setAudioOutput(audio);
    media->setVideoOutput(video);
    media->setSource(QUrl::fromLocalFile(fileName));
    videoLayout->setSpacing(0);
    videoLayout->setContentsMargins(5, 5, 5, 5);
    videoLayout->addWidget(video);
}

void MediaWidget::setMediaFile(const QString& mediaFile)
{
    media->setSource(QUrl::fromLocalFile(mediaFile));
}

void MediaWidget::setMediaVolume(double volume)
{
    audio->setVolume(volume);
}

void MediaWidget::setMediaAspectRatiMode(Qt::AspectRatioMode mode)
{
    video->setAspectRatioMode(mode);
}

void MediaWidget::setWidgetSpacing(int spacing, int marginLeft, int marginTop, int marginRight, int marginBottom)
{
    videoLayout->setSpacing(spacing);
    videoLayout->setContentsMargins(marginLeft, marginTop, marginRight, marginBottom);
}
