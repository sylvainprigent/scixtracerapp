/// \file SxfModel.h
/// \brief SxfModel class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>

#include "sxframeworkExport.h"
#include "SxfActuator.h"

/// \class SxfModel
/// \brief Interface for model. Model interact with the percistance of data
class SXFRAMEWORK_EXPORT SxfModel : public SxfActuator{ 

    Q_OBJECT

public:
    SxfModel();
    ~SxfModel();

    virtual void update(SxfAction* action) = 0;

};
