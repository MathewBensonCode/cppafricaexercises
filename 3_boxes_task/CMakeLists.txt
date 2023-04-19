add_executable(boxes_task boxes_task.cpp)
target_link_libraries(boxes_task PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(boxes_task)
