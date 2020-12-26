#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTime>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);       //кнопка "закрыть"

    QPixmap gif(":/img/кубик.gif");
    ui->label->setPixmap(gif);
    qsrand(QTime::currentTime().msecsSinceStartOfDay());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    ui->playButton->setEnabled(false);
    player->setPlaylist(playlist);                                  // Установка плейлиста в аудио плеер
    playlist->addMedia(QUrl("qrc:/audio/звук.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);     // проигрывать один раз
    player->play();

    ui->label->setMovie(movie);
    ui->label->show();
    movie->start();

    ui->label->setMovie(movie);
    ui->label->show();
    movie->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));     // посылает сигнал в ф-ию onTimeout()
    timer->start(706);                                              // генерирует сигнал через заданное время, точно указать время окончания звука
}

void MainWindow::onTimeout()
{
    ui->playButton->setEnabled(true);

    movie->stop();
    timer->stop();

    qsrand(QTime::currentTime().msecsSinceStartOfDay());
    int rand = 1 + qrand() % 6;

    QPixmap pix1(":/img/1.jpg");
    QPixmap pix2(":/img/2.jpg");
    QPixmap pix3(":/img/3.jpg");
    QPixmap pix4(":/img/4.jpg");
    QPixmap pix5(":/img/5.jpg");
    QPixmap pix6(":/img/6.jpg");

    switch(rand)
    {
        case 1:
            ui->label->setPixmap(pix1);
            break;
        case 2:
            ui->label->setPixmap(pix2);
            break;
        case 3:
            ui->label->setPixmap(pix3);
            break;
        case 4:
            ui->label->setPixmap(pix4);
            break;
        case 5:
            ui->label->setPixmap(pix5);
            break;
        case 6:
            ui->label->setPixmap(pix6);
            break;
    }
}
