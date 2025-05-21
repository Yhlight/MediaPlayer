#ifndef VOLUMEWIDGET_H
#define VOLUMEWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QSlider>

class VolumeWidget : public QWidget
{
    friend class MainWidget;
public:
    explicit VolumeWidget(QWidget *parent = nullptr);

    void setVolumeSize(int w = 20, int h = 80);
    void setVolumeRange(int min = 0, int max = 100);
    void setVolumeValue(int value = 20);
    void setWidgetSpacing(int spacing = 0, int marginLeft = 0, int marginTop = 0, int marginRight = 0, int marginBottom = 0);
private:
    QBoxLayout *volumeLayout;
    QSlider *volumeSlider;
};

#endif // VOLUMEWIDGET_H
