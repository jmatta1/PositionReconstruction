cmake_minimum_required (VERSION 2.6)
project (PositionReconstruction)

# force the existence of the BOOST library package
find_package(Boost COMPONENTS thread log log_setup filesystem date_time REQUIRED)
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT COMPONENTS Core RIO Hist Tree REQUIRED)

# MESSAGE( STATUS "Root Library List:    " ${ROOT_LIBRARIES})

# Add the generated file header directory in this way to allow files in the
# utility directory to access the generated file as if it was
include_directories("${PROJECT_BINARY_DIR}/Utility")
# Add the generated file header directory in this way to allow files not in the
# utility directory to access the generated file as OrchidConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# include the file where I define a couple of compiler flags, including the long
# lists of warning flags for the compiler
include(./CMakeFlagDefs.txt)

# add our default g++ flags
#add_definitions(-m64 -std=c++14 -D_FILE_OFFSET_BITS=64 -lpthread -I/usr/local/include/root)
add_definitions(-m64 -march=native -mtune=native -std=c++11 -D_FILE_OFFSET_BITS=64)

# a little hack to make Qt Creator a little happier when it runs cmake to get
# the project files

# check for each supported build type and add the appropriate g++ flags
if(BUILD_TYPE STREQUAL "Release")
    add_definitions(${GCC_OPT_FLAG})
elseif(BUILD_TYPE STREQUAL "Debug")
    add_definitions(${GCC_DEB_FLAG})
elseif(BUILD_TYPE STREQUAL "OptDebug")
    add_definitions(${GCC_DEB_FLAG})
    add_definitions(${GCC_OPT_FLAG})
elseif(BUILD_TYPE STREQUAL "Warn")
    add_definitions(${WARN_FLAGS})
elseif(BUILD_TYPE STREQUAL "Warn_Opt")
    add_definitions(${WARN_FLAGS})
    add_definitions(${WARN_OPT_FLAGS})
endif(BUILD_TYPE STREQUAL "Release")

# include the boost header dir in my system
include_directories( ${Boost_INCLUDE_DIR} )
# include the root header dir
include_directories( ${ROOT_INCLUDE_DIRS} )

# Grab all the source files
file(GLOB_RECURSE SRCS *.cpp)

# Grab all the header files
file(GLOB_RECURSE HDRS *.h)

# set things up so that files include as if they were at the root of the dir
# tree unless they are including a file within their own folder
include_directories(".")

# Set the executable and what it depends on
add_executable(positionReconstruction ${SRCS} ${HDRS})

# make sure that the system knows to link the boost libraries
# target_link_libraries(orchidReader ${Boost_LIBRARIES})
# target_link_libraries(positionReconstruction ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(positionReconstruction ${ROOT_LIBRARIES})
