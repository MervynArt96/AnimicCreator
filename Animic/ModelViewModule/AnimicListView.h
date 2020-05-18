#pragma once

#include <QListView>
#include <QModelIndex>

class AnimicListView : public QListView
{
	Q_OBJECT

public:
	AnimicListView();
	~AnimicListView();

	void setListMode(bool);
	void mousePressEvent(QMouseEvent* event) override;

private:

	bool mode = false; //true for main, false for stitching dialog

signals:
	
	void openNewSceneTab();
	void switchScene();

public slots:

	void onDoubleClicked(const QModelIndex&);
	void showContextMenu(const QPoint& pos);

	void onRenameScene();
	void onDeleteScene();

};
