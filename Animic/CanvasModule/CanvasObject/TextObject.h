#pragma once

#include <QGraphicsTextItem>

class TextObject : public QGraphicsTextItem
{
	Q_OBJECT

public:
	TextObject(QObject *parent);
	~TextObject();
};
