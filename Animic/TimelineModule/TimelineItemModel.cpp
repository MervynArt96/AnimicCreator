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

QVariant TimelineItemModel::data(const QModelIndex& index, int role) const
{
	return index;
}

int TimelineItemModel::rowCount(const QModelIndex& parent) const
{
	return trackList.count();
}

int TimelineItemModel::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return 1;
}

int TimelineItemModel::getTrackHeight() const
{
	return trackHeight;
}

void TimelineItemModel::setTrackHeight(int height)
{
	trackHeight = height;
}

double TimelineItemModel::getScaleFactor() const
{
	return 1.0;
}

void TimelineItemModel::setScaleFactor(double scale)
{

}

/*
void TimelineItemModel::trackHeightChanged()
{

}

void TimelineItemModel::scaleFactorChanged()
{

}*/