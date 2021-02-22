/// \file SxExperimentToolbarComponent.h
/// \brief SxExperimentToolbarComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentToolbarComponent
/// \brief Component to manipulate SxExperiment metadata
class SCIXTRACERAPP_EXPORT SxExperimentToolbarComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentToolbarComponent(SxExperimentContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

protected slots:
    void updateTitle();
    void infoButtonClicked();
    void importButtonClicked();
    void tagButtonClicked();
    void processButtonClicked();
    void refreshButtonClicked();
    void closeButtonClicked();

protected:
    SxExperimentContainer* m_container;

private:
    QWidget* m_widget;
    QLabel* m_nameLabel;
};