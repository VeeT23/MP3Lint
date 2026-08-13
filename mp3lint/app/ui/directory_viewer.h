#pragma once
#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;
class QTreeView;
class QFileSystemModel;


class DirectoryViewer : public QWidget {
	Q_OBJECT
public:
	explicit DirectoryViewer(QWidget* parent = nullptr);
signals:
	void directoryChanged(const QString& path);
	void scanRequested(const QString& path);

private slots:
	void browse();
	void loadPath();

private:
	QLabel* titleLabel;
	QLineEdit* pathEdit;
	QPushButton* upButton;
	QPushButton* browseButton;
	QPushButton* scanButton;
	QTreeView* treeView;
	QFileSystemModel* fileModel;
};