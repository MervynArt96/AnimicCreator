#include "stdafx.h"
#include "TwoWayTrigger.h"

TwoWayTrigger::TwoWayTrigger(QObject *parent)
{
	playList = new QMediaPlaylist();
	player = new QMediaPlayer();

	player->setPlaylist(playList);
}

TwoWayTrigger::~TwoWayTrigger()
{

}
