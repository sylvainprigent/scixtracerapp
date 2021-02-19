/// \file SxfActuator.h
/// \brief SxfActuator class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>

#include "sxframeworkExport.h"

#include "SxfAction.h"

/// \class SxfActuator
/// \brief Actuator mother class for Component and Model
class SXFRAMEWORK_EXPORT SxfActuator : public SxfObject{ 

    Q_OBJECT

public:
    SxfActuator();
    ~SxfActuator();

    virtual void update(SxfAction* action) = 0;

};
