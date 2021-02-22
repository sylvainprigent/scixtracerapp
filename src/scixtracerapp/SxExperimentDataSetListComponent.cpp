/// \file SxExperimentDataSetListComponent.cpp
/// \brief SxExperimentDataSetListComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentDataSetListComponent.h"
#include "SxExperimentStates.h"

SxExperimentDataSetListComponent::SxExperimentDataSetListComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxExperimentDataSetListComponent";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QScrollArea();
    m_widget->setObjectName("BiWidget");
    m_widget->setWidgetResizable(true);
    m_widget->setMinimumWidth(150);

    QWidget* widget = new QWidget();
    widget->setObjectName("SxSideBar");
    widget->setAttribute(Qt::WA_StyledBackground, true);
    m_widget->setWidget(widget);

    m_layout = new QVBoxLayout();
    widget->setLayout(m_layout);
}

void SxExperimentDataSetListComponent::datasetClicked(QString name)
{   
    m_container->set_current_dataset_name(name);
    m_container->send(SxExperimentStates::DataSetClicked);
}

void SxExperimentDataSetListComponent::update(SxfAction* action)
{
    if (action->state() == SxExperimentStates::Loaded || action->state() == SxExperimentStates::RefreshClicked)
    {
        this->createDataSetsButton();
    }
}
            
void SxExperimentDataSetListComponent::createDataSetsButton()
{
    // free layout
    for(int i = m_layout->count()-1 ; i >= 0 ; --i)
    {       
        m_layout->itemAt(i)->widget()->deleteLater();
    }

    QLabel* rawLabel = new QLabel("Raw dataset");
    rawLabel->setObjectName("SxSideBarTitle");
    rawLabel->setMaximumHeight(50);

    QLabel* ProcessedLabel = new QLabel("Processed dataset");
    ProcessedLabel->setObjectName("SxSideBarTitle");
    ProcessedLabel->setMaximumHeight(50);
        
    SxButton* dataButton = new SxButton("data");
    dataButton->setContent("data");
    dataButton->setObjectName("BiBrowserShortCutsButton");
    dataButton->setCheckable(true);
    dataButton->setAutoExclusive(true);
    if (m_container->get_current_dataset_name() == "data")
    {
        dataButton->setChecked(true);
    }
    connect(dataButton, SIGNAL(dataButton(QString)), this, SLOT(datasetClicked(QString)));
    
    m_buttons.append(dataButton);

    m_layout->addWidget(rawLabel, 0, Qt::AlignTop);
    m_layout->addWidget(dataButton, 0, Qt::AlignTop);
    m_layout->addWidget(ProcessedLabel, 0, Qt::AlignTop);

    QStringList pdataset_uris = m_container->get_experiment()->get_processed_datasets();
    for(int i = 0 ; i < pdataset_uris.count() ; ++i)
    {
        QString pdataset_uri = pdataset_uris[i];
        SxDataset* pdataset = SxServices::request()->read_processeddataset(pdataset_uri);
        SxButton* datasetButton = new SxButton(pdataset->get_name());
        datasetButton->setContent(pdataset->get_name());
        datasetButton->setObjectName("SxBrowserShortCutsButton");
        datasetButton->setCheckable(true);
        datasetButton->setAutoExclusive(true);
        if (m_container->get_current_dataset_name() == pdataset->get_name()){
                datasetButton->setChecked(true);
        }
        connect(datasetButton, SIGNAL(clickedContent(QString)), this, SLOT(datasetClicked(QString)));
        m_layout->addWidget(datasetButton, 0, Qt::AlignTop);
        m_buttons.append(datasetButton);
    }
    m_layout->addWidget(new QWidget(), 1, Qt::AlignTop);
}

void SxExperimentDataSetListComponent::updateList()
{
    return;
}

QWidget* SxExperimentDataSetListComponent::getWidget()
{ 
    return m_widget;
}
