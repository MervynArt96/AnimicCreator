#pragma once

#include <CanvasModule\AnimicScene.h>
#include <QTimer>
#include <QtCore\qeventloop.h>

class PlaybackEngineCore : public QObject
{
	Q_OBJECT

public:

	PlaybackEngineCore();
	PlaybackEngineCore(QList<AnimicScene*>);
	~PlaybackEngineCore();

	void refreshList(QList<AnimicScene*>);
	void setList(QList<AnimicScene*>);
	QList<AnimicScene*> getList();
	void playback();

	AnimicScene* findEntryScene();

private:

	QList<AnimicScene*> sceneList;
	QTimer* timer;
	QEventLoop* loop;

signals:

	void playNextScene(AnimicScene*);
	void terminatePreview();

public slots:

	void onNextScene(AnimicScene*);
	void onTerminate();

};

