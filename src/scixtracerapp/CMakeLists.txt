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
  SxExperimentContainer.cpp
  SxExperimentCreateStates.cpp
  SxExperimentImportContainer.cpp
  SxExperimentTagContainer.cpp
  SxExperimentStates.cpp
  SxMetadataExperimentComponent.cpp
  SxMetadataExperimentContainer.cpp
  SxMetadataExperimentStates.cpp
  SxMetadataRunComponent.cpp
  SxProcessedDataComponent.cpp
  SxProcessedDataContainer.cpp
  SxProcessedDataStates.cpp
  SxRawDataComponent.cpp
  SxRawDataContainer.cpp
  SxRawDataStates.cpp
  SxRunContainer.cpp
  SxRunStates.cpp
  SxExperimentTagsUsingNameComponent.cpp
  SxExperimentTagsUsingSeparatorsComponent.cpp
  SxExperimentTagsListComponent.cpp
  SxExperimentTagComponent.cpp
  SxExperimentImportDirectoryDataComponent.cpp
  SxExperimentImportSingleDataComponent.cpp
  SxExperimentImportComponent.cpp
  SxExperimentCreateComponent.cpp
  SxExperimentCreateContainer.cpp
  SxExperimentDataSetViewComponent.cpp
  SxExperimentDataSetListComponent.cpp
  SxExperimentToolbarComponent.cpp
  SxExperimentComponent.cpp
  SxRawDataModel.cpp
  SxProcessedDataModel.cpp
  SxRunModel.cpp
  SxMetadataExperimentModel.cpp
  SxExperimentModel.cpp
  SxExperimentCreateModel.cpp
)

SET(HEADERS_FILES
  SxExperimentComponent.h
  SxExperimentContainer.h
  SxExperimentCreateStates.h
  SxExperimentImportContainer.h
  SxExperimentTagContainer.h
  SxExperimentStates.h
  SxMetadataExperimentComponent.h
  SxMetadataExperimentContainer.h
  SxMetadataExperimentStates.h
  SxMetadataRunComponent.h
  SxProcessedDataComponent.h
  SxProcessedDataContainer.h
  SxProcessedDataStates.h
  SxRawDataComponent.h
  SxRawDataContainer.h
  SxRawDataStates.h
  SxRunContainer.h
  SxRunStates.h
  SxExperimentTagsUsingNameComponent.h
  SxExperimentTagsUsingSeparatorsComponent.h
  SxExperimentTagsListComponent.h
  SxExperimentTagComponent.h
  SxExperimentImportDirectoryDataComponent.h
  SxExperimentImportSingleDataComponent.h
  SxExperimentImportComponent.h
  SxExperimentCreateComponent.h
  SxExperimentCreateContainer.h
  SxExperimentDataSetViewComponent.h
  SxExperimentDataSetListComponent.h
  SxExperimentToolbarComponent.h
  SxExperimentComponent.h
  SxRawDataModel.h
  SxProcessedDataModel.h
  SxRunModel.h
  SxMetadataExperimentModel.h
  SxExperimentModel.h
  SxExperimentCreateModel.h
)
  
## #################################################################
## Library target
## #################################################################

add_library(${PROJECT_NAME} ${SRC_FILES} ${HEADERS_FILES})

target_link_libraries(${PROJECT_NAME} scixtracercpp sxframework sxwidgets ${SL_LIBRARIES})


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
