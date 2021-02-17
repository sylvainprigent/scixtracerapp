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
project(sxhometools)

## #################################################################
## Define files
## #################################################################
include_directories(${simageviewer_SRC_INCLUDE_DIR})

SET(SRC_FILES 
	)

## #################################################################
## Exe generation
## #################################################################
SET(NAME SxHomeDemo)
SET(FILE ${SRC_FILES} demo.cpp )
add_executable( ${NAME} ${FILE} )
target_link_libraries(${NAME} sxwidgets sxframework sxhome ${SL_LIBRARIES})
