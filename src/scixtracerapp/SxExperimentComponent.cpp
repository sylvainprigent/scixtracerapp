/// \file SxExperimentComponent.cpp
/// \brief SxExperimentComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentComponent.h"


SxExperimentComponent::SxExperimentComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxExperimentComponent";

    // containers
    m_container = container;
    m_container->subscribe(this);
    m_rawDataContainer = new SxRawDataContainer();
    m_rawDataContainer->subscibe(this);
    m_processedDataContainer = new SxProcessedDataContainer();
    m_processedDataContainer->subscribe(this);
    m_runContainer = new SxRunContainer();
    m_runContainer->subscribe(this);
    m_metadataExperimentContainer = new SxMetadataExperimentContainer();
    m_metadataExperimentContainer->subscribe(this);

    // models
    m_experimentModel = new SxExperimentModel(m_container);
    m_rawDataModel = new SxRawDataModel(m_rawDataContainer);
    m_processedDataModel = new SxProcessedDataModel(m_processedDataContainer);
    m_runModel = new SxRunModel(m_runContainer);
    m_metadataExperimentModel = new SxMetadataExperimentModel(m_metadataExperimentContainer);

    // components
    m_toolbarComponent = new SxExperimentToolbarComponent(m_container);
    m_datasetListComponent = new SxExperimentDataSetListComponent(m_container);
    m_datasetViewComponent = new SxExperimentDataSetViewComponent(m_container);
    m_rawDataComponent = new SxRawDataComponent(m_rawDataContainer);
    m_processedDataComponent = new SxProcessedDataComponent(m_processedDataContainer);
    m_runComponent = new SxMetadataRunComponent(m_runContainer);
    m_metadataExperimentComponent = new SxMetadataExperimentComponent(m_metadataExperimentContainer);
    m_importComponent = new SxExperimentImportComponent(m_container);
    m_tagComponent = new SxExperimentTagComponent(m_container);

    // widget
    m_widget = new QWidget();
    m_widget->setObjectName("SxWidget");
    m_widget->setAttribute(Qt::WA_StyledBackground, true);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    m_widget->setLayout(layout);
    QSplitter* splitter = new QSplitter();

    this->hideDataComponents();  

    layout->addWidget(m_toolbarComponent->getWidget());
    layout->addWidget(splitter);
    splitter->addWidget(m_datasetListComponent->getWidget());
    splitter->addWidget(m_datasetViewComponent->getWidget());
    splitter->addWidget(m_rawDataComponent->getWidget());
    splitter->addWidget(m_processedDataComponent->getWidget());

    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 3);
}

SxExperimentComponent::~SxExperimentComponent()
{

}

void SxExperimentComponent::hideDataComponents()
{
    m_rawDataComponent->getWidget()->setVisible(false);  
    m_processedDataComponent->getWidget()->setVisible(false); 
}

void SxExperimentComponent::update(SxfAction* action)
{
    if (action->state() == SxExperimentStates::Loaded)
    {
        m_datasetListComponent->datasetClicked("data");
        m_metadataExperimentContainer->set_experiment(m_container->get_experiment());
        m_metadataExperimentContainer->send(SxMetadataExperimentStates::Loaded);
        return;
    }

    if (action->state() == SxExperimentStates::RawDataClicked)
    {
        m_rawDataContainer->set_md_uri(m_container->get_current_dataset()->get(m_container->clickedRow())->get_md_uri();
        m_rawDataContainer->send(SxRawDataStates::URIChanged);
        m_rawDataComponent->getWidget().setVisible(true);
        m_processedDataComponent->getWidget().setVisible(false);
        return;
    }

    if (action->state() == SxExperimentStates::ProcessedDataClicked)
    {
        m_processedDataContainer->set_md_uri(m_container->get_current_dataset()->get_data(m_container->clickedRow())->get_md_uri();   
        m_processedDataContainer->send(SxProcessedDataStates::URIChanged);
        m_rawDataComponent->getWidget()->setVisible(false);
        m_processedDataComponent->getWidget()->setVisible(true);
        return;
    } 

    if (action->state() == BiRawDataStates::Saved)
    {
        m_datasetListComponent->datasetClicked("data");
        return;
    }

    if (action->state() == SxExperimentStates::EditInfoClicked)
    {
        m_metadataExperimentComponent->getWidget()->setVisible(true);    
        return;
    }

    if (action->state() == BiMetadataExperimentStates::Saved)
    {
        m_metadataExperimentComponent->getWidget()->setVisible(false);   
        m_toolbarComponent->updateTitle(); 
        return;
    }

    if (action->state() == SxExperimentStates::ImportClicked)
    {
        m_importComponent->getWidget()->setVisible(true); 
        return;
    }

    if (action->state() == SxExperimentStates::DataImported)
    {
        m_importComponent->getWidget()->setVisible(false);
        QMessageBox msgBox;
        msgBox->setText("Data imported");
        msgBox.exec(); 
        m_datasetListComponent->datasetClicked("data");
        return;
    }

    if (action->state() == SxExperimentStates::TagClicked)
    {
        m_tagComponent->getWidget()->setVisible(true);
        return;
    }

    if (action->state() == SxExperimentStates::TagsSaved && action.state == SxExperimentStates::DataTagged)
    {
        m_tagComponent->getWidget()->setVisible(false);
        QMessageBox msgBox;
        msgBox.setText("Tags saved");
        msgBox.exec(); 
        m_datasetListComponent->datasetClicked("data");
        return;
    }    

    if (action->state() == SxExperimentStates::ProcessClicked)
    {
        /*
            finder_path = os.path.join(os.path.dirname(
                os.path.realpath(__file__)), '..', '..', 'finderapp.py')
            subprocess.Popen(['python', finder_path]);
        */
    }

    if (action->state() == SxExperimentStates::DataSetClicked)
    {
        this->hideDataComponents();
    }   

    if (action->state() == BiProcessedDataStates::RunOpenClicked)
    {
        m_runContainer->set_md_uri(m_processedDataContainer->get_processeddata()->get_run_uri();   
        m_runContainer->send(BiRunStates::URIChanged);
    } 

    if (action->state() == BiRunStates::Loaded)
    {    
        m_runComponent->getWidget()->setVisible(true);
    } 
}

QWidget* SxExperimentComponent::getWidget()
{
    return m_widget;
}
