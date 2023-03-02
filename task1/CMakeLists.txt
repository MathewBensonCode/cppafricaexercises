add_executable(task1 task1.cpp)
target_link_libraries(task1 PRIVATE project_options project_warnings fmt::fmt)

CreateTargetLink(task1)
