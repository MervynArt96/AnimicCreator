#pragma once
#include <QTreeWidget>
#include <QDebug>
#include "AssetHandlerModule/AssetItem.h"

class AssetHandler : public QTreeWidget
{
	Q_OBJECT

public:
	
	AssetHandler();
	~AssetHandler();
	
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

private:


signals:
	


public slots:


};

