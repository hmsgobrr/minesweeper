cmake_minimum_required(VERSION 3.0)
project(minesweeper CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE "src/*.cpp" "src/*.h")
file(GLOB ASSETS "assets/*.png" "assets/*.jpg" "README.md")

add_executable(${PROJECT_NAME} ${SOURCE} ${ASSETS})

add_subdirectory(vendor/plankton)
target_link_libraries(${PROJECT_NAME} plankton)
target_include_directories(${PROJECT_NAME} PUBLIC "vendor/plankton/include" "vendor/plankton/vendor/spdlog")

# Macro for absolute path to assets folder
# NOTE: use relative path for release
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
