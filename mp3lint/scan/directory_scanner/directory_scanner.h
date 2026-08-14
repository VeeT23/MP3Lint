#pragma once
#include <nlohmann/json.hpp>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <format>


struct FileEntry {

	std::filesystem::path file_path;
	uint32_t size_bytes = 0;
	std::string date_modified;
	std::string extension;

	bool operator<(const FileEntry& other) const {
		return file_path < other.file_path;
	}

	bool operator>(const FileEntry& other) const {
		return file_path > other.file_path;
	}

	bool operator<=(const FileEntry& other) const {
		return file_path <= other.file_path;
	}

	bool operator>=(const FileEntry& other) const {
		return file_path >= other.file_path;
	}

	bool operator==(const FileEntry& other) const {
		return file_path == other.file_path;
	}

};

struct ScanResult {

	std::vector<FileEntry> entries;
	uint64_t total_size_bytes      = 0;
	uint32_t total_files           = 0;
	
	nlohmann::json overview_to_json() const;
	nlohmann::json to_json() const;
};



ScanResult scan_directory(const std::filesystem::path& directory_path);