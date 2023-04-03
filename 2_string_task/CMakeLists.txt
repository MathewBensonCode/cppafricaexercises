add_executable(string_task string_task.cpp)
target_link_libraries(string_task PRIVATE project_options project_warnings fmt::fmt)
CreateTargetLink(string_task)
