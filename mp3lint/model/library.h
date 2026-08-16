#include "album.h"

#include <nlohmann/json.hpp>
#include <vector>

struct Library {
	std::vector<Album> albums;

	nlohmann::json overview_to_json() {
		nlohmann::json j;
		j["albums"] = albums.size();
		return j;
	}
};