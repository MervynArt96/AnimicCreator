#include "stdafx.h"
#include "TimelineItemModel.h"

TimelineItemModel::TimelineItemModel(QObject *parent)
{

}

TimelineItemModel::~TimelineItemModel()
{

}


bool TimelineItemModel::dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex& parent)
{
	return false;
}

QModelIndex	TimelineItemModel::index(int row, int column, const QModelIndex& parent) const
{
	return parent;
}

QModelIndex	TimelineItemModel::sibling(int row, int column, const QModelIndex& idx) const
{
	return idx;
}