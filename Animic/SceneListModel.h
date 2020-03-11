#pragma once

#include <QAbstractListModel>

class SceneListModel : public QAbstractListModel
{
	Q_OBJECT

public:
	SceneListModel(QWidget *parent);
	~SceneListModel();

	Qt::ItemFlags flags(const QModelIndex& index) const override;
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
	bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
	
	QModelIndex sibling(int row, int column, const QModelIndex& idx) const override;

signals:

	void headerDataChanged(Qt::Orientation orientation, int first, int last);
	


};
