find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(ch1-5 main.cpp)
target_link_libraries(ch1-5 PRIVATE Qt6::Widgets)
