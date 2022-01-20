#include "musicplayer.h"
#include "ui_musicplayer.h"

MusicPlayer::MusicPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer();
    m_playlist = new QMediaPlaylist();
    m_player->setPlaylist(m_playlist);
    connect(ui->b_find, &QPushButton::clicked, this, &MusicPlayer::findSong);
    connect(ui->b_playPause, &QPushButton::clicked, this, &MusicPlayer::playSong);
    connect(ui->s_volume, &QSlider::valueChanged, m_player, &QMediaPlayer::setVolume);
    connect(m_player, &QMediaPlayer::volumeChanged, this, &MusicPlayer::showVolume);
    connect(m_player, &QMediaPlayer::currentMediaChanged, this, &MusicPlayer::showNewSong);
    connect(ui->b_forward, &QPushButton::clicked, m_playlist, &QMediaPlaylist::next);
    connect(ui->b_exit, &QPushButton::clicked, this, &MusicPlayer::close);
}

MusicPlayer::~MusicPlayer()
{
    delete ui;
}

void MusicPlayer::findSong()
{
    QString songPath = QFileDialog::getOpenFileName(this, tr("CHoose Music"),QDir::homePath(),tr("Music(*.mp3)"));
    ui->l_songName->setText(songPath);
    m_playlist->addMedia(QUrl::fromLocalFile(songPath));
    m_playlist->setCurrentIndex(1);
}

void MusicPlayer::playSong()
{
  m_player->play();
  ui->b_playPause->setText("||");
  disconnect(ui->b_playPause, &QPushButton::clicked, this, &MusicPlayer::playSong);
  connect(ui->b_playPause, &QPushButton::clicked, this, &MusicPlayer::pause);
}

void MusicPlayer::pause()
{
   m_player->pause();
   ui->b_playPause->setText(">");
   disconnect(ui->b_playPause, &QPushButton::clicked, this, &MusicPlayer::pause);
   connect(ui->b_playPause, &QPushButton::clicked, this, &MusicPlayer::playSong);
}

void MusicPlayer::showVolume(int volume)
{
    ui->label->setNum(volume);
}

void MusicPlayer::showNewSong(QMediaContent content)
{
    QString path  = content.request().url().toString();
    ui->l_songName->setText(path);
}

