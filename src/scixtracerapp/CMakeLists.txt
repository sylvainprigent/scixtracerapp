############################################################
#
# $Id$
#
# Copyright (c) SImageViewer 2021
#
# AUTHOR:
# Sylvain Prigent
# 

# Project name
project(scixtracerapp)

## #################################################################
## Define files
## #################################################################

SET(SRC_FILES  
  SxExperimentComponent.cpp
  SxMetadataExperimentStates.cpp
  SxProcessedDataStates.cpp
  SxRawDataComponent.cpp
  SxRawDataContainer.cpp
  SxRawDataStates.cpp
  SxRunStates.cpp
)

SET(HEADERS_FILES
  SxExperimentComponent.h
  SxMetadataExperimentStates.h
  SxProcessedDataStates.h
  SxRawDataComponent.h
  SxRawDataContainer.h
  SxRawDataStates.h
  SxRunStates.h
)
  
## #################################################################
## Library target
## #################################################################

add_library(${PROJECT_NAME} ${SRC_FILES} ${HEADERS_FILES})

target_link_libraries(${PROJECT_NAME} scixtracercpp sxframework ${SL_LIBRARIES})


## #################################################################
## Export header file
## #################################################################

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

generate_export_header(${PROJECT_NAME}
  EXPORT_FILE_NAME "${PROJECT_NAME}Export.h")

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}"
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export")
