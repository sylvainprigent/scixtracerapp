/// \file SxMetadataExperimentComponent.cpp
/// \brief SxMetadataExperimentComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxMetadataExperimentComponent.h"
#include "SxMetadataExperimentStates.h"

SxMetadataExperimentComponent::SxMetadataExperimentComponent(SxMetadataExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxMetadataExperimentComponent";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QWidget();
    m_widget->setObjectName("SxWidget");
    m_widget->setAttribute(Qt::WA_StyledBackground, true);

    QGridLayout* layout = new QGridLayout();
    m_widget->setLayout(layout);

    QLabel* title = new QLabel(m_widget->tr("Experiment informations"));
    title->setObjectName("SxLabelFormHeader1");
    title->setMaximumHeight(50);

    QLabel* nameLabel = new QLabel("Name");
    nameLabel->setObjectName("SxLabel");
    m_nameEdit = new QLineEdit();

    QLabel* authorLabel = new QLabel("Author");
    authorLabel->setObjectName("SxLabel");
    m_authorEdit = new QLineEdit();

    QLabel* createddateLabel = new QLabel("Created date");
    createddateLabel->setObjectName("SxLabel");
    m_createddateEdit = new QLineEdit();

    QPushButton* saveButton = new QPushButton(m_widget->tr("Save"));
    saveButton->setObjectName("btnPrimary");
    connect(saveButton, SIGNAL(released()), this, SLOT(saveButtonClicked));

        layout->addWidget(title, 0, 0, 1, 2);
        layout->addWidget(nameLabel, 1, 0);
        layout->addWidget(m_nameEdit, 1, 1);
        layout->addWidget(authorLabel, 2, 0);
        layout->addWidget(m_authorEdit, 2, 1);
        layout->addWidget(createddateLabel, 3, 0);
        layout->addWidget(m_createddateEdit, 3, 1);
        layout->addWidget(saveButton, 4, 0, 1, 2);
        layout->addWidget(new QWidget(), 5, 0, 1, 2, Qt::AlignTop);
}

void SxMetadataExperimentComponent::saveButtonClicked()
{
    SxExperiment* experiment = m_container->get_experiment();
    experiment->set_name(m_nameEdit->text());
    experiment->set_author(new SxUser(m_authorEdit->text()));
    experiment->set_date(new SxDate(m_createddateEdit->text()));

    m_container->send(SxMetadataExperimentStates::SaveClicked);
}

void SxMetadataExperimentComponent::update(SxfAction* action)
{
    if (action->state() == SxMetadataExperimentStates::Loaded)
    {
            m_nameEdit->setText(m_container->get_experiment()->get_name());
            m_authorEdit->setText(m_container->get_experiment()->get_author()->get_username());
            m_createddateEdit->setText(m_container->get_experiment()->get_date()->get_to_string("YYYY-MM-DD"));
    }   

    if (action->state() == SxMetadataExperimentStates::Saved)
    {
        QMessageBox msgBox;
        msgBox.setText("Information have been saved");
        msgBox.exec();  
    }
}

QWidget* SxMetadataExperimentComponent::getWidget()
{ 
    return m_widget;  
}