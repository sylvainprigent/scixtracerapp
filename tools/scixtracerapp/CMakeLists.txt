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
project(scixtracerapptool)

## #################################################################
## Define files
## #################################################################
include_directories(${simageviewer_SRC_INCLUDE_DIR})

SET(SRC_FILES 
	)

## #################################################################
## Exe generation
## #################################################################
SET(NAME SciXtracerApp)
SET(FILE ${SRC_FILES} demo.cpp )
add_executable( ${NAME} ${FILE} )
target_link_libraries(${NAME} sxframework scixtracerapp ${SL_LIBRARIES})
