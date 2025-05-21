#include "ListWidget.h"

ListWidget::ListWidget(QWidget *parent) : QWidget(parent), listLayout(new QVBoxLayout(this)), listView(new QListView(this)), mediaPathList(new QStringList()), mediaNameList(new QStringList()), index(0), prevRandomNumber(0), mediaListModel(new QStringListModel(this)), fileInfo(new QFileInfo())
{
    listView->setMovement(QListView::Static);
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listLayout->addWidget(listView);
    this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
}

ListWidget::~ListWidget()
{
    if(mediaPathList != nullptr)
    {
        delete mediaPathList;
        mediaPathList = nullptr;
    }

    if(mediaNameList != nullptr)
    {
        delete mediaNameList;
        mediaNameList = nullptr;
    }

    if(fileInfo != nullptr)
    {
        delete fileInfo;
        fileInfo = nullptr;
    }
}

void ListWidget::addMedia(const QStringList &paths)
{
    for(const QString &path : paths)
    {
        fileInfo->setFile(path);
        mediaPathList->append(path);
        mediaNameList->append(fileInfo->fileName());
    }
    mediaListModel->setStringList(*mediaNameList);
    listView->setModel(mediaListModel);
}

void ListWidget::closeEvent(QCloseEvent *event)
{
    listView->setCurrentIndex(QModelIndex(mediaListModel->index(index, 0)));
}
