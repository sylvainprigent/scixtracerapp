/// \file SxProcessedDataStates.h
/// \brief SxProcessedDataStates class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxframeworkExport.h"

#include <sxframework>

/// \class SxProcessedDataStates
/// \brief States for a processed data editor container
class SXFRAMEWORK_EXPORT SxProcessedDataStates : public SxfStates{ 

public:
    static QString URIChanged;
    static QString Loaded;
    static QString RunOpenClicked;
};