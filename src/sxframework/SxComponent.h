/// \file SxComponent.h
/// \brief SxComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>
#include "SxActuator.h"

#include "sxframeworkExport.h"

/// \class SxComponent
/// \brief Define a GUI component
class SXFRAMEWORK_EXPORT SxComponent : public SxActuator{ 

    Q_OBJECT

public:
    SxComponent();
    ~SxComponent();

    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    virtual void update(SxAction* action) = 0;
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    virtual QWidget* getWidget() = 0;

};
