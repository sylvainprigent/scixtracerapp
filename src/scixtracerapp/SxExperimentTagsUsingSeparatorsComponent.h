/// \file SxExperimentTagsUsingSeparatorsComponent.h
/// \brief SxExperimentTagsUsingSeparatorsComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentTagsUsingSeparatorsComponent
/// \brief Component to create tag from separators in files names
class SCIXTRACERAPP_EXPORT SxExperimentTagsUsingSeparatorsComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentTagsUsingSeparatorsComponent(SxExperimentContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

protected slots:
    void addLine();
    void validated();

protected:
    SxExperimentContainer* m_container;

private:
    QWidget* m_widget;
    QList<QLineEdit*> m_tagsEdit;
    QList<QLineEdit*> m_separatorEdit;
    QList<QSpinBox*> m_positionSpinBox;
    QGridLayout* m_gridLayout;
};