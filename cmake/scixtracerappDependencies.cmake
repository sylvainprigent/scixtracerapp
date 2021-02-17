############################################################
#
# $Id$
#
# Copyright (c) SciXtracerApp 2021
#
# AUTHOR:
# Sylvain Prigent
# 

## #################################################################
## Qt
## #################################################################
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Threads REQUIRED)
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

set (SL_LIBRARIES ${SL_LIBRARIES} Qt6::Core Qt6::Widgets)


## ##################################################################
## simageio
## ##################################################################
find_package (scixtracercpp REQUIRED)
if ( scixtracercpp_FOUND )
  message(STATUS "Using scixtracercpp")
  set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} ${scixtracercpp_INCLUDE_DIRS})
  set (SL_LIBRARY_DIRS ${SL_LIBRARY_DIRS} ${scixtracercpp_LIBRARY_DIRS})
  set (SL_LIBRARIES ${SL_LIBRARIES} ${scixtracercpp_LIBRARIES})
  message(STATUS "scixtracercpp_LIBRARY_DIRS=" ${scixtracercpp_LIBRARY_DIRS})
  set(scixtracerapp_HAVE_scixtracercpp 1)
else( scixtracercpp_FOUND )
  message(STATUS "NOT Using scixtracercpp")
endif( scixtracercpp_FOUND )

## #################################################################
## Doxygen
## #################################################################

find_package(Doxygen QUIET)
if(${DOXYGEN_FOUND})
  set(SL_USE_DOXYGEN 1)
endif(${DOXYGEN_FOUND})

if(${SL_USE_OPENMP})
  find_package(OpenMP REQUIRED)
endif(${SL_USE_OPENMP})  

## #################################################################
## definitions
## #################################################################
add_definitions (${SL_DEFINITIONS})
include_directories (${SL_INCLUDE_DIRS})
link_directories(${SL_LIBRARY_DIRS})
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SL_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SL_CXX_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set (SL_INCLUDE_DIRS ${SL_INCLUDE_DIRS} CACHE STRING "include directories for spartion dependancies")
set (SL_LIBRARIES ${SL_LIBRARIES} CACHE STRING "spartion required and optional 3rd party libraries")
set (SL_DEFINITIONS ${SL_DEFINITIONS} CACHE STRING "SL_USE_XXX defines")
set (SL_C_FLAGS ${SL_C_FLAGS}  CACHE STRING "c flags for cimg")
set (SL_CXX_FLAGS ${SL_CXX_FLAGS} CACHE STRING "c++ flags for cimg")
 
