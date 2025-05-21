#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QListView>
#include <QStringList>
#include <QStringListModel>
#include <QFileInfo>
#include <QModelIndex>
#include <QCloseEvent>

class ListWidget : public QWidget
{
    friend class MainWidget;
public:
    explicit ListWidget(QWidget *parent = nullptr);
    ~ListWidget();
    void addMedia(const QStringList &paths);

    void closeEvent(QCloseEvent *event) override;
private:
    QLayout *listLayout;
    QListView *listView;
    QStringList *mediaPathList;
    QStringList *mediaNameList;
    int index;
    int prevRandomNumber;
    QStringListModel *mediaListModel;
    QFileInfo *fileInfo;
};

#endif // LISTWIDGET_H
