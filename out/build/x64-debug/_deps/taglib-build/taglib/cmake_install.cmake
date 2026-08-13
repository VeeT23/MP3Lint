# Install script for directory: C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Joefi/source/repos/MP3Lint/out/install/x64-debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/taglib/tag.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/taglib" TYPE FILE FILES
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/tag.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/fileref.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/audioproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/taglib_export.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/taglib.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tstring.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tlist.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tlist.tcc"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tstringlist.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tbytevector.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tbytevectorlist.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tvariant.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tbytevectorstream.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tiostream.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tfilestream.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tmap.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tmap.tcc"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tpicturetype.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tpropertymap.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tdebuglistener.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/toolkit/tversionnumber.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/mpegfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/mpegproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/mpegheader.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/xingheader.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v1/id3v1tag.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v1/id3v1genres.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/id3v2.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/id3v2extendedheader.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/id3v2frame.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/id3v2header.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/id3v2synchdata.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/id3v2footer.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/id3v2framefactory.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/id3v2tag.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/commentsframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/eventtimingcodesframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/ownershipframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/privateframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/synchronizedlyricsframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/unknownframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/urllinkframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/chapterframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/tableofcontentsframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpeg/id3v2/frames/podcastframe.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/oggfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/oggpage.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/oggpageheader.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/xiphcomment.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/vorbis/vorbisfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/vorbis/vorbisproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/flac/oggflacfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/speex/speexfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/speex/speexproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/opus/opusfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ogg/opus/opusproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/flac/flacfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/flac/flacpicture.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/flac/flacproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/flac/flacmetadatablock.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ape/apefile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ape/apeproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ape/apetag.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ape/apefooter.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/ape/apeitem.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpc/mpcfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mpc/mpcproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/wavpack/wavpackfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/wavpack/wavpackproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/trueaudio/trueaudiofile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/trueaudio/trueaudioproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/riff/rifffile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/riff/aiff/aifffile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/riff/aiff/aiffproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/riff/wav/wavfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/riff/wav/wavproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/riff/wav/infotag.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/asf/asffile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/asf/asfproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/asf/asftag.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/asf/asfattribute.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/asf/asfpicture.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mp4/mp4file.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mp4/mp4atom.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mp4/mp4tag.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mp4/mp4item.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mp4/mp4properties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mp4/mp4coverart.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mp4/mp4itemfactory.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mod/modfilebase.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mod/modfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mod/modtag.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/mod/modproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/it/itfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/it/itproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/s3m/s3mfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/s3m/s3mproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/xm/xmfile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/xm/xmproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/dsf/dsffile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/dsf/dsfproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/dsdiff/dsdifffile.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/dsdiff/dsdiffproperties.h"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-src/taglib/dsdiff/dsdiffdiintag.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib/taglib-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib/taglib-targets.cmake"
         "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/taglib/CMakeFiles/Export/398eef5e047a0959864f2888198961bf/taglib-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib/taglib-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib/taglib-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib" TYPE FILE FILES "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/taglib/CMakeFiles/Export/398eef5e047a0959864f2888198961bf/taglib-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib" TYPE FILE FILES "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/taglib/CMakeFiles/Export/398eef5e047a0959864f2888198961bf/taglib-targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib" TYPE FILE FILES
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/taglib-config.cmake"
    "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/taglib-config-version.cmake"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/taglib/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
