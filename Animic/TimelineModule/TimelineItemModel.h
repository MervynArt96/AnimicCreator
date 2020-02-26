#pragma once

#include <QAbstractListModel>


enum TrackType
{
    VideoTrackType, ImageTrackType, AudioTrackType, DialogueTrackType,
};

struct Track
{
	TrackType type;
	int number;
	int trackIndex;
};

typedef QList<Track> TrackList;

class TimelineItemModel : public QAbstractListModel
{
	Q_OBJECT

public:
	TimelineItemModel(QObject *parent);
	~TimelineItemModel();


	bool dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex& parent);
	QModelIndex	index(int, int, const QModelIndex& parent) const;
	QModelIndex	sibling(int, int, const QModelIndex& idx) const;

private:

	TrackList trackList;

signals:

public slots:


};
