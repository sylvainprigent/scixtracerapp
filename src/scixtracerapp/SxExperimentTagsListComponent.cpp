/// \file SxExperimentTagsListComponent.cpp
/// \brief SxExperimentTagsListComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentTagsListComponent.h"
#include "SxExperimentStates.h"

#include <sxwidgets>

SxExperimentTagsListComponent::SxExperimentTagsListComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxExperimentTagsListComponent";
    m_container = container;
    m_container->subscribe(this);  

    m_widget = new QWidget();
    m_widget->setAttribute(Qt::WA_StyledBackground, true);
    m_widget->setObjectName("SxWidget");

    QVBoxLayout* layout = new QVBoxLayout();
    m_widget->setLayout(layout);

    // title
    QLabel* title = new QLabel(m_widget->tr("Tags"));
    title->setObjectName("SxLabelFormHeader1");

    // add widget
    QWidget* addWidget = new QWidget();
    QHBoxLayout* addLayout = new QHBoxLayout();
    addWidget->setLayout(addLayout);

    m_addEdit = new QLineEdit(m_widget);
    QPushButton* addButton = new QPushButton(m_widget->tr("Add"));
    addButton->setObjectName("btnDefault");
    addLayout->addWidget(m_addEdit);
    addLayout->addWidget(addButton);

    m_tagListWidget = new QWidget();
    m_tagListWidget->setObjectName("SxWidget");
    m_tagListLayout = new QVBoxLayout();
    m_tagListWidget->setLayout(m_tagListLayout);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setObjectName("SxWidget");
    scrollArea->setWidget(m_tagListWidget);

    // button area
    QWidget* buttonsWidget = new QWidget();
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->setContentsMargins(0,0,0,0);
    buttonsLayout->setSpacing(2);
    buttonsWidget->setLayout(buttonsLayout);
    QPushButton* cancelButton = new QPushButton(m_widget->tr("Cancel"));
    cancelButton->setObjectName("btnDefault");
    QPushButton* saveButton = new QPushButton(m_widget->tr("Save"));
    saveButton->setObjectName("btnPrimary");
    buttonsLayout->addWidget(cancelButton, 1, Qt::AlignRight);
    buttonsLayout->addWidget(saveButton, 0, Qt::AlignRight);

    layout->addWidget(title);
    layout->addWidget(addWidget);
    layout->addWidget(scrollArea);
    layout->addWidget(buttonsWidget);

    connect(addButton, SIGNAL(released()), this, SLOT(addButtonClicked()));
    connect(cancelButton, SIGNAL(released()), this, SLOT(cancelButtonClicked()));
    connect(saveButton, SIGNAL(released()), this, SLOT(saveButtonClicked()));
}    

void SxExperimentTagsListComponent::update(SxfAction* action)
{
    if (action->state() == SxExperimentStates::Loaded)
    {
        this->reload();
        return;
    }
}

void SxExperimentTagsListComponent::reload()
{
    // free layout
    for (int i = m_tagListLayout->count()-1 ; i >= 0 ; --i)
    {
        m_tagListLayout->itemAt(i)->widget()->deleteLater();
    }

    // add tags
    QStringList tags_key = m_container->get_experiment()->get_tags_keys();
    for (int i = 0 ; i < tags_key.count() ; ++i)
    {
        SxTagWidget* tagWidget = new SxTagWidget(); 
        tagWidget->setContent(tags_key[i]);
        connect(tagWidget, SIGNAL(remove()), this, SLOT(removeClicked()));
        m_tagListLayout->addWidget(tagWidget);
    }
    m_tagListWidget->adjustSize();
}

void SxExperimentTagsListComponent::addButtonClicked()
{
    if (m_addEdit->text() != "")
    {
        SxTagWidget* tagWidget = new SxTagWidget();
        tagWidget->setContent(m_addEdit->text());
        connect(tagWidget, SIGNAL(remove()), this, SLOT(removeClicked()));
        m_tagListLayout->addWidget(tagWidget);
        m_addEdit->setText("");
        m_tagListLayout->update();
    }
}

void SxExperimentTagsListComponent::cancelButtonClicked()
{
        this->reload();
}

void SxExperimentTagsListComponent::saveButtonClicked()
{
    QStringList tags;
    for (int i = 0 ; i < m_tagListLayout->count() ; ++i)
    {
        QLayoutItem* item = m_tagListLayout->itemAt(i);
        SxTagWidget* widget = dynamic_cast<SxTagWidget*>(item->widget());
        if (widget)
        {
            tags.append(widget->content());
        }
    }
    m_container->get_tag_info()->set_tags(tags);
    m_container->send(SxExperimentStates::TagsModified);
}

void SxExperimentTagsListComponent::removeClicked(const QString& tag)
{
    for(int i = 0 ; i < m_tagListLayout->count() ; ++i)
    {
        QLayoutItem* item = m_tagListLayout->itemAt(i);
        SxTagWidget* widget = dynamic_cast<SxTagWidget*>(item->widget());
        if (widget)
        {
            if (widget->content() == tag)
            {
                QLayoutItem* itemd = m_tagListLayout->takeAt(i);
                itemd->widget()->deleteLater();
            }
        }
    }
    m_tagListWidget->adjustSize(); 
}

QWidget* SxExperimentTagsListComponent::getWidget()
{
    return m_widget;
}