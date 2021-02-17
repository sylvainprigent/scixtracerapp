/// \file SxHomeComponent.h
/// \brief SxHomeComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>

#include "sxframeworkExport.h"

#include <sxframework>
#include <sxwidgets>
#include "SxHomeNavbarWidget.h"
#include "SxHomeWidget.h"

/// \class SxHomeComponent
/// \brief GUI component for a home view (tiles and navbar)
class SXHOME_EXPORT SxHomeComponent : public SxComponent{ 

    Q_OBJECT

public:
    SxHomeComponent();
    ~SxHomeComponent();

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

private:
    void addHomeButton();

private slots:
    void showTab(int id);
    void closeTab(int id);

private:
    QWidget* m_widget;
    SxHomeNavbarWidget* m_bar;
    SxSlidingStackedWidget *m_centralWidget;
    SxHomeWidget* m_home;
};
