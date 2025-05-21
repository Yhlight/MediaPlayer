#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QIcon>

class ButtonWidget : public QWidget
{
    friend class MainWidget;
    Q_OBJECT
public:
    explicit ButtonWidget(QWidget *parent = nullptr);

    void setButtonSize(int w = 40, int h = 40);
    void setWidgetSpacing(int spacing = 5, int marginLeft = 0, int marginTop = 0, int marginRight = 0, int marginBottom = 0);

private:
    QBoxLayout* buttonLayout;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QPushButton *playButton;
    QPushButton *playMode;
    QPushButton *volumeButton;
    QPushButton *rateButton;
    QPushButton *playList;
    QPushButton *fullScene;
};

#endif // BUTTONWIDGET_H
