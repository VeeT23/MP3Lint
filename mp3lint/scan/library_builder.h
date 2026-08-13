#pragma once
#include <filesystem>
#include "mp3lint/model/library.h"

// Takes a path and builds a library object from it. The library object can then be used to perform linting operations on the files in the library.

Library build_library_from_path(const std::filesystem::path& library_path);