/// \file SxExperimentTagsListComponent.h
/// \brief SxExperimentTagsListComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentTagsListComponent
/// \brief Component to create tag from files names
class SCIXTRACERAPP_EXPORT SxExperimentTagsListComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentTagsListComponent(SxExperimentContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

protected slots:
    void reload();
    void addButtonClicked();
    void cancelButtonClicked();
    void saveButtonClicked();
    void removeClicked(const QString& tag);

protected:
    SxExperimentContainer* m_container;

private:
    QWidget* m_widget;
    QLineEdit* m_addEdit;
    QWidget* m_tagListWidget;
    QVBoxLayout* m_tagListLayout;
};