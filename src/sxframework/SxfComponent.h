/// \file SxfComponent.h
/// \brief SxfComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>
#include "SxfActuator.h"

#include "sxframeworkExport.h"

/// \class SxfComponent
/// \brief Define a GUI component
class SXFRAMEWORK_EXPORT SxfComponent : public SxfActuator{ 

    Q_OBJECT

public:
    SxfComponent();
    ~SxfComponent();

    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    virtual void update(SxfAction* action) = 0;
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    virtual QWidget* getWidget() = 0;

};
