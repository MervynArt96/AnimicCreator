#pragma once

#include <QListView>
#include <QModelIndex>
#include <CanvasModule/AnimicScene.h>
#include <ModelViewModule/SceneListModel.h>

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
	
	void openNewSceneTab(AnimicScene*, QModelIndex);
	void switchScene(AnimicScene*, QModelIndex);

	void deleteScene(AnimicScene*);

	void returnSceneToTrigger(AnimicScene*);

public slots:

	void onDoubleClicked(const QModelIndex&);
	void showContextMenu(const QPoint& pos);

	void onRenameScene();
	void onDeleteScene();

	void getScene(int);
};
