set(cmake_version 3.18.3)

cmake_minimum_required(VERSION ${cmake_version})

set(ProjectName "packet-info")

project(${ProjectName}
		VERSION 0.1.1
		LANGUAGES CXX)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# To organize targets into groups when using IDE like XCode or VisualStudio, etc.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Create header-only library
add_library(packet_info INTERFACE)
target_sources(packet_info INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/packet_info/packet_info.h)
target_include_directories(
	packet_info INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Create groups in the IDE which mirrors directory structure on the hard disk
get_target_property(packet_info_sources packet_info SOURCES)
source_group(
  TREE   ${CMAKE_CURRENT_SOURCE_DIR}/include
  FILES  ${packet_info}
)

# Things typically only needed if we are the top level project
if(TEST_PACKET_INFO OR CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  # Setup testing
  add_subdirectory(tests)
endif()