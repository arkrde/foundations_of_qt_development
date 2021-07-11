add_executable(ch-1-10 main.cpp)

add_library(ch-1-10-lib myclass.h myclass.cpp)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
target_link_libraries(ch-1-10-lib PUBLIC Qt6::Widgets)
target_link_libraries(ch-1-10 PUBLIC ch-1-10-lib)
