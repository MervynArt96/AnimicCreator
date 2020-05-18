#include "stdafx.h"
#include "SceneListModel.h"

SceneListModel::SceneListModel()
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

int SceneListModel::rowCount(const QModelIndex& parent) const
{
	return sceneList->count();
}

QVariant SceneListModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= sceneList->size())
		return QVariant();

	if (role == Qt::BackgroundRole)
	{
		return QVariant::fromValue<AnimicScene*>(sceneList->at(index.row()));
	}
	else if (role == Qt::EditRole || role == Qt::DisplayRole)
	{
		return sceneList->at(index.row())->getName();
	}
	else return QVariant();
}

bool SceneListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (index.isValid() && role == Qt::EditRole) 
	{
		//sceneList->replace(index.row(), qvariant_cast<AnimicScene*>(value));
		sceneList->at(index.row())->setName(value.toString());

		emit dataChanged(index, index);
		return true;
	}
	return false;
}

bool SceneListModel::insertRows(int row, int count, const QModelIndex& parent)
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

bool SceneListModel::removeRows(int row, int count, const QModelIndex& parent)
{
	beginRemoveRows(QModelIndex(), row, row + count - 1);

	for (int row = 0; row < count; ++row) {
		sceneList->removeAt(row);
	}

	endRemoveRows();
	return true;
}

void SceneListModel::appendRow()
{
	beginInsertRows(QModelIndex(), sceneList->size(), sceneList->size());
	sceneList->append(new AnimicScene());
	endInsertRows();
}

void SceneListModel::appendRow(AnimicScene* sc)
{
	beginInsertRows(QModelIndex(), sceneList->size(), sceneList->size());
	sceneList->append(sc);

	endInsertRows();

}

QModelIndex SceneListModel::sibling(int row, int column, const QModelIndex& idx) const
{
	return idx;
}

QList<AnimicScene*>* SceneListModel::getList()
{
	return sceneList;
}
