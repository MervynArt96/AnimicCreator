#pragma once

#include <QWidget>
#include "TimelineModule/TimelineItemModel.h"

class Timeline : public QWidget
{
	Q_OBJECT

public:
	Timeline(QWidget *parent);
	~Timeline();


private:

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
