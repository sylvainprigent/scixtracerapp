/// \file SxExperimentImportDirectoryDataComponent.h
/// \brief SxExperimentImportDirectoryDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentImportDirectoryDataComponent
/// \brief Component for a tag
class SCIXTRACERAPP_EXPORT SxExperimentImportDirectoryDataComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentImportDirectoryDataComponent(SxExperimentContainer* container);

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
    QCheckBox* m_recursiveBox;
    QComboBox* m_filterComboBox;
    QLineEdit* m_filterEdit;
    QCheckBox* m_copyDataBox;
    QLineEdit* m_formatEdit;
    QLineEdit* m_authorEdit;
    QLineEdit* m_createddateEdit;
    QProgressBar* m_progressBar;

};