#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QDir>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class MusicPlayer; }
QT_END_NAMESPACE

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();
private slots:
    void findSong();
    void playSong();
    void pause();
    void showVolume(int volume);
    //void showNewSong(QMediaContent content);

private:
    QMediaPlayer *m_player;
    QMediaPlaylist *m_playlist;
    Ui::MusicPlayer *ui;
};
#endif // MUSICPLAYER_H
