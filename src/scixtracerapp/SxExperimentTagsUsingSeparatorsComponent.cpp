/// \file SxExperimentTagsUsingSeparatorsComponent.cpp
/// \brief SxExperimentTagsUsingSeparatorsComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentTagsUsingSeparatorsComponent.h"
#include "SxExperimentStates.h"

SxExperimentTagsUsingSeparatorsComponent::SxExperimentTagsUsingSeparatorsComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxExperimentTagsUsingSeparatorsComponent";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QWidget();
    m_widget->setAttribute(Qt::WA_StyledBackground, true);
    m_widget->setObjectName("SxWidget");

    QGridLayout* layout = new QGridLayout();
    m_widget->setLayout(layout);

    // title
    QLabel* title = new QLabel(m_widget->tr("Tag using separator"));
    title->setObjectName("SxLabelFormHeader1");

    QWidget* gridWidget = new QWidget();
    m_gridLayout = new QGridLayout();
    gridWidget->setLayout(m_gridLayout);

    QLabel* tagLabel = new QLabel(m_widget->tr("Tag"));
    tagLabel->setObjectName("SxWidget");
    QLabel* separatorLabel = new QLabel(m_widget->tr("Separator"));
    separatorLabel->setObjectName("SxWidget");
    QLabel* positionLabel = new QLabel(m_widget->tr("Position"));
    positionLabel->setObjectName("SxWidget");

    QLineEdit* tagsEdit = new QLineEdit();
    m_tagsEdit.append(tagsEdit);
    QLineEdit* separatorEdit = new QLineEdit();
    m_separatorEdit.append(separatorEdit);
    QSpinBox* positionSpinBox = new QSpinBox();
    m_positionSpinBox.append(positionSpinBox);

    QPushButton* addLineButton = new QPushButton(m_widget->tr("Add line"));
    addLineButton->setObjectName("btnDefault");
    connect(addLineButton, SIGNAL(released()), this, SLOT(addLine()));

    QPushButton* validateButton = new QPushButton(m_widget->tr("Validate"));
    validateButton->setObjectName("btnPrimary");
    connect(validateButton, SIGNAL(released()), this, SLOT(validated()));

    layout->addWidget(title, 0, 0, 1, 3);
        
    m_gridLayout->addWidget(tagLabel, 0, 0);
    m_gridLayout->addWidget(separatorLabel, 0, 1);
    m_gridLayout->addWidget(positionLabel, 0, 2);

    m_gridLayout->addWidget(tagsEdit, 1, 0);
    m_gridLayout->addWidget(separatorEdit, 1, 1);
    m_gridLayout->addWidget(positionSpinBox, 1, 2);

    layout->addWidget(gridWidget, 1, 0, 1, 3);
    layout->addWidget(addLineButton, 2, 0);
    layout->addWidget(validateButton, 3, 2);

}

void SxExperimentTagsUsingSeparatorsComponent::validated()
{
    QStringList tags;
    QStringList separator;
    QList<int> position;
    for (int i = 0 ; i < m_tagsEdit.count() ; ++i)
    {
        tags.append(m_tagsEdit[i]->text()); 
    }
    for (int i = 0 ; i < m_separatorEdit.count() ; ++i)
    {
        separator.append(m_separatorEdit[i]->text());
    }
    for (int i = 0 ; i < m_positionSpinBox.count() ; ++i)
    {
        position.append(m_positionSpinBox[i]->value()); 
    }

    m_container->get_tag_info()->set_usingseparator_tags(tags);
    m_container->get_tag_info()->set_usingseparator_separator(separator);
    m_container->get_tag_info()->set_usingseparator_position(position);
    m_container->send(SxExperimentStates::TagUsingSeparators);
}

void SxExperimentTagsUsingSeparatorsComponent::addLine()
{
    QLineEdit* tagsEdit = new QLineEdit();
    m_tagsEdit.append(tagsEdit);
    QLineEdit* separatorEdit = new QLineEdit();
    m_separatorEdit.append(separatorEdit);
    QSpinBox* positionSpinBox = new QSpinBox();
    m_positionSpinBox.append(positionSpinBox);

    int rowIdx = m_gridLayout->count();
    m_gridLayout->addWidget(tagsEdit, rowIdx, 0);
    m_gridLayout->addWidget(separatorEdit, rowIdx, 1);
    m_gridLayout->addWidget(positionSpinBox, rowIdx, 2);
}

void SxExperimentTagsUsingSeparatorsComponent::update(SxfAction*)
{
    return;
}  

QWidget* SxExperimentTagsUsingSeparatorsComponent::getWidget()
{
    return m_widget;
}
  