#include "stdafx.h"
#include "SceneListModel.h"

SceneListModel::SceneListModel()	// this is the backend model data for the list view
{
	
}

SceneListModel::~SceneListModel()
{

}

Qt::ItemFlags SceneListModel::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

int SceneListModel::rowCount(const QModelIndex& parent) const	//get number of rows
{
	return sceneList->count();
}

QVariant SceneListModel::data(const QModelIndex& index, int role) const	//get data based on the MVC architecture
{
	if (!index.isValid())	//invalid index
		return QVariant();	//return an empty data

	if (index.row() >= sceneList->size())	//invalid index
		return QVariant(); //return an empty data

	if (role == Qt::BackgroundRole)	//return scene here 
	{
		return QVariant::fromValue<AnimicScene*>(sceneList->at(index.row()));
	}
	else if (role == Qt::EditRole || role == Qt::DisplayRole)	//return scene name here
	{
		return sceneList->at(index.row())->getName();
	}
	else return QVariant();	//return empty data
}

bool SceneListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (index.isValid() && role == Qt::EditRole)	//edit scene name 
	{
		//sceneList->replace(index.row(), qvariant_cast<AnimicScene*>(value));
		sceneList->at(index.row())->setName(value.toString());

		emit dataChanged(index, index);
		return true;
	}
	return false;
}

bool SceneListModel::insertRows(int row, int count, const QModelIndex& parent)	//add new instance of scene
{
	beginInsertRows(QModelIndex(), row, row + count - 1);

	AnimicScene* newScene = new AnimicScene();

	for (int row = 0; row < count; ++row) 
	{
		sceneList->insert(row, newScene);
	}

	endInsertRows();
	return true;
}

bool SceneListModel::removeRows(int row, int count, const QModelIndex& parent)	//remove existing instance of scene
{
	beginRemoveRows(QModelIndex(), row, row + count - 1);
	sceneList->removeAt(row);

	endRemoveRows();
	return true;
}

void SceneListModel::appendRow()	//append new instance of scene, add to back
{
	beginInsertRows(QModelIndex(), sceneList->size(), sceneList->size());
	sceneList->append(new AnimicScene());
	endInsertRows();
}

void SceneListModel::appendRow(AnimicScene* sc) // append existing instance of scene, not used
{
	beginInsertRows(QModelIndex(), sceneList->size(), sceneList->size());
	sceneList->append(sc);

	endInsertRows();
}

QModelIndex SceneListModel::sibling(int row, int column, const QModelIndex& idx) const	// not used
{
	return idx;
}

QList<AnimicScene*>* SceneListModel::getList()	//return the entire list of scenes, not based on MVC architecture, for convenience only
{
	return sceneList;
}

void SceneListModel::setSceneToEditMode()	//change all scene in the list to edit mode, work with videoobjects
{
	for (int i = 0; i < sceneList->count(); i++)
	{
		sceneList->at(i)->enableObjectDragging();
		sceneList->at(i)->disableTrigger();
	}
}

void SceneListModel::setSceneToStitchMode()	//change all scene in the list to stitching mode, work with triggers
{
	for (int i = 0; i < sceneList->count(); i++)
	{
		sceneList->at(i)->disableObjectDragging();
		sceneList->at(i)->enableTrigger();
		sceneList->at(i)->disconnectObject();
		sceneList->at(i)->disconnect();
	}
}
