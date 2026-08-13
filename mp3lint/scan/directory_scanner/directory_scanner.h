#pragma once
#include <nlohmann/json.hpp>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <format>


class FileEntry {
public:
	enum class FileType {
		AUDIO,
		IMAGE,
		PLAYLIST,
		OTHER
	};

	std::filesystem::path file_path;
	FileType type = FileType::OTHER;

	uint32_t size_bytes = 0;
	std::string date_modified;
	std::string extension;
};

class ScanResult {
public:

	std::vector<FileEntry> entries;
	uint64_t total_size_bytes      = 0;
	uint32_t total_files           = 0;

	uint32_t total_files_audio     = 0;
	uint32_t total_files_image     = 0;
	uint32_t total_files_playlist  = 0;
	uint32_t total_files_other     = 0;
	
	nlohmann::json overview_to_json() const;
	nlohmann::json to_json() const;
};

inline ScanResult scan_directory(const std::filesystem::path& directory_path);