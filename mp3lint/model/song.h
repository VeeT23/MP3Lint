#pragma once

#include <string>
#include <vector>

using SongTitle = std::string;
using ArtistName = std::string;
using Genre = std::string;

class Song {
public:
	Song() = default;

	SongTitle title;
	std::vector<ArtistName> artists;
	std::vector<ArtistName> album_artists;
	std::vector<Genre> genres;

	uint16_t year;
	uint16_t track_number;
	uint16_t disc_number;

	uint16_t total_tracks;
	uint16_t total_discs;
};