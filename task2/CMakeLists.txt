add_executable(task2 task2.cpp)
target_link_libraries(task2 PRIVATE project_options project_warnings fmt::fmt)

CreateTargetLink(task2)
