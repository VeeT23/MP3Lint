#include "directory_scanner.h"

nlohmann::json ScanResult::overview_to_json() const
{
	nlohmann::json j;
	j["total_size_bytes"] = total_size_bytes;
	j["total_files"] = total_files;
	j["total_files_audio"] = total_files_audio;
	j["total_files_image"] = total_files_image;
	j["total_files_playlist"] = total_files_playlist;
	j["total_files_other"] = total_files_other;
	return j;
}

nlohmann::json ScanResult::to_json() const {
	nlohmann::json j;
	j["total_size_bytes"] = total_size_bytes;
	j["total_files"] = total_files;
	j["total_files_audio"] = total_files_audio;
	j["total_files_image"] = total_files_image;
	j["total_files_playlist"] = total_files_playlist;
	j["total_files_other"] = total_files_other;
	for (const auto& entry : entries) {
		nlohmann::json entry_json;
		entry_json["file_path"] = entry.file_path.string();
		entry_json["type"] = static_cast<int>(entry.type);
		entry_json["size_bytes"] = entry.size_bytes;
		entry_json["date_modified"] = entry.date_modified;
		entry_json["extension"] = entry.extension;
		j["entries"].push_back(entry_json);
	}
	return j;
}

ScanResult scan_directory(const std::filesystem::path& directory_path)
{
	ScanResult result;
	auto& entries = result.entries;

	if (!std::filesystem::exists(directory_path) || !std::filesystem::is_directory(directory_path)) {
		return result;
	}

	auto opts = std::filesystem::directory_options::skip_permission_denied;
	for (const auto& entry : std::filesystem::recursive_directory_iterator(directory_path, opts)) {
		if (!entry.is_regular_file()) {
			continue;
		}

		result.total_files += 1;

		FileEntry file_entry;
		file_entry.file_path = entry.path();
		file_entry.extension = entry.path().extension().string();


		std::string ext_lower = file_entry.extension;
		std::ranges::transform(ext_lower, ext_lower.begin(), [](unsigned char c) { return std::tolower(c); });

		if (ext_lower == ".mp3" || ext_lower == ".flac" || ext_lower == ".wav" || ext_lower == ".aac" || ext_lower == ".ogg" || ext_lower == ".m4a") {
			file_entry.type = FileEntry::FileType::AUDIO;
			result.total_files_audio += 1;
		}
		else if (ext_lower == ".jpg" || ext_lower == ".jpeg" || ext_lower == ".png" || ext_lower == ".gif" || ext_lower == ".bmp") {
			file_entry.type = FileEntry::FileType::IMAGE;
			result.total_files_image += 1;
		}
		else if (ext_lower == ".m3u" || ext_lower == ".m3u8" || ext_lower == ".pls") {
			file_entry.type = FileEntry::FileType::PLAYLIST;
			result.total_files_playlist += 1;
		}
		else {
			file_entry.type = FileEntry::FileType::OTHER;
			result.total_files_other += 1;
		}

		std::error_code ec;
		auto file_size = std::filesystem::file_size(entry, ec);
		file_entry.size_bytes = ec ? 0 : static_cast<uint32_t>(file_size);
		result.total_size_bytes += ec ? 0 : file_size;

		auto ftime = std::filesystem::last_write_time(entry, ec);
		if (!ec) {
			try {
				auto sctp = std::chrono::clock_cast<std::chrono::system_clock>(ftime);
				file_entry.date_modified = std::format("{:%Y-%m-%d %H:%M:%S}", std::chrono::floor<std::chrono::seconds>(sctp));
			}
			catch (...) {
				file_entry.date_modified = "Unknown";
			}
		}
		else {
			file_entry.date_modified = "Unknown";
		}

		entries.push_back(file_entry);
	}

	return result;
}
