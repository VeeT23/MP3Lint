#pragma once

#include "mp3lint/scan/library_builder.h"

#include <string>
#include <filesystem>


class Linter {
public:
	Linter() = default;

	void scan_library(const std::string& library_path);

private:
	std::string library_file_path;
	Library library;
};