#pragma once
#include "song.h"

#include <string>
#include <vector>

using AlbumName = std::string;

struct Album {

	std::filesystem::path directory_path;

	AlbumName name;
	std::vector<ArtistName> album_artists;
	std::vector<Song*> songs;
};