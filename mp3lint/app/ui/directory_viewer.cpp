#include "directory_viewer.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStandardPaths>
#include <QDir>

DirectoryViewer::DirectoryViewer(QWidget* parent)
	: QWidget(parent)
{
	titleLabel = new QLabel("Directory Viewer", this);
	pathEdit = new QLineEdit(this);
	browseButton = new QPushButton("Browse", this);
	upButton = new QPushButton(this);
	scanButton = new QPushButton("Scan", this);
	treeView = new QTreeView(this);
	fileModel = new QFileSystemModel(this);

	upButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogToParent));

	fileModel->setFilter(
		QDir::AllDirs |
		QDir::NoDotAndDotDot |
		QDir::Files
	);

	treeView->setModel(fileModel);

	// Give the name column most of the space
	treeView->setColumnWidth(0, 300); // Name
	treeView->setColumnWidth(1, 60);  // Size
	treeView->setColumnWidth(2, 60);  // Type
	treeView->setColumnWidth(3, 80);  // Date Modified

	auto* pathLayout = new QHBoxLayout;

	pathLayout->addWidget(upButton);
	pathLayout->addWidget(pathEdit);
	pathLayout->addWidget(browseButton);
	pathLayout->addWidget(scanButton);


	auto* mainLayout = new QVBoxLayout(this);

	mainLayout->addWidget(titleLabel);
	mainLayout->addLayout(pathLayout);
	mainLayout->addWidget(treeView);

	treeView->setExpandsOnDoubleClick(false);

	connect(treeView, &QTreeView::doubleClicked,
		this, [this](const QModelIndex& index)
		{
			if (!fileModel->isDir(index))
				return;

			QString directory = fileModel->filePath(index);
			pathEdit->setText(directory);

			loadPath();
		});

	connect(
		browseButton,
		&QPushButton::clicked,
		this,
		&DirectoryViewer::browse
	);

	connect(
		scanButton,
		&QPushButton::clicked,
		this,
		[this]() {
			emit scanRequested(pathEdit->text());
		}
	);

	connect(
		upButton,
		&QPushButton::clicked,
		this,
		[this]() {
			QDir dir(pathEdit->text());
			if (dir.cdUp()) {
				pathEdit->setText(dir.absolutePath());
				loadPath();
			}
		}
	);


	connect(
		pathEdit,
		&QLineEdit::returnPressed,
		this,
		&DirectoryViewer::loadPath
	);


	// Start location
	QString startPath = QStandardPaths::writableLocation(QStandardPaths::MusicLocation);

	if (startPath.isEmpty() || !QDir(startPath).exists())
	{
		startPath = QDir::homePath();
	}

	pathEdit->setText(startPath);
	loadPath();
}

void DirectoryViewer::browse()
{
	QString directory =
		QFileDialog::getExistingDirectory(
			this,
			"Select Directory"
		);

	if (!directory.isEmpty())
	{
		pathEdit->setText(directory);
		loadPath();
	}
}

void DirectoryViewer::loadPath()
{
	QString path = pathEdit->text();

	QModelIndex root =
		fileModel->setRootPath(path);

	treeView->setRootIndex(root);

	emit directoryChanged(path);
}