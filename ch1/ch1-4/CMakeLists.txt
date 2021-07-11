find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(ch1-4 main.cpp)
target_link_libraries(ch1-4 PRIVATE Qt6::Widgets)
