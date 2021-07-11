add_executable(ch1-13 main.cpp)

find_package(Qt6 COMPONENTS Core)
target_link_libraries(ch1-13 PUBLIC Qt6::Core)
