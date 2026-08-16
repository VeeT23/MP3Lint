#pragma once

#include <vector>
#include <unordered_set>
#include "mp3lint/scan/directory_scanner/directory_scanner.h"

enum class FileType {
	AUDIO,
	IMAGE,
	PLAYLIST,
	OTHER,
	UNKNOWN
};

FileType identify_file_type(const std::filesystem::path& file_path)
{

	//TODO: Load file extension classifications from a user defined setting

	static const std::unordered_set<std::string> audio_extensions = {
			".mp3",
			".wav",
			".flac",
			".ogg",
			".m4a",
			".aac",
			".opus"
	};

	static const std::unordered_set<std::string> image_extensions = {
		".png",
		".jpg",
		".jpeg",
		".gif",
		".tiff",
		".bmp",
		".webp"
	};

	static const std::unordered_set<std::string> playlist_extensions = {
		".m3u",
		".m3u8",
		".pls"
	};

	static const std::unordered_set<std::string> other_extensions = {
		".txt",
		".pdf",
		".ini" // Hidden .ini files are used by windows for whatever
	};

	std::string extension = file_path.extension().string();

	std::ranges::transform(extension, extension.begin(), [](unsigned char c) { // Normalize to avoid case sensitive bugs
		return static_cast<char>(std::tolower(c));
		});


	if (audio_extensions.contains(extension)) {
		return FileType::AUDIO;
	}

	if (image_extensions.contains(extension)) {
		return FileType::IMAGE;
	}

	if (playlist_extensions.contains(extension)) {
		return FileType::PLAYLIST;
	}

	if (other_extensions.contains(extension)) {
		return FileType::OTHER;
	}

	return FileType::UNKNOWN;
}

// classify_files sorts and categorizes a given set of files

using FileIndex = uint16_t;

struct ClassifyResult {
	std::vector<FileEntry> entries;

	std::vector<FileIndex> audio_entries;
	std::vector<FileIndex> image_entries;
	std::vector<FileIndex> playlist_entries;
	std::vector<FileIndex> other_entries;
	std::vector<FileIndex> unknown_entries;

	nlohmann::json overview_to_json() const
	{
		nlohmann::json j;
		j["audio_entries"] = audio_entries.size();
		j["image_entries"] = image_entries.size();
		j["playlist_entries"] = playlist_entries.size();
		j["other_entries"] = other_entries.size();
		j["unknown_entries"] = unknown_entries.size();
		return j;
	}
};

ClassifyResult classify_files(const std::vector<FileEntry>& entries)
{
	ClassifyResult result;

	result.entries = entries;

	std::sort(result.entries.begin(), result.entries.end());

	for (FileIndex idx = 0; idx < result.entries.size(); idx++)
	{
		FileEntry& entry = result.entries[idx];
		FileType type = identify_file_type(entry.file_path);
		switch (type)
		{
		case FileType::AUDIO:
			result.audio_entries.push_back(idx);
			break;
		case FileType::IMAGE:
			result.image_entries.push_back(idx);
			break;
		case FileType::PLAYLIST:
			result.playlist_entries.push_back(idx);
			break;
		case FileType::OTHER:
			result.other_entries.push_back(idx);
			break;
		case FileType::UNKNOWN:
			result.unknown_entries.push_back(idx);
			break;
		default:
			throw std::runtime_error("Unrecognized FileType enum:" + std::to_string(static_cast<int>(type)));
		}
	}

	return result;
}