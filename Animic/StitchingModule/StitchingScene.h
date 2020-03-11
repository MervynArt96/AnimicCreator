#pragma once

#include <QGraphicsScene>

enum SceneType
{
	AutoScene,
	SingleButtonScene,
	MashButtonScene,
	HoldButtonScene,
	TimeLimitedScene,
	TwoWayScene,
	MultiWayScene
};


class StitchingScene : public QGraphicsScene
{
	Q_OBJECT

public:
	StitchingScene();
	~StitchingScene();
};
