FILE(GLOB sources
    RELATIVE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/ch*
)
foreach(src ${sources})
    add_subdirectory(${src})
endforeach()
