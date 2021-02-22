/// \file SxExperimentCreateComponent.cpp
/// \brief SxExperimentCreateComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentCreateComponent.h"
#include "SxExperimentCreateStates.h"

SxExperimentCreateComponent::SxExperimentCreateComponent(SxExperimentCreateContainer* container, const QString& default_destination) : SxfComponent()
{
    m_objectName = "SxExperimentCreateComponent";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QWidget();
    m_widget->setObjectName("SxWidget");
    QGridLayout* layout = new QGridLayout();
    m_widget->setLayout(layout);

    // title
    QLabel* title = new QLabel(m_widget->tr("Create experiment"));
    title->setObjectName("SxLabelFormHeader1");
    title->setMaximumHeight(50);

    QLabel* destinationLabel = new QLabel(m_widget->tr("Destination"));
    destinationLabel->setObjectName("SxLabel");
    m_destinationEdit = new QLineEdit();
    m_destinationEdit->setText(default_destination);
    QPushButton* browseButton = new QPushButton(m_widget->tr("..."));
    browseButton->setObjectName("SxBrowseButton");
    connect(browseButton, SIGNAL(released()), this, SLOT(browseButtonClicked()));

    QLabel* nameLabel = new QLabel(m_widget->tr("Experiment name"));
    nameLabel->setObjectName("SxLabel");
    m_nameEdit = new QLineEdit();

    QLabel* authorLabel = new QLabel(m_widget->tr("Author"));
    authorLabel->setObjectName("SxLabel");
    m_authorEdit = new QLineEdit();

    QPushButton* createButton = new QPushButton(m_widget->tr("Create"));
    createButton->setObjectName("btnPrimary");
    connect(createButton, SIGNAL(released()), this, SLOT(createButtonClicked()));

    layout->addWidget(title, 0, 0, 1, 3);
    layout->addWidget(destinationLabel, 1, 0);
    layout->addWidget(m_destinationEdit, 1, 1);
    layout->addWidget(browseButton, 1, 2);
    layout->addWidget(nameLabel, 2, 0);
    layout->addWidget(m_nameEdit, 2, 1, 1, 2);
    layout->addWidget(authorLabel, 3, 0);
    layout->addWidget(m_authorEdit, 3, 1, 1, 2);
    layout->addWidget(createButton, 4, 2, 1, 1, Qt::AlignRight);
    layout->addWidget(new QWidget(), 5, 0, 1, 1, Qt::AlignTop);
}

void SxExperimentCreateComponent::browseButtonClicked()
{
    QString directory = QFileDialog::getExistingDirectory(m_widget, m_widget->tr("Select Directory"),
                                       "",
                                       QFileDialog::ShowDirsOnly
                                       | QFileDialog::DontResolveSymlinks);
    m_destinationEdit->setText(directory);
}

void SxExperimentCreateComponent::createButtonClicked()
{
    m_container->set_experiment_destination_dir(m_destinationEdit->text());
    m_container->set_experiment_name(m_nameEdit->text());
    m_container->set_experiment_author(m_authorEdit->text());
    m_container->send(SxExperimentCreateStates::CreateClicked);
}

void SxExperimentCreateComponent::reset()
{
    m_destinationEdit->setText("");
    m_nameEdit->setText("");
    m_authorEdit->setText(""); 
}   

void SxExperimentCreateComponent::setDestination(const QString& path)
{
    m_destinationEdit->setText(path);
}

void SxExperimentCreateComponent::update(SxfAction* action)
{
    return;
}

QWidget* SxExperimentCreateComponent::getWidget()
{
    return m_widget;
}
        