add_library(SortFunctions SHARED bubble.cpp)
target_include_directories(SortFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(SortFunctions PRIVATE "EXPORTING_MYMATH")