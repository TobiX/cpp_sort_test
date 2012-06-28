set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required

project(cpp_sort_test)
cmake_minimum_required(VERSION 2.8)

# EASTL
include_directories("${PROJECT_SOURCE_DIR}/EASTL/include")

# Qt4
find_package(Qt4)
set(QT_DONT_USE_QTGUI 1)

if (QT4_FOUND)
    include(${QT_USE_FILE})

    add_executable(cpp_sort_test_qt main.cpp)
    set_target_properties(cpp_sort_test_qt PROPERTIES COMPILE_DEFINITIONS BUILD_QT)
    target_link_libraries(cpp_sort_test_qt ${QT_LIBRARIES})
endif(QT4_FOUND)

add_executable(cpp_sort_test_stl main.cpp)
set_target_properties(cpp_sort_test_stl PROPERTIES COMPILE_DEFINITIONS BUILD_STL)

add_executable(cpp_sort_test_eastl main.cpp)
set_target_properties(cpp_sort_test_eastl PROPERTIES COMPILE_DEFINITIONS BUILD_EASTL)
