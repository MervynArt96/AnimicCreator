#include "stdafx.h"
#include "SceneListDelegate.h"

SceneListDelegate::SceneListDelegate(QObject *parent): QItemDelegate(parent)
{

}

SceneListDelegate::~SceneListDelegate()
{

}

QWidget* SceneListDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QLineEdit* editor = new QLineEdit(parent);
	return editor;
}

void SceneListDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	QString name = index.model()->data(index, Qt::EditRole).toString();
	QLineEdit* edit = static_cast<QLineEdit*>(editor);
	edit->setText(name);
}

void SceneListDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	QLineEdit* edit = static_cast<QLineEdit*>(editor);
	model->setData(index, edit->text(), Qt::EditRole);
}

void SceneListDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	editor->setGeometry(option.rect);
}

void SceneListDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

}

QSize SceneListDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	
}
