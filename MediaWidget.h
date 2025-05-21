#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "VideoContainer.h"

class MediaWidget : public QWidget
{
    friend class MainWidget;
public:
    explicit MediaWidget(QWidget *parent = nullptr);
    explicit MediaWidget(QWidget *parent, const QString& fileName);

    void setMediaFile(const QString& mediaFile);
    void setMediaVolume(double volume = 0.2);
    void setMediaAspectRatiMode(Qt::AspectRatioMode mode = Qt::KeepAspectRatio);
    void setWidgetSpacing(int spacing = 5, int marginLeft = 0, int marginTop = 0, int marginRight = 0, int marginBottom = 0);

private:
    QBoxLayout *videoLayout;
    QMediaPlayer *media;
    QAudioOutput *audio;
    VideoContainer *video;
};

#endif // MEDIAWIDGET_H
