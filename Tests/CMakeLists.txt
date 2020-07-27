
include_directories("${PROJECT_SOURCE_DIR}/gtest/include")
link_directories("${PROJECT_SOURCE_DIR}/gtest/lib")

file (GLOB SOURCE_FILES *.cpp)
add_executable(htest ${SOURCE_FILES})
target_link_libraries(htest 
  debug gtestd
  debug gtest_maind
  optimized gtest
  optimized gtest_main
  SortFunctions
)


