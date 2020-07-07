#include "stdafx.h"
#include "SceneListDelegate.h"

SceneListDelegate::SceneListDelegate(QObject *parent): QItemDelegate(parent) // the representation to be displayed by the list view,in this case it is just a simple text field
{

}

SceneListDelegate::~SceneListDelegate()
{

}

QWidget* SceneListDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const	// display an overlay on top of the text field
{
	QLineEdit* editor = new QLineEdit(parent);	//this text field allows user to edit the name
	return editor;
}

void SceneListDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const	//set the data after finish editting
{
	QString name = index.model()->data(index, Qt::EditRole).toString();
	QLineEdit* edit = static_cast<QLineEdit*>(editor);
	edit->setText(name);
}

void SceneListDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const	//set the source of data
{
	QLineEdit* edit = static_cast<QLineEdit*>(editor);
	model->setData(index, edit->text(), Qt::EditRole);
}

void SceneListDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const	//set the editor shape to be the same as the delegate
{
	editor->setGeometry(option.rect);
}

void SceneListDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const	//to highlight the delegate when selected
{
	QItemDelegate::paint(painter, option, index);
}

/*
QSize SceneListDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const // to change the size of each delegate
{
	
}
*/
