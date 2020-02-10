#pragma once

#include <QWidget>

class Timeline : public QWidget
{
	Q_OBJECT

public:
	Timeline(QWidget *parent);
	~Timeline();


private:

	//playHead
	//markers
	//trackModel?
	//layer objects

signals:

	void seeked();
	

public slots:

	void onSeeked();


};
