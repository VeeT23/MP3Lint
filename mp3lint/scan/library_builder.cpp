#include "library_builder.h"
#include "directory_scanner/directory_scanner.h"
#include "mp3lint/core/console.h"

Library build_library_from_path(const std::filesystem::path& library_path)
{
	Library library;

	ScanResult scan_result = scan_directory(library_path);

	Console::GetInstance().WriteLine("Scanned directory: " + library_path.string());
	Console::GetInstance().WriteLine(scan_result.overview_to_json().dump(4));

	return library;
}