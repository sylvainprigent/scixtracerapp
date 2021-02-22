/// \file SxExperimentImportComponent.h
/// \brief SxExperimentImportComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentImportComponent
/// \brief Main component to import data
class SCIXTRACERAPP_EXPORT SxExperimentImportComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentImportComponent(SxExperimentContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

private:
    SxExperimentContainer* m_container;   

private:
    QWidget* m_widget;
};
