#pragma once

#include <QGraphicsVideoItem>

class TimedMashTrigger : public QGraphicsVideoItem
{
	Q_OBJECT

public:
	TimedMashTrigger(QObject *parent);
	~TimedMashTrigger();
};
