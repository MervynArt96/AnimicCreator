#pragma once
#include <QGraphicsVideoItem>

class VideoObject : public QGraphicsVideoItem
{
	Q_OBJECT

public:
	VideoObject(QObject *parent, QUrl);
	~VideoObject();

	QUrl getVideoPath();

private:

	QUrl videoPath;

	
public slots:

	//void onScrubEnter();
	//void onScrubExit();

	//void onFocused();
	//void onFocusExit();

	//void onDurationChanged();
	//void onSourceChanged();

};