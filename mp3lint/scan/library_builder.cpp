#include "library_builder.h"
#include "directory_scanner/directory_scanner.h"
#include "mp3lint/core/console.h"
#include "mp3lint/scan/file_classifier/file_classifier.h"

Library static build_library_from_classify(const ClassifyResult& classify_result)
{
	Library library;

	Album album;

	std::filesystem::path previous_parent_path;
	for (const FileIndex& idx : classify_result.audio_entries) // Sorted by path
	{
		const FileEntry& entry = classify_result.entries[idx];
		std::filesystem::path parent_path = entry.file_path.parent_path();
		if (parent_path != previous_parent_path)
		{
			if (!album.songs.empty())
			{
				library.albums.push_back(std::move(album));
			}

			album = Album(parent_path);
		}


		album.songs.emplace_back(entry.file_path);

		previous_parent_path = parent_path;
	}

	if (!album.songs.empty())
	{
		library.albums.push_back(std::move(album));
	}

	return library;
}

Library build_library_from_path(const std::filesystem::path& library_path)
{

	ScanResult scan_result = scan_directory(library_path);

	Console::GetInstance().WriteLine("Scanned directory: " + library_path.string());
	Console::GetInstance().WriteLine(scan_result.overview_to_json().dump(4));

	ClassifyResult classify_result;
	classify_result = classify_files(scan_result.entries);

	Console::GetInstance().WriteLine("Classification result:");
	Console::GetInstance().WriteLine(classify_result.overview_to_json().dump(4));

	Library library = build_library_from_classify(classify_result);

	Console::GetInstance().WriteLine("Library build result:");
	Console::GetInstance().WriteLine(library.overview_to_json().dump(4));


	// TODO: parse song pass to populate SongMetadata of Song class.

	return library;
}