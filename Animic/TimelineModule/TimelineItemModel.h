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
	//Q_PROPERTY(int trackHeight READ getTrackHeight WRITE setTrackHeight NOTIFY trackHeightChanged)
	//Q_PROPERTY(double scaleFactor READ getScaleFactor WRITE setScaleFactor NOTIFY scaleFactorChanged)

public:
	explicit TimelineItemModel(QObject *parent);
	~TimelineItemModel();

	bool dropMimeData(const QMimeData* , Qt::DropAction , int , int , const QModelIndex& );
	QModelIndex	index(int, int, const QModelIndex& ) const;
	QModelIndex	sibling(int, int, const QModelIndex& ) const;
	QVariant data(const QModelIndex& , int ) const;
	int rowCount(const QModelIndex&  = QModelIndex()) const;
	int columnCount(const QModelIndex& ) const;
	int getTrackHeight() const;
	void setTrackHeight(int height);
	double getScaleFactor() const;
	void setScaleFactor(double scale);

private:

	TrackList trackList;

	int trackHeight = 10;
	double scaleFactor = 1;

signals:
	
	//void trackHeightChanged();
	//void scaleFactorChanged();

public slots:


};
