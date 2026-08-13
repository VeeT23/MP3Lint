#pragma once
#include <QMainWindow>
#include <QApplication>
#include "mp3lint/core/linter.h"

class App : public QApplication {
	Q_OBJECT
public:
	App(int& argc, char** argv);

private:
	QMainWindow window;
	Linter linter;
};