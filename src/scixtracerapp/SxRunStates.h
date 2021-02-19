/// \file SxRunStates.h
/// \brief SxRunStates class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxframeworkExport.h"

#include <sxframework>

/// \class SxRunStates
/// \brief States for a run editor container
class SXFRAMEWORK_EXPORT SxRunStates : public SxfStates{ 

public:
    static QString URIChanged;
    static QString Loaded;  
};