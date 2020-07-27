
################################
# GTest
################################
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. 
add_subdirectory(googletest)

file (GLOB SOURCE_FILES *.cpp)
add_executable(htest ${SOURCE_FILES})
# target_link_libraries(htest 
#   debug gtestd 
#   debug gtest_maind
#   optimized gtest
#   optimized gtest_main
# )
target_link_libraries(htest gtest gtest_main SortFunctions)
