/// \file SxMetadataRunComponent.h
/// \brief SxMetadataRunComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxRunContainer.h"

#include "scixtracerappExport.h"

/// \class SxMetadataRunComponent
/// \brief Component to manipulate SxRun metadata
class SCIXTRACERAPP_EXPORT SxMetadataRunComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxMetadataRunComponent(SxRunContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

private:
    SxRunContainer* m_container;

private:
    QScrollArea* m_widget;
    QLineEdit* m_toolEdit;
    QLineEdit* m_tooluriEdit;
    QTableWidget* m_parametersTable;
    QTableWidget* m_inputsTable;
    QGridLayout* m_tagsLayout;
};