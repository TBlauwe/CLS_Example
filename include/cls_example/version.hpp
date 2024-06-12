/*****************************************************************//**
@file   version.hpp
@brief  Contains information related to current version

@author TBlauwe
@date   12, June 2024
 *********************************************************************/
#pragma once

/**
    @namespace CLS_Example::version
    @brief Contains information related to current version
**/
namespace CLS_Example::version
{
    /** @brief Major version number of the project
     *  @details This is the X in the X.Y.Z format of semantic versioning.
    **/
    inline constexpr int major = 0;

    /** @brief Minor version number of the project
     *  @details This is the Y in the X.Y.Z format of semantic versioning.
    **/
    inline constexpr int minor = 0;

    /** @brief Patch version number of the project
     *  @details This is the Z in the X.Y.Z format of semantic versioning.
    **/
    inline constexpr int patch = 0;

    /** @brief Number of commits ahead of the latest release
     *  @details This is the number of commits that have been made since the last tag.
    **/
    inline constexpr int ahead = 1;

    /** @brief Full version string of the project in MAJOR.MINOR.PATCH+AHEAD-sha format.
     *  @details This is the version string that includes the major, minor, patch, ahead and git sha.
    **/
    inline constexpr const char * full = "0.0.0+1.1f9d535";

    /** @brief Version string of the project in X.Y.Z format
     *  @details This is the version string that only includes the major, minor, and patch numbers in the X.Y.Z format of semantic versioning.
    **/
    inline constexpr const char * str = "0.0.0";

    /** @brief Git SHA of the project
     *  @details This is the hash of the latest commit in the project.
    **/
    inline constexpr const char * git_sha = "1f9d535";
}
