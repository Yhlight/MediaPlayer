#ifndef PROGRESSBARWIDGET_H
#define PROGRESSBARWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QProgressBar>
#include <QTime>

class ProgressBarWidget : public QWidget
{
    friend class MainWidget;
public:
    explicit ProgressBarWidget(QWidget *parent = nullptr);

    void setWidgetSpacing(int spacing = 5, int marginLeft = 0, int marginTop = 0, int marginRight = 0, int marginBottom = 0);
    void updateProgress(qint64 position, qint64 duration);
private:
    QBoxLayout *progressBarLayout;
    QProgressBar *progressBar;
};

#endif // PROGRESSBARWIDGET_H
