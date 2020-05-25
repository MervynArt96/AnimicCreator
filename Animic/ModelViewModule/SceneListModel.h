#pragma once

#include <QAbstractListModel>
#include "CanvasModule/AnimicScene.h"

class SceneListModel : public QAbstractListModel
{
	Q_OBJECT

public:
	SceneListModel();
	~SceneListModel();

	Qt::ItemFlags flags(const QModelIndex& index) const override;
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role) const override;
	QList<AnimicScene*>* SceneListModel::getList();

	bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
	bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	void appendRow();
	void appendRow(AnimicScene*);

	void setSceneToEditMode();
	void setSceneToStitchMode();
	
	QModelIndex sibling(int row, int column, const QModelIndex& idx) const override;

private:
	
	QList<AnimicScene*>* sceneList = new QList<AnimicScene*>();


signals:
	


};
