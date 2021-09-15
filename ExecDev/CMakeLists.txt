cmake_minimum_required(VERSION 3.10.0)
project(
        "ExecDev"
        VERSION 1.0
)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(EXEC_TARGET_NAME basicExecute)

add_executable(${EXEC_TARGET_NAME}
        ${HEADERS}
        ${SOURCES}
        main.cpp
        ${RESOURCES}
        )
# Add files that do not affect the built software but should be editable from the IDE
target_sources(${EXEC_TARGET_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/headers.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/linklibraries.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/resources.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCESLIST}
        )

target_link_libraries(${EXEC_TARGET_NAME} PUBLIC ${LINKLIBRARIES})
target_link_libraries(${EXEC_TARGET_NAME} LINK_PUBLIC ${LINKLIBRARIES})
target_include_directories(${EXEC_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../CodeDev/include)
target_include_directories(${EXEC_TARGET_NAME} PUBLIC include/)
