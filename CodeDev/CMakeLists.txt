cmake_minimum_required(VERSION 3.10.0)

project(
        "CodeDev"
        VERSION 1.0
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/headers.cmake HEADERS)
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake SOURCES)
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/linklibraries.cmake LINKLIBRARIES)

set(LIB_TARGET_NAME CodeDev)

add_library(${LIB_TARGET_NAME} SHARED
        ${HEADERS}
        ${SOURCES}
        ${RESOURCES}
        )

# Add files that do not affect the built software but should be editable from the IDE
target_sources(${LIB_TARGET_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/headers.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/tests.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/documentation.cmake
        )

target_link_libraries(${LIB_TARGET_NAME} PUBLIC ${LINKLIBRARIES})
target_include_directories (${LIB_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${LIB_TARGET_NAME} PUBLIC include/)

install(
        TARGETS ${LIB_TARGET_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)