#pragma once

#include "mp3lint/model/song.h"


#include <filesystem>

class SongResult {
public:
	Song song;

	// Error codes for parsing a song from a file path
	// Does not treat missing data as an error, only if tags exist but are unable to parse. 
	enum ParseError {
		OK               = 0,
		FILE_NOT_FOUND   = 1,
		BAD_DATE         = 2,
		BAD_TRACK_NUMBER = 3,
		BAD_DISC_NUMBER  = 4
	};

	using ParseResult = uint16_t;

	ParseResult error = 0;

};

SongResult parse_song_from_path(const std::filesystem::path& song_path);