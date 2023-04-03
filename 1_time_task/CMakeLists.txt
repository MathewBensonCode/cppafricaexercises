add_executable(time_task time_task.cpp)
target_link_libraries(time_task PRIVATE project_options project_warnings fmt::fmt)

CreateTargetLink(time_task)
