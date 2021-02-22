/// \file SxExperimentDataSetViewComponent.h
/// \brief SxExperimentDataSetViewComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentDataSetViewComponent
/// \brief Component to create a new experiment
class SCIXTRACERAPP_EXPORT SxExperimentDataSetViewComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentDataSetViewComponent(SxExperimentContainer* container);

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

public:

private slots:
    void cellClicked(int row, int col);
    void cellDoubleClicked(int row, int col);
    void highlightLine(int row);

private:
    void drawRawDataset();
    void drawProcessedDataSet();

private:
    SxExperimentContainer* m_container;   

private:
    QWidget* m_widget;
    QTableWidget* m_tableWidget;
};
