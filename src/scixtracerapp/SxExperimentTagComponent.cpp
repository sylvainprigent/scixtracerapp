/// \file SxExperimentTagComponent.h
/// \brief SxExperimentTagComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentTagComponent.h"

#include "SxExperimentTagsListComponent.h"
#include "SxExperimentTagsUsingSeparatorsComponent.h"
#include "SxExperimentTagsUsingNameComponent.h"

SxExperimentTagComponent::SxExperimentTagComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxExperimentTagComponent";
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

    SxExperimentTagsListComponent* tagsListComponent = new SxExperimentTagsListComponent(m_container);
    SxExperimentTagsUsingSeparatorsComponent* tagUsingSeparatorComponent = new SxExperimentTagsUsingSeparatorsComponent(m_container);
    SxExperimentTagsUsingNameComponent* tagUsingNameComponent = new SxExperimentTagsUsingNameComponent(m_container);

    tabWidget->addTab(tagsListComponent->getWidget(), m_widget->tr("Tags"));
    tabWidget->addTab(tagUsingSeparatorComponent->getWidget(), m_widget->tr("Tag using separator"));
    tabWidget->addTab(tagUsingNameComponent->getWidget(), m_widget->tr("Tag using name"));
}

void SxExperimentTagComponent::update(SxfAction* action)
{
    return;
}

QWidget* SxExperimentTagComponent::getWidget()
{
    return m_widget;
} 