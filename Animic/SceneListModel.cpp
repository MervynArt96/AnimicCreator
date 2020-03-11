#include "stdafx.h"
#include "SceneListModel.h"

SceneListModel::SceneListModel(QWidget *parent) : QAbstractListModel(parent)
{

}

SceneListModel::~SceneListModel()
{

}

Qt::ItemFlags SceneListModel::flags(const QModelIndex& index) const
{
	return Qt::ItemIsEditable;
}

int SceneListModel::rowCount(const QModelIndex& parent) const
{
	return 1;
}

QVariant SceneListModel::data(const QModelIndex& index, int role) const
{
	QVariant var;
	return var;
}

bool SceneListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	return false;
}

QVariant SceneListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	QVariant var;
	return var;
}

bool SceneListModel::insertRows(int row, int count, const QModelIndex& parent)
{
	return false;
}

bool SceneListModel::removeRows(int row, int count, const QModelIndex& parent)
{
	return false;
}

QModelIndex SceneListModel::sibling(int row, int column, const QModelIndex& idx) const
{
	return idx;
}
