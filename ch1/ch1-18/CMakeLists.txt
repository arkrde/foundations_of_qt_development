add_executable(ch1-18 main.cpp)

find_package(Qt6 COMPONENTS Core REQUIRED)
target_link_libraries(ch1-18 PUBLIC Qt6::Core)
