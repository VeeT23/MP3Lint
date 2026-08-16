#pragma once

#include <string>
#include <vector>
#include <filesystem>

using SongTitle = std::string;
using ArtistName = std::string;
using Genre = std::string;

struct SongMetadata {

	SongTitle title;
	std::vector<ArtistName> artists;
	std::vector<ArtistName> album_artists;
	std::vector<Genre> genres;

	uint16_t year = UINT16_MAX;
	uint16_t track_number = UINT16_MAX;
	uint16_t disc_number = UINT16_MAX;

	uint16_t total_tracks = UINT16_MAX;
	uint16_t total_discs = UINT16_MAX;
};

struct Song {
	
	Song() = default;
	Song(std::filesystem::path path) : file_path(path) {}

	std::filesystem::path file_path;
	SongMetadata data;
};

