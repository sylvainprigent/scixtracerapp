/// \file SxActuator.h
/// \brief SxActuator class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>

#include "sxframeworkExport.h"
#include "SxActuator.h"

/// \class SxActuator
/// \brief Interface for model. Model interact with the percistance of data
class SXFRAMEWORK_EXPORT SxModel : public SxActuator{ 

    Q_OBJECT

public:
    SxModel();
    ~SxModel();

    virtual void update(SxAction* action) = 0;

};
