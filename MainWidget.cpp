#include "MainWidget.h"
#include "MediaWidget.h"
#include "ButtonWidget.h"
#include "ProgressBarWidget.h"
#include "VolumeWidget.h"
#include "ListWidget.h"
#include "RateWidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) , mainLayout(new QVBoxLayout(this))
{
    this->setBaseSize(800, 600);
    this->setMinimumSize(800, 600);
    this->setWindowTitle("荧火光");
    this->setAcceptDrops(true);
    MediaWidget *mediaWidget = new MediaWidget(this);
    ProgressBarWidget *progressBarWidget = new ProgressBarWidget(this);
    ButtonWidget *buttonWidget = new ButtonWidget(this);
    VolumeWidget *volumeWidget = new VolumeWidget(this);
    ListWidget *listWidget = new ListWidget(this);
    RateWidget *rateWidget = new RateWidget(this);
    mainLayout->addWidget(mediaWidget);
    mainLayout->addWidget(progressBarWidget);
    mainLayout->addWidget(buttonWidget);

    QObject::connect(buttonWidget->prevButton, &QPushButton::clicked, [buttonWidget, listWidget, mediaWidget]() {
        if (listWidget->mediaPathList->isEmpty()) return;

        int newIndex = 0;
        if(buttonWidget->playMode->objectName() == "random")
        {
            QRandomGenerator *random = QRandomGenerator::global();
            newIndex = random->bounded(0, listWidget->mediaPathList->length());
            while(listWidget->prevRandomNumber == newIndex)
            {
                newIndex = random->bounded(0, listWidget->mediaPathList->length());
            }
            listWidget->prevRandomNumber = newIndex;
        }
        else
        {
            newIndex = listWidget->index - 1;
            if (newIndex < 0)
            {
                newIndex = listWidget->mediaPathList->size() - 1;
            }
        }
        listWidget->index = newIndex;
        listWidget->listView->setCurrentIndex(QModelIndex(listWidget->mediaListModel->index(newIndex, 0)));
        mediaWidget->media->setSource(QUrl::fromLocalFile(listWidget->mediaPathList->at(newIndex)));
        mediaWidget->media->play();
    });

    QObject::connect(buttonWidget->nextButton, &QPushButton::clicked, [buttonWidget, listWidget, mediaWidget]() {
        if (listWidget->mediaPathList->isEmpty()) return;

        int newIndex = 0;
        if(buttonWidget->playMode->objectName() == "random")
        {
            QRandomGenerator *random = QRandomGenerator::global();
            newIndex = random->bounded(0, listWidget->mediaPathList->length());
            while(listWidget->prevRandomNumber == newIndex)
            {
                newIndex = random->bounded(0, listWidget->mediaPathList->length());
            }
            listWidget->prevRandomNumber = newIndex;
        }
        else
        {
            newIndex = listWidget->index + 1;
            if (newIndex >= listWidget->mediaPathList->size())
            {
                newIndex = 0;
            }
        }
        listWidget->index = newIndex;
        listWidget->listView->setCurrentIndex(QModelIndex(listWidget->mediaListModel->index(newIndex, 0)));
        mediaWidget->media->setSource(QUrl::fromLocalFile(listWidget->mediaPathList->at(newIndex)));
        mediaWidget->media->play();
    });

    QObject::connect(buttonWidget->playButton, &QPushButton::clicked, [mediaWidget, buttonWidget]() {
        if(mediaWidget->media->isPlaying())
        {
            mediaWidget->media->pause();
            buttonWidget->playButton->setIcon(QIcon(":/stop.png"));
        } else
        {
            mediaWidget->media->play();
            buttonWidget->playButton->setIcon(QIcon(":/play.png"));
        }
    });

    QObject::connect(buttonWidget->playMode, &QPushButton::clicked, [buttonWidget, mediaWidget]() {
        if(buttonWidget->playMode->objectName() == "line")
        {
            buttonWidget->playMode->setIcon(QIcon(":/random.png"));
            buttonWidget->playMode->setObjectName("random");
        }
        else if(buttonWidget->playMode->objectName() == "random")
        {
            buttonWidget->playMode->setIcon(QIcon(":/loop.png"));
            buttonWidget->playMode->setObjectName("loop");
        }
        else
        {
            buttonWidget->playMode->setIcon(QIcon(":/line.png"));
            buttonWidget->playMode->setObjectName("line");
        }
    });

    QObject::connect(mediaWidget->media, &QMediaPlayer::durationChanged, [progressBarWidget](qint64 duration) {
        if(duration / 1000 > 3600)
        {
            progressBarWidget->progressBar->setFormat("00:00:00 / " + QTime(0, 0).addMSecs(duration).toString("hh:mm:ss"));
        }
        else
        {
            progressBarWidget->progressBar->setFormat("00:00 / " + QTime(0, 0).addMSecs(duration).toString("mm:ss"));
        }
        progressBarWidget->progressBar->setRange(0, duration / 1000);
        progressBarWidget->progressBar->setValue(0);
    });

    QObject::connect(mediaWidget->media, &QMediaPlayer::positionChanged, [mediaWidget, progressBarWidget](qint64 position) {
        progressBarWidget->updateProgress(position, mediaWidget->media->duration());
    });

    QObject::connect(mediaWidget->media, &QMediaPlayer::mediaStatusChanged, [mediaWidget, buttonWidget](QMediaPlayer::MediaStatus status) {
        // if(buttonWidget->playMode->objectName() == "line" && status == QMediaPlayer::EndOfMedia)
        // {
        //     buttonWidget->nextButton->click();
        //     mediaWidget->media->play();
        // }
        // else if(buttonWidget->playMode->objectName() == "random" && status == QMediaPlayer::EndOfMedia)
        // {
        //     buttonWidget->nextButton->click();
        //     mediaWidget->media->play();
        // }
        if(buttonWidget->playMode->objectName() == "loop" && status == QMediaPlayer::EndOfMedia)
        {
            mediaWidget->media->play();
        }
    });

    QObject::connect(buttonWidget->volumeButton, &QPushButton::clicked, [buttonWidget, volumeWidget]() {
        int volumeButtonWidth = buttonWidget->volumeButton->width();

        int volumeWidgetWidth = volumeWidget->width();
        int volumeWidgetHeight = volumeWidget->height();
        QPoint point = buttonWidget->volumeButton->mapToGlobal(QPoint(volumeButtonWidth / 2, 0));
        int moveX = point.x() - volumeWidgetWidth / 2;
        int moveY = point.y() - volumeWidgetHeight - 5;
        volumeWidget->move(moveX, moveY);
        volumeWidget->isHidden() ? volumeWidget->show() : volumeWidget->hide();
    });

    QObject::connect(volumeWidget->volumeSlider, &QSlider::valueChanged, [mediaWidget, volumeWidget]() {
        mediaWidget->audio->setVolume(volumeWidget->volumeSlider->value() / 100.0);
    });

    QObject::connect(buttonWidget->rateButton, &QPushButton::clicked, [buttonWidget, rateWidget]() {
        int rateButtonWidth = buttonWidget->rateButton->width();

        int rateWidgetWidth = rateWidget->width();
        int rateWidgetHeight = rateWidget->height();
        QPoint point = buttonWidget->rateButton->mapToGlobal(QPoint(rateButtonWidth / 2, 0));
        int moveX = point.x() - rateWidgetWidth / 2;
        int moveY = point.y() - rateWidgetHeight - 5;
        rateWidget->move(moveX, moveY);
        rateWidget->isHidden() ? rateWidget->show() : rateWidget->hide();
    });

    for(int i = 0;i < rateWidget->rateButtonGroup->length();i++)
    {
        QObject::connect(rateWidget->rateButtonGroup->at(i), &QPushButton::clicked, [i, mediaWidget, rateWidget]() {
            mediaWidget->media->setPlaybackRate(rateWidget->rates->at(i).second);
        });
    }

    QObject::connect(buttonWidget->playList, &QPushButton::clicked, [mediaWidget, listWidget]() {
        int listWidgetWidth = 0.3 * mediaWidget->width();
        int listWidgetHeight = mediaWidget->height();
        listWidget->setFixedSize(listWidgetWidth, listWidgetHeight);
        QPoint point = mediaWidget->mapToGlobal(QPoint(mediaWidget->width(), 0));
        listWidget->move(point.x() - listWidgetWidth, point.y());
        listWidget->isHidden() ? listWidget->show() : listWidget->hide();
    });

    QObject::connect(listWidget->listView, &QListView::doubleClicked, [listWidget, mediaWidget](const QModelIndex value) {
        mediaWidget->media->setSource(QUrl::fromLocalFile(listWidget->mediaPathList->at(value.row())));
        listWidget->index = value.row();
        mediaWidget->media->play();
    });

    QObject::connect(buttonWidget->fullScene, &QPushButton::clicked, [mediaWidget]() {
        mediaWidget->video->setFullScreen(true);
    });

    QObject::connect(this, &MainWidget::filesDropped, [mediaWidget, listWidget](const QStringList& filePaths) {
        QStringList filteredPaths;
        const QStringList supportedFormats = {"mp3", "mp4", "avi", "mkv", "wav"};
        for (const QString& path : filePaths)
        {
            QFileInfo fileInfo(path);
            if (supportedFormats.contains(fileInfo.suffix().toLower()) && !listWidget->mediaPathList->contains(path))
            {
                filteredPaths.append(path);
            }
        }
        if (!filteredPaths.isEmpty())
        {
            listWidget->addMedia(filteredPaths);
            mediaWidget->media->setSource(QUrl::fromLocalFile(filteredPaths.first()));
            listWidget->index = 0;
            listWidget->listView->setCurrentIndex(QModelIndex(listWidget->mediaListModel->index(listWidget->mediaPathList->indexOf(mediaWidget->media->source().toLocalFile()), 0)));
            mediaWidget->media->play();
        }
    });
}

void MainWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
    else
    {
        event->ignore();
    }
}

void MainWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasUrls())
    {
        QList<QUrl> urlList = event->mimeData()->urls();
        QStringList filePaths;
        for (const QUrl &url : std::as_const(urlList))
        {
            filePaths.append(url.toLocalFile());
        }
        emit filesDropped(filePaths);
    }
}
