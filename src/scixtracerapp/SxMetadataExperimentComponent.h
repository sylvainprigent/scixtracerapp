/// \file SxMetadataExperimentComponent.h
/// \brief SxMetadataExperimentComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxMetadataExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxMetadataExperimentComponent
/// \brief Component to manipulate SxExperiment metadata
class SCIXTRACERAPP_EXPORT SxMetadataExperimentComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxMetadataExperimentComponent(SxMetadataExperimentContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

protected slots:
    void saveButtonClicked();

protected:
    SxMetadataExperimentContainer* m_container;

private:
    QWidget* m_widget;
    QLineEdit* m_nameEdit;
    QLineEdit* m_authorEdit;
    QLineEdit* m_createddateEdit;
};