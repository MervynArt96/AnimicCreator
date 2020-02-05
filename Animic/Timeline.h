#pragma once

#include <QWidget>

class Timeline : public QWidget
{
	Q_OBJECT

public:
	Timeline(QWidget *parent);
	~Timeline();

signals:

	

public slots:

	void onSeeked();


};
