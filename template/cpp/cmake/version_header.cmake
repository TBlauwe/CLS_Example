MESSAGE(STATUS "Configuring ${PROJECT_SOURCE_DIR}/include/{{tmplr.repo_name | lowercase}}/version.hpp")
configure_file(${PROJECT_SOURCE_DIR}/src/version.hpp.in ${PROJECT_SOURCE_DIR}/include/{{tmplr.repo_name | lowercase}}/version.hpp @ONLY)