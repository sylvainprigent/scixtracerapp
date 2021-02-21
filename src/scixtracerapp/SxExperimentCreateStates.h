/// \file SxExperimentCreateStates.h
/// \brief SxExperimentCreateStates class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxframeworkExport.h"

#include <sxframework>

/// \class SxExperimentCreateStates
/// \brief States for a experiment create editor
class SXFRAMEWORK_EXPORT SxExperimentCreateStates : public SxfStates{ 

public:
 
    static QString CreateClicked;
    static QString CancelClicked;
    static QString ExperimentCreated;
    static QString ExperimentCreationError;

};