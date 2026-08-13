#include "song_parser.h"


SongResult parse_song_from_path(const std::filesystem::path& song_path)
{
	SongResult result;
	Song& song = result.song;
	bool has_error = false;

	if (!std::filesystem::exists(song_path)) {
		result.error |= SongResult::FILE_NOT_FOUND;
		has_error = true;
	}
	else {




	}






	if (!has_error) {
		result.error = SongResult::OK;
	}
	return result;
}