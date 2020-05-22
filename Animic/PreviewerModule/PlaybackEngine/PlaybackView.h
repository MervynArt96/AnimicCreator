#pragma once

#include <QGraphicsView>

class PlaybackView : public QGraphicsView
{
	Q_OBJECT

public:
	PlaybackView(QObject *parent);
	~PlaybackView();
};
