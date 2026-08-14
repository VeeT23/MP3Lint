#include "linter.h"

#include "mp3lint/core/console.h"

void Linter::scan_library(const std::string& library_path)
{
	std::string normalized_path = library_path;

	std::replace(
		normalized_path.begin(),
		normalized_path.end(),
		'\\',
		'/'
	);

	library_file_path =
		std::filesystem::path(normalized_path).lexically_normal();

	library = build_library_from_path(library_file_path);
}