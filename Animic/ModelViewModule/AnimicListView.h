#pragma once

#include <QListView>

class AnimicListView : public QListView
{
	Q_OBJECT

public:
	AnimicListView();
	~AnimicListView();

	void setListMode(bool);

private:

	bool mode = false; //true for main, false for stitching dialog

signals:
	

};
