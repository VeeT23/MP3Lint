#include "app.h"
#include "mp3lint/core/linter.h"
#include "ui/directory_viewer.h"

App::App(int& argc, char** argv) 
	: QApplication(argc, argv) 
{
	window.setWindowTitle("MP3 Linter");
	window.resize(800, 600);

	auto* directoryPanel = new DirectoryViewer(&window);
	window.setCentralWidget(directoryPanel);

	connect(
		directoryPanel,
		&DirectoryViewer::scanRequested,
		this,
		[this](const QString& path) {
			linter.scan_library(path.toStdString());
		}
	);

	window.show();
}