#pragma once

#include "mp3lint/scan/library_builder.h"

#include <string>
#include <filesystem>


class Linter {
public:
	Linter() = default;

	/*
		Scans the library at the given path and builds a Library object from it. The Library object can then be used to perform linting operations on the files in the library.
	*/

	void scan_library(const std::string& library_path);

private:
	std::filesystem::path library_file_path;
	Library library;
};