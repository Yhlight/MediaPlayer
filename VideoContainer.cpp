#include "VideoContainer.h"

VideoContainer::VideoContainer(QWidget *parent) : QVideoWidget(parent)
{
    this->setAcceptDrops(false);
}

void VideoContainer::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(this->isFullScreen())
    {
        this->setFullScreen(false);
    }
    else
    {
        this->setFullScreen(true);
    }
}

void VideoContainer::dragEnterEvent(QDragEnterEvent *event) {}
void VideoContainer::dropEvent(QDropEvent *event) {}
