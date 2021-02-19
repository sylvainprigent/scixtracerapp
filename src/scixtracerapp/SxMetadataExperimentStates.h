/// \file SxMetadataExperimentStates.h
/// \brief SxMetadataExperimentStates class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxframeworkExport.h"

#include <sxframework>

/// \class SxMetadataExperimentStates
/// \brief States for a experiment metadata editor container
class SXFRAMEWORK_EXPORT SxMetadataExperimentStates : public SxfStates{ 

public:
    static QString Loaded;
    static QString SaveClicked;
    static QString Saved;
};