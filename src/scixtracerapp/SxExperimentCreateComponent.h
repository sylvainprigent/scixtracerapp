/// \file SxExperimentCreateComponent.h
/// \brief SxExperimentCreateComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentCreateContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentCreateComponent
/// \brief Component to create a new experiment
class SCIXTRACERAPP_EXPORT SxExperimentCreateComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentCreateComponent(SxExperimentCreateContainer* container, const QString& default_destination = "");

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

public:
    void reset();
    void setDestination(const QString& path);

private slots:
    void createButtonClicked();
    void browseButtonClicked();

private:
    SxExperimentCreateContainer* m_container;   

private:
    QWidget* m_widget;
    QLineEdit* m_destinationEdit;
    QLineEdit* m_nameEdit;
    QLineEdit* m_authorEdit;
};
