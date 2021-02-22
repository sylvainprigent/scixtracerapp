/// \file SxExperimentTagComponent.h
/// \brief SxExperimentTagComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentTagComponent
/// \brief Component for a tag
class SCIXTRACERAPP_EXPORT SxExperimentTagComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentTagComponent(SxExperimentContainer* container);

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