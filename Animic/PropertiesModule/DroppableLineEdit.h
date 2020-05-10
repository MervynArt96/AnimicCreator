#pragma once

#include <QLineEdit>

class DroppableLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	DroppableLineEdit(QWidget*parent);
	DroppableLineEdit();
	~DroppableLineEdit();

	void dropEvent(QDropEvent*) override;
	void dragEnterEvent(QDragEnterEvent*) override;
	void dragLeaveEvent(QDragLeaveEvent*) override;
	void dragMoveEvent(QDragMoveEvent*) override;

signals:

	void urlChanged(QList<QUrl>);

};
