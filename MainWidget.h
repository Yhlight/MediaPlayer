#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QRandomGenerator>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
signals:
    void filesDropped(const QStringList &filePaths);

private:
    QBoxLayout *mainLayout;
};

#endif // MAINWIDGET_H
