/// \file SxExperimentDataSetListComponent.h
/// \brief SxExperimentDataSetListComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>
#include <sxwidgets>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentDataSetListComponent
/// \brief Component to view an experiment dataset list
class SCIXTRACERAPP_EXPORT SxExperimentDataSetListComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentDataSetListComponent(SxExperimentContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

private slots:
    void datasetClicked(QString name);

private:
    void createDataSetsButton();
    void updateList();

private:
    SxExperimentContainer* m_container;   

private:
    QScrollArea* m_widget;
    QVBoxLayout* m_layout;
    QList<SxButton*> m_buttons;
};