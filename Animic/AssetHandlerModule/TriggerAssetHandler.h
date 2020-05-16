#pragma once

#include <QListWidget>

class TriggerAssetHandler : public QTreeWidget
{
	Q_OBJECT

public:
	TriggerAssetHandler(QObject *parent);
	~TriggerAssetHandler();

	void importAsset();
	void importDirectory();
	void deleteAsset();

	QString mimeTypes();
	QString getMimeTypeFromFile(const QString);

protected:

	void mousePressEvent(QMouseEvent* event);
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* event);
	void dragMoveEvent(QDragMoveEvent* event);
	void dragLeaveEvent(QDragLeaveEvent* event);

};
