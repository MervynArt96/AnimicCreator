#pragma once
#include <QTreeWidget>
#include <QDebug>

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

