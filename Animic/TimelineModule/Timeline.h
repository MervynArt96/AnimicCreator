#pragma once

#include <QQuickWidget>
#include <QQuickView>
#include "TimelineModule/TimelineItemModel.h"

class Timeline : public QQuickWidget
{
	Q_OBJECT

public:
	Timeline(QWidget*);
	~Timeline();


private:

	TimelineItemModel* itemModel = new TimelineItemModel(this);

	class TimelineCommand
	{

	};

signals:

	void seeked();
	

public slots:

	void onSeeked();
	void addVideoObject();
	void addImageObject();
	void addAudioObject();
	void addDialogueObject();

};
