CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(PidgeotEngine)

set_property(GLOBAL PROPERTY ENGINE_LIBS "")
set_property(GLOBAL PROPERTY ENGINE_INCLUDES "")

# Gather all source files
aux_source_directory(src/application/src SRC_APPLICATION)
aux_source_directory(src/application/src/tasks SRC_APPLICATION_TASKS)
aux_source_directory(src/application/src/entities SRC_APPLICATION_ENTITIES)
aux_source_directory(src/engine/src SRC_ENGINE)
aux_source_directory(src/engine/src/managers SRC_ENGINE_MANAGERS)
aux_source_directory(src/engine/src/modules SRC_ENGINE_MODULES)
aux_source_directory(src/engine/src/modules/map SRC_ENGINE_MODULES_MAP)
aux_source_directory(src/engine/src/resources SRC_ENGINE_RESOURCES)
aux_source_directory(src/engine/src/resources SRC_ENGINE_RESOURCES_SPRITE)
aux_source_directory(src/engine/src/utils SRC_ENGINE_UTILS)

set(SOURCES
        ${SRC_APPLICATION}
        ${SRC_APPLICATION_TASKS}
        ${SRC_APPLICATION_ENTITIES}
        ${SRC_ENGINE}
        ${SRC_ENGINE_MANAGERS}
        ${SRC_ENGINE_MODULES}
        ${SRC_ENGINE_MODULES_MAP}
        ${SRC_ENGINE_RESOURCES}
        ${SRC_ENGINE_RESOURCES_SPRITE}
        ${SRC_ENGINE_UTILS})

# Required packages and include paths
include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
include_directories(src/application/src src/engine/src)
include_directories(vendor/spdlog/include)
include_directories(vendor/rapidxml/include)

# Compile spdlog as a static library
find_package(Threads REQUIRED)

add_library(spdlog STATIC vendor/spdlog/src/spdlog.cpp ${SPDLOG_ALL_HEADERS})
target_compile_definitions(spdlog PUBLIC SPDLOG_COMPILED_LIB)
target_include_directories(spdlog PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_link_libraries(spdlog PUBLIC Threads::Threads)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} spdlog)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)