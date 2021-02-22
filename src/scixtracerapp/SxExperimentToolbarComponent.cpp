/// \file SxExperimentToolbarComponent.cpp
/// \brief SxExperimentToolbarComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021


#include "SxExperimentToolbarComponent.h" 
#include "SxExperimentStates.h"

SxExperimentToolbarComponent::SxExperimentToolbarComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxBrowserExperimentToolbar";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QWidget();
    m_widget->setObjectName("SxToolBar");
    m_widget->setAttribute(Qt::WA_StyledBackground, true);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->setSpacing(1);
    m_widget->setLayout(layout);

    // info
    QToolButton* infoButton = new QToolButton();
    infoButton->setObjectName("SxBrowserExperimentToolbarInfoButton");
    infoButton->setToolTip(m_widget->tr("Information"));
    connect(infoButton, SIGNAL(released()), this, SLOT(infoButtonClicked()));
    layout->addWidget(infoButton, 0, Qt::AlignLeft);

    // import
    QToolButton* importButton = new QToolButton();
    importButton->setObjectName("SxBrowserExperimentToolbarImportButton");
    importButton->setToolTip(m_widget->tr("Import data"));
    connect(importButton, SIGNAL(released()), this, SLOT(importButtonClicked()));
    layout->addWidget(importButton, 0, Qt::AlignLeft);
        
    // tags
    QToolButton* tagButton = new QToolButton();
    tagButton->setObjectName("SxBrowserExperimentToolbarTagButton");
    tagButton->setToolTip(m_widget->tr("Tag data"));
    connect(tagButton, SIGNAL(released()), this, SLOT(tagButtonClicked()));
    layout->addWidget(tagButton, 0, Qt::AlignLeft);

    // process
    QToolButton* processButton = new QToolButton();
    processButton->setObjectName("SxBrowserExperimentToolbarProcessButton");
    processButton->setToolTip(m_widget->tr("Process data"));
    connect(processButton, SIGNAL(released()), SLOT(processButtonClicked()));
    layout->addWidget(processButton, 0, Qt::AlignLeft);

    // refresh
    QToolButton* refreshButton = new QToolButton();
    refreshButton->setObjectName("SxBrowserExperimentToolbarRefreshButton");
    refreshButton->setToolTip(m_widget->tr("Refresh"));
    connect(refreshButton, SIGNAL(released()), this, SLOT(refreshButtonClicked()));
    layout->addWidget(refreshButton, 0, Qt::AlignLeft);

    // experiment name
    m_nameLabel = new QLabel();
    m_nameLabel->setObjectName("SxLabel");
    m_nameLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    layout->addWidget(new QWidget(), 1, Qt::AlignRight);
    layout->addWidget(m_nameLabel, 0, Qt::AlignRight);

    // close button
    QToolButton* closeButton = new QToolButton();
    closeButton->setObjectName("SxBrowserExperimentToolbarCloseButton");
    connect(closeButton, SIGNAL(released()), this, SLOT(closeButtonClicked()));
    layout->addWidget(new QWidget(), 1, Qt::AlignRight);
    layout->addWidget(closeButton, 0, Qt::AlignRight);
}

void SxExperimentToolbarComponent::updateTitle()
{
    m_nameLabel->setText(m_container->get_experiment()->get_name());
}

void SxExperimentToolbarComponent::infoButtonClicked()
{
    m_container->send(SxExperimentStates::EditInfoClicked);
}

void SxExperimentToolbarComponent::importButtonClicked()
{
    m_container->send(SxExperimentStates::ImportClicked);
}

void SxExperimentToolbarComponent::tagButtonClicked()
{
    m_container->send(SxExperimentStates::TagClicked);    
}

void SxExperimentToolbarComponent::processButtonClicked()
{
    m_container->send(SxExperimentStates::ProcessClicked); 
}

void SxExperimentToolbarComponent::refreshButtonClicked()
{
    m_container->send(SxExperimentStates::RefreshClicked);  
}

void SxExperimentToolbarComponent::closeButtonClicked()
{
    m_container->send(SxExperimentStates::CloseClicked);  
}

void SxExperimentToolbarComponent::update(SxfAction* action)
{
    if (action->state() == SxExperimentStates::Loaded)
    {
        m_nameLabel->setText(m_container->get_experiment()->get_name());  
    } 
} 

QWidget* SxExperimentToolbarComponent::getWidget()
{
    return m_widget;
}