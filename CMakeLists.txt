cmake_minimum_required(VERSION 3.21)
project(duplication_finder)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.78.0 COMPONENTS crc)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(duplication_finder src/main.cc src/processor/file-system-processor.cc src/processor/file-system-processor.h src/processor/check-sum-processor.cc src/processor/check-sum-processor.h src/processor/entity/file.cc src/processor/entity/file.h src/duplication-finder.cc src/duplication-finder.h)
target_link_libraries(duplication_finder ${Boost_LIBRARIES})


