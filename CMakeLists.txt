cmake_minimum_required(VERSION 3.21)
project(duplication_finder)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.78.0 COMPONENTS crc)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(duplication_finder src/main.cxx src/processor/file-system-processor.cxx src/processor/file-system-processor.h)
target_link_libraries(duplication_finder ${Boost_LIBRARIES})


