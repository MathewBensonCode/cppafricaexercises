add_executable(partA partA.cpp)
target_link_libraries(partA PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(partA)

add_executable(partB partB.cpp)
target_link_libraries(partB PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(partB)

add_executable(partC partC.cpp)
target_link_libraries(partC PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(partC)

add_executable(partD partD.cpp)
target_link_libraries(partD PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(partD)
