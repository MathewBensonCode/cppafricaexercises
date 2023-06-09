add_executable(streams stream.cpp)
target_link_libraries(streams PRIVATE project_options project_warnings)

CreateTargetLink(streams)

add_executable(stdcinversion stdcinversion.cpp)
target_link_libraries(stdcinversion PRIVATE project_options project_warnings)

CreateTargetLink(stdcinversion)
