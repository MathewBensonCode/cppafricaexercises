add_executable(partA partA.cpp)
target_link_libraries(partA PRIVATE project_options project_warnings fmt::fmt)
createtargetlink(partA)

add_library(partBLib partB_lib.cpp)
target_link_libraries(
    partBLib
    PUBLIC
    project_options
    project_warnings
    fmt::fmt
    )

add_executable(partB partB.cpp)
target_link_libraries(partB PRIVATE partBLib)
createtargetlink(partB)


add_library(partCLib partC_lib.cpp)
target_include_directories(partCLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
    partCLib
    PUBLIC
    project_options
    project_warnings
    fmt::fmt
    )

add_executable(partC partC.cpp)
target_link_libraries(partC PRIVATE partCLib)
createtargetlink(partC)

add_library(partDLib partD_lib.cpp)
target_include_directories(partDLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
    partDLib
    PUBLIC
    project_options
    project_warnings
    fmt::fmt
    partBLib partCLib
    )

add_executable(partD partD.cpp)
target_link_libraries(partD PRIVATE partDLib)
createtargetlink(partD)

