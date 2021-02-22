/// \file SxExperimentImportSingleDataComponent.h
/// \brief SxExperimentImportSingleDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentImportSingleDataComponent
/// \brief Component to import one data file
class SCIXTRACERAPP_EXPORT SxExperimentImportSingleDataComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentImportSingleDataComponent(SxExperimentContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

private slots:
    void browseDataButtonClicked();
    void importButtonClicked();

private:
    SxExperimentContainer* m_container;

private:
    QWidget* m_widget;
    QLineEdit* m_dataPath;
    QCheckBox* m_copyDataBox;
    QLineEdit* m_nameEdit;
    QLineEdit* m_formatEdit;
    QLineEdit* m_authorEdit;
    QLineEdit* m_createddateEdit;
};