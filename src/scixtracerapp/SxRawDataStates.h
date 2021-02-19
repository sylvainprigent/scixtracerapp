/// \file SxRawDataStates.h
/// \brief SxRawDataStates class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxframeworkExport.h"

#include <sxframework>

/// \class SxRawDataStates
/// \brief States for a raw data editor container
class SXFRAMEWORK_EXPORT SxRawDataStates : public SxfStates{ 

public:
    static QString URIChanged;
    static QString Loaded;
    static QString SaveClicked;
    static QString Saved;
};