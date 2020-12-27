macro(InitCMake)
    include(FetchContent)
    set (CMake_VERSION 0.1.0)

    message(STATUS "find package: CMake ${CMAKE_VERSION}")
    find_package(CMake, ${CMAKE_VERSION} EXACT QUIET)

    if (NOT CMAKE_FOUND)
        message(STATUS "CMake ${CMAKE_VERSION} not found")
        set (_address )

    endif()


endmacro()