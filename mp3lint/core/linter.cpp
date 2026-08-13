#include "linter.h"

#include "mp3lint/core/console.h"

void Linter::scan_library(const std::string& library_path)
{
	library_file_path = library_path;

	library = build_library_from_path(library_path);
}