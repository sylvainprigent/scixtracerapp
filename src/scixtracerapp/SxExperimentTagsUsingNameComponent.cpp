/// \file SxExperimentTagsUsingNameComponent.cpp
/// \brief SxExperimentTagsUsingNameComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentTagsUsingNameComponent.h"
#include "SxExperimentStates.h"

SxExperimentTagsUsingNameComponent::SxExperimentTagsUsingNameComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxExperimentTagsUsingNameComponent";
    m_container = container;
    m_container->subscribe(this);  

    m_widget = new QWidget();
    m_widget->setAttribute(Qt::WA_StyledBackground, true);
    m_widget->setObjectName("SxWidget");

    QGridLayout* layout = new QGridLayout();
    m_widget->setLayout(layout);

    // title
    QLabel* title = new QLabel(m_widget->tr("Tag using name"));
    title->setObjectName("SxLabelFormHeader1");

    QLabel* tagLabel = new QLabel(m_widget->tr("Tag:"));
    tagLabel->setObjectName("SxWidget");
    m_tagEdit = new QLineEdit();

    QLabel* searchLabel = new QLabel(m_widget->tr("Search names:"));
    searchLabel->setObjectName("SxWidget");
    QWidget* searchWidget = new QWidget();
    m_searchLayout = new QVBoxLayout();
    m_searchLayout->setContentsMargins(0,0,0,0);
    searchWidget->setLayout(m_searchLayout);

    QLineEdit* nameEdit = new QLineEdit();
    m_namesEdit.append(nameEdit);
    m_searchLayout->addWidget(nameEdit);

    QPushButton* addLineButton = new QPushButton(m_widget->tr("Add name"));
    addLineButton->setObjectName("btnDefault");
    connect(addLineButton, SIGNAL(released()), this, SLOT(addLine()));

    QPushButton* validateButton = new QPushButton(m_widget->tr("Validate"));
    validateButton->setObjectName("btnPrimary");
    connect(validateButton, SIGNAL(released()), this, SLOT(validated()));

    layout->addWidget(title, 0, 0);
    layout->addWidget(tagLabel, 1, 0, 1, 1, Qt::AlignTop);
    layout->addWidget(m_tagEdit, 1, 1);
    layout->addWidget(searchLabel, 2, 0, 1, 1, Qt::AlignTop );
    layout->addWidget(searchWidget, 2, 1);
    layout->addWidget(addLineButton, 3, 1);
    layout->addWidget(validateButton, 4, 2);
}

void SxExperimentTagsUsingNameComponent::validated()
{
    QStringList names;
    for (int i = 0 ; i < m_namesEdit.count() ; ++i)
    {
        names.append(m_namesEdit[i]->text());
    }
    m_container->get_tag_info()->set_usingname_tag(m_tagEdit->text());
    m_container->get_tag_info()->set_usingname_search(names);
    m_container->send(SxExperimentStates::TagUsingName);
}

void SxExperimentTagsUsingNameComponent::addLine()
{
    QLineEdit* nameEdit = new QLineEdit();
    m_namesEdit.append(nameEdit);
    m_searchLayout->addWidget(nameEdit);
}

void SxExperimentTagsUsingNameComponent::update(SxfAction*)
{
    return;
}   

QWidget* SxExperimentTagsUsingNameComponent::getWidget()
{
    return m_widget;
}