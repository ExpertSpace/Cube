#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QMovie>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QMediaPlayer *player = new QMediaPlayer;                    // выделение памяти для плеера
    QMediaPlaylist *playlist = new QMediaPlaylist(player);      // создание плейлиста
    QTimer *timer = new QTimer();
    QMovie *movie = new QMovie(":/img/кубик.gif");

private slots:
    void on_playButton_clicked();

private:
    Ui::MainWindow *ui;

public slots:
    void onTimeout();
};
#endif // MAINWINDOW_H
