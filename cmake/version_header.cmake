MESSAGE(STATUS "Configuring ${PROJECT_SOURCE_DIR}/include/cls_example/version.hpp")
configure_file(${PROJECT_SOURCE_DIR}/src/version.hpp.in ${PROJECT_SOURCE_DIR}/include/cls_example/version.hpp @ONLY)