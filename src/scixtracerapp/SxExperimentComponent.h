/// \file SxExperimentComponent.h
/// \brief SxExperimentComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "scixtracerappExport.h"

/// \class SxExperimentComponent
/// \brief Main component to manipulate SxExperiment metadata
class SCIXTRACERAPP_EXPORT SxExperimentComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentComponent();
    ~SxExperimentComponent();

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

};
