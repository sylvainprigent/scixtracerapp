/// \file SxRawDataComponent.h
/// \brief SxRawDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxRawDataContainer.h"

#include "scixtracerappExport.h"

/// \class SxRawDataComponent
/// \brief Main component to manipulate SxExperiment metadata
class SCIXTRACERAPP_EXPORT SxRawDataComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxRawDataComponent(SxRawDataContainer* container);

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
    SxRawDataContainer* m_container;

protected:
    QScrollArea *m_widget;
    QList<QWidget*> m_tagWidgets;
    QLineEdit* m_uriEdit;
    QLineEdit* m_nameEdit;
    QLineEdit* m_formatEdit;
    QLineEdit* m_dateEdit;
    QLineEdit* m_authorEdit;
    QGridLayout* m_tagsLayout;
};