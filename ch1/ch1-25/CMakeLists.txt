add_executable(ch1-25 main.cpp)

find_package(Qt6 COMPONENTS Core REQUIRED)
target_link_libraries(ch1-25 PUBLIC Qt6::Core)
