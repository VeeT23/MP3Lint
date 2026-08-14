#include "library_builder.h"
#include "directory_scanner/directory_scanner.h"
#include "mp3lint/core/console.h"
#include "mp3lint/scan/file_classifier/file_classifier.h"

Library build_library_from_path(const std::filesystem::path& library_path)
{
	Library library;

	ScanResult scan_result = scan_directory(library_path);

	Console::GetInstance().WriteLine("Scanned directory: " + library_path.string());
	Console::GetInstance().WriteLine(scan_result.overview_to_json().dump(4));

	ClassifyResult class_result;
	class_result = classify_files(scan_result.entries);

	Console::GetInstance().WriteLine("Classification result:");
	Console::GetInstance().WriteLine(class_result.overview_to_json().dump(4));

	for (int i = 0; i < 20; i++)
	{
		Console::GetInstance().WriteLine(class_result.entries[i].file_path.wstring());
	}

	

	return library;
}