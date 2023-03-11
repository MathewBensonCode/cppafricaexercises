add_executable(task3 task3.cpp)
target_link_libraries(task3 PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(task3)

add_executable(kraatorsversion kraatorsversion.cpp)
target_link_libraries(kraatorsversion PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(kraatorsversion)

add_executable(kraatorclang kraatorclang.cpp)
target_link_libraries(kraatorclang PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(kraatorclang)
