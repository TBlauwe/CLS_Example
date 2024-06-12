# ------------------------------------------------------------------------------ 
#           File : CMakeLists.txt
#         Author : TBlauwe
#    Description : Root cmake file.
#
#                  Available targets (excluding dependencies) :
#                  * cls_example : main library
#                  * tests, documentation, benchmarks are only available
#                  when build as the main project.
#
#                  Noteworthy cmake folders :
#                  * cmake/  : Additional cmake files, mainly to de-clutter root CMakeLists.txt.
#                  * extern/ : contains cmake files to find dependencies using CPM.
#                              Can be skipped by setting CLS_EXAMPLE_DOWNLOAD_DEPENDENCIES 
#
# ------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.21...3.26)
include(cmake/prevent_in_source_build.cmake)

# ----- Project information
project(CLS_EXAMPLE
	DESCRIPTION "Repository generated from cpp_lib_starter template repository"
	HOMEPAGE_URL "https://github.com/TBlauwe/CLS_Example"
	LANGUAGES C CXX
)

# ------------------------------------------------------------------------------
# --- CMake Configuration
# ------------------------------------------------------------------------------
# CMake's behaviours is altered whether this project is consumed or if it is the main project
if (PROJECT_IS_TOP_LEVEL)
	if (NOT DEFINED CMAKE_CXX_STANDARD)
		set(CMAKE_CXX_STANDARD 20) 							# Only set the cxx_standard if it is not set by someone else
	endif()
	set(CMAKE_CXX_EXTENSIONS OFF)                           # Ensure -std=c++xx is used instead of -std=g++xx. See: https://crascit.com/2015/03/28/enabling-cxx11-in-cmake/
	set(CPM_USE_NAMED_CACHE_DIRECTORIES ON)                 # See https://github.com/cpm-cmake/CPM.cmake?tab=readme-ov-file#cpm_use_named_cache_directories
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)            # Support folders in IDEs
	set(${PROJECT_NAME}_EXE_DIR "${CMAKE_BINARY_DIR}/bin")  # Convenience variable to generate executables (tests, benchmarks, experiments, examples) in a bin/ folder.
endif ()


include(cmake/utility.cmake)
# ------------------------------------------------------------------------------
# --- Project options
# ------------------------------------------------------------------------------
section("Options")
	option(${PROJECT_NAME}_USE_TRACY                "Enable usage of tracy to instrument library code."                     OFF)
	include(CMakePrintHelpers)
	cmake_print_variables(CPM_SOURCE_CACHE)
	cmake_print_variables(${PROJECT_NAME}_NO_ASSERT)
end_section()


# ------------------------------------------------------------------------------
# --- Additional setup : tools and file configuration
# ------------------------------------------------------------------------------
section("Configuring additional cmake tools")
include(cmake/cache.cmake)
include(cmake/misc.cmake) # Add warning guards and other miscellaneous items.
end_section()

section("Configuring files")
include(cmake/set_version_from_git.cmake)   # Defines version from git if is TOP_LEVEL, otherwise read it from file.
include(cmake/version_header.cmake)         # Generate a version header file.
end_section(
		CONDITION ${PROJECT_NAME}_VERSION
		PASS "done. Version : ${${PROJECT_NAME}_VERSION_STRING_FULL}"
		FAIL "failed."
)


# ------------------------------------------------------------------------------
# --- Dependencies
# ------------------------------------------------------------------------------
section("Finding dependencies")
	# Dependencies are added via CPM.
	# See https://github.com/cpm-cmake/CPM.cmake for more info.
	include(cmake/find_cpm.cmake)
	include(extern/core.cmake)
end_section()


# ------------------------------------------------------------------------------
# --- Target : cls_example
# ------------------------------------------------------------------------------
# --- Sources
SET(SOURCE_LIST
    "src/core.cpp"
)

# --- Headers
SET(HEADER_LIST
    "include/cls_example/core.hpp"
    "include/cls_example/version.hpp"
)

# --- Assets
# No assets here

section(CHECK_START "Configuring cls_example")

	add_library(cls_example ${SOURCE_LIST} ${HEADER_LIST})
	add_library(cls_example::cls_example ALIAS cls_example)
	target_compile_features(cls_example PRIVATE cxx_std_20)
	target_compile_options(cls_example PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/Zc:preprocessor>) # if using __VA_OPT__, we enforce latest preprocessor on MSVC
	target_compile_options(cls_example PUBLIC $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->) # being a cross-platform target, we enforce standards conformance on MSVC
	target_link_libraries(cls_example PUBLIC core_dependencies)
	target_include_directories(cls_example ${${PROJECT_NAME}_WARNING_GUARD} PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")

	option_define(cls_example ${PROJECT_NAME}_NO_ASSERT)

	if(${PROJECT_IS_TOP_LEVEL})
		include(cmake/target_set_compile_warnings.cmake)
		target_set_compile_warnings_cxx(TARGET cls_example SCOPE PRIVATE)
		target_compile_options(cls_example PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/ZI>)             # Needed to enable "Edit and Continue" for MSVC
		target_compile_options(cls_example PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/INCREMENTAL>)    # Needed to enable "Edit and Continue" for MSVC
	endif()
end_section()


# ------------------------------------------------------------------------------
# --- Export
# ------------------------------------------------------------------------------
include(GenerateExportHeader)

generate_export_header(cls_example BASE_NAME ${PROJECT_NAME} EXPORT_FILE_NAME export/cls_example/export.hpp)

set_target_properties(
	cls_example
	PROPERTIES
	CXX_VISIBILITY_PRESET hidden
	VISIBILITY_INLINES_HIDDEN YES
	VERSION "${PROJECT_VERSION}"
	SOVERSION "${PROJECT_VERSION_MAJOR}"
	EXPORT_NAME cls_example
	OUTPUT_NAME cls_example
)

target_include_directories(cls_example SYSTEM PUBLIC "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>")


# ------------------------------------------------------------------------------
# --- Additional targets : tests, benchmarks.
# ------------------------------------------------------------------------------
# Only available if this is the main project
if(${PROJECT_IS_TOP_LEVEL})
	include(CTest)
	add_subdirectory(tests)
	add_subdirectory(benchmarks)
	add_subdirectory(examples)
	add_subdirectory(docs)
	section("Closure")
endif()
