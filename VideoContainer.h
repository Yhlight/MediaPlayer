#ifndef VIDEOCONTAINER_H
#define VIDEOCONTAINER_H

#include <QVideoWidget>
#include <QDragEnterEvent>
#include <QDropEvent>

class VideoContainer : public QVideoWidget
{
    Q_OBJECT
public:
    explicit VideoContainer(QWidget *parent = nullptr);

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // VIDEOCONTAINER_H
