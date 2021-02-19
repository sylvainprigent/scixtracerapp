/// \file SxProcessedDataComponent.h
/// \brief SxProcessedDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxProcessedDataContainer.h"

#include "scixtracerappExport.h"

/// \class SxProcessedDataComponent
/// \brief Main component to manipulate SxExperiment metadata
class SCIXTRACERAPP_EXPORT SxProcessedDataComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxProcessedDataComponent(SxProcessedDataContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

private slots:
    void emitRun();

private:
    SxProcessedDataContainer* m_container;

private:
    QScrollArea* m_widget;
    QLineEdit* m_uriEdit;
    QLineEdit* m_nameEdit;
    QLineEdit* m_authorEdit;
    QLineEdit* m_dateEdit;
    QLineEdit* m_formatEdit;
    QLineEdit* m_outlabelEdit;
    QLineEdit* m_originEdit;
    QGridLayout* m_tagsLayout;
    QMap<QString, QLineEdit*> m_tagWidgets;

};