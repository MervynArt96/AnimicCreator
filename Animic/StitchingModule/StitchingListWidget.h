#pragma once

#include <QListWidget>

class StitchingListWidget : public QListWidget
{
	Q_OBJECT

public:
	StitchingListWidget(QWidget *parent);
	~StitchingListWidget();

	void mouseDoubleClickEvent(QMouseEvent* event);
};
