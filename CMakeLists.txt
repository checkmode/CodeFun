cmake_minimum_required(VERSION 3.0.0)
project(CodeFun VERSION 0.1.0)

# include(CTest)
# enable_testing()

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_subdirectory(LibraryA)
list(APPEND EXTRA_LIBS SortFunctions)
#list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/LibraryA")

add_executable(CodeFun main.cpp)

target_link_libraries(CodeFun PUBLIC ${EXTRA_LIBS})
target_include_directories(CodeFun PUBLIC "${PROJECT_BINARY_DIR}")

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
