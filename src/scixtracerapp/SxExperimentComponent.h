/// \file SxExperimentComponent.h
/// \brief SxExperimentComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentContainer.h"
#include "SxRawDataContainer.h"
#include "SxProcessedDataContainer.h"
#include "SxRunContainer.h"
#include "SxMetadataExperimentContainer.h"

#include "SxExperimentModel.h"
#include "SxRawDataModel.h"
#include "SxProcessedDataModel.h"
#include "SxRunModel.h"
#include "SxMetadataExperimentModel.h"

#include "SxExperimentToolbarComponent.h"
#include "SxExperimentDataSetListComponent.h"
#include "SxExperimentDataSetViewComponent.h"
#include "SxRawDataComponent.h"
#include "SxProcessedDataComponent.h"
#include "SxMetadataRunComponent.h"
#include "SxMetadataExperimentComponent.h"
#include "SxExperimentImportComponent.h"
#include "SxExperimentTagComponent.h"

#include "SxExperimentModel.h"
#include "SxRawDataModel.h"
#include "SxProcessedDataModel.h"
#include "SxRunModel.h"
#include "SxMetadataExperimentModel.h"

#include "scixtracerappExport.h"

/// \class SxExperimentComponent
/// \brief Main component to manipulate SxExperiment metadata
class SCIXTRACERAPP_EXPORT SxExperimentComponent : public SxfComponent{ 

    Q_OBJECT

public:
    SxExperimentComponent(SxExperimentContainer* container);
    ~SxExperimentComponent();

public:
    /// \brief Trigerred when an action is emitted 
    /// \param[in] action Pointer to the action container
    void update(SxfAction* action);
    /// \brief Get the component graphical widget
    /// \return Pointer to the widget
    QWidget* getWidget();

protected slots:
    void hideDataComponents();

private:
    QWidget* m_widget;

    //containers
    SxExperimentContainer* m_container; 
    SxRawDataContainer* m_rawDataContainer;  
    SxProcessedDataContainer *m_processedDataContainer; 
    SxRunContainer* m_runContainer;
    SxMetadataExperimentContainer* m_metadataExperimentContainer;

    // model
    SxExperimentModel* m_experimentModel;
    SxRawDataModel* m_rawDataModel;
    SxProcessedDataModel *m_processedDataModel;
    SxRunModel* m_runModel;
    SxMetadataExperimentModel *m_metadataExperimentModel;

    // components
    SxExperimentToolbarComponent* m_toolbarComponent;
    SxExperimentDataSetListComponent* m_datasetListComponent;
    SxExperimentDataSetViewComponent* m_datasetViewComponent;
    SxRawDataComponent* m_rawDataComponent;
    SxProcessedDataComponent* m_processedDataComponent;
    SxMetadataRunComponent* m_runComponent;
    SxMetadataExperimentComponent* m_metadataExperimentComponent;
    SxExperimentImportComponent* m_importComponent;
    SxExperimentTagComponent* m_tagComponent;
};
