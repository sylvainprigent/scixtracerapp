/// \file SxExperimentImportComponent.cpp
/// \brief SxExperimentImportComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentImportComponent.h"

#include "SxExperimentImportSingleDataComponent.h"
#include "SxExperimentImportDirectoryDataComponent.h"

SxExperimentImportComponent::SxExperimentImportComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxExperimentImportComponent";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QWidget();
    m_widget->setAttribute(Qt::WA_StyledBackground, true);
    m_widget->setObjectName("SxWidget");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    m_widget->setLayout(layout);
    QTabWidget* tabWidget = new QTabWidget();
    layout->addWidget(tabWidget);

    SxExperimentImportSingleDataComponent* importSingleComponent = new SxExperimentImportSingleDataComponent(container);
    tabWidget->addTab(importSingleComponent->getWidget(), m_widget->tr("Single Data"));

    SxExperimentImportDirectoryDataComponent* importDirectoryComponent = new SxExperimentImportDirectoryDataComponent(container);
    tabWidget->addTab(importDirectoryComponent->getWidget(), m_widget->tr("Multiple Data"));
}

void SxExperimentImportComponent::update(SxfAction* action)
{
    return;
}

QWidget* SxExperimentImportComponent::getWidget()
{
    return m_widget;
}
        