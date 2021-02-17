/// \file SxActuator.h
/// \brief SxActuator class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>

#include "sxframeworkExport.h"

#include "SxAction.h"

/// \class SxActuator
/// \brief Actuator mother class for Component and Model
class SXFRAMEWORK_EXPORT SxActuator : public SxfObject{ 

    Q_OBJECT

public:
    SxActuator();
    ~SxActuator();

    virtual void update(SxAction* action) = 0;

};
