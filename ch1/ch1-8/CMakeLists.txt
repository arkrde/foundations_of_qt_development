add_executable(ch1-8 main.cpp myclass.h)

add_library(ch1-8-lib myclass.cpp myclass.h)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
target_link_libraries(ch1-8-lib PUBLIC Qt6::Widgets)
target_link_libraries(ch1-8 PUBLIC ch1-8-lib)

