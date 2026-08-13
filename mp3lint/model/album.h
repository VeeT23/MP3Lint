#pragma once
#include "song.h"

#include <string>
#include <vector>

using AlbumName = std::string;

class Album {

	AlbumName name;
	std::vector<ArtistName> artists;
	std::vector<Song*> songs;
};