/// \file SxExperimentImportSingleDataComponent.h
/// \brief SxExperimentImportSingleDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentImportSingleDataComponent.h"
#include "SxExperimentStates.h"

SxExperimentImportSingleDataComponent::SxExperimentImportSingleDataComponent(SxExperimentContainer* container) : SxfComponent()
{    
    m_objectName = "SxExperimentImportSingleDataComponent";
    m_container = container;
    m_container->subscribe(this);  

    m_widget = new QWidget();
    m_widget->setAttribute(Qt::WA_StyledBackground, true);
    m_widget->setObjectName("SxWidget");

    QGridLayout* layout = new QGridLayout();
    m_widget->setLayout(layout);

    // title
    QLabel* title = new QLabel(m_widget->tr("Import single data"));
    title->setObjectName("SxLabelFormHeader1");

    QLabel* dataLabel = new QLabel(m_widget->tr("Data"));
    dataLabel->setObjectName("SxWidget");
    m_dataPath = new QLineEdit();
    QPushButton* browseDataButton = new QPushButton(m_widget->tr("..."));
    browseDataButton->setObjectName("SxBrowseButton");
    connect(browseDataButton, SIGNAL(released()), this, SLOT(browseDataButtonClicked()));

    QLabel* copyDataLabel = new QLabel(m_widget->tr("Copy data"));
    copyDataLabel->setObjectName("SxWidget");
    m_copyDataBox = new QCheckBox();
    m_copyDataBox->setChecked(true);

    QLabel* nameLabel = new QLabel(m_widget->tr("Name"));
    nameLabel->setObjectName("SxWidget");
    m_nameEdit = new QLineEdit();

    QLabel* formatLabel = new QLabel(m_widget->tr("Format"));
    formatLabel->setObjectName("SxWidget");
    m_formatEdit = new QLineEdit();

    QLabel* authorLabel = new QLabel(m_widget->tr("Author"));
    authorLabel->setObjectName("SxWidget");
    m_authorEdit = new QLineEdit();

    QLabel* createddateLabel = new QLabel(m_widget->tr("Created date"));
    createddateLabel->setObjectName("SxWidget");
    m_createddateEdit = new QLineEdit();

    QPushButton* importButton = new QPushButton(m_widget->tr("import"));
    importButton->setObjectName("btnPrimary");
    connect(importButton, SIGNAL(released()), this, SLOT(importButtonClicked()));

    layout->addWidget(title, 0, 0, 1, 3);
    layout->addWidget(dataLabel, 1, 0);
    layout->addWidget(m_dataPath, 1, 1);
    layout->addWidget(browseDataButton, 1, 2);
    layout->addWidget(copyDataLabel, 2, 0);
    layout->addWidget(m_copyDataBox, 2, 1, 1, 2);
    layout->addWidget(nameLabel, 3, 0);
    layout->addWidget(m_nameEdit, 3, 1, 1, 2);
    layout->addWidget(formatLabel, 4, 0);
    layout->addWidget(m_formatEdit, 4, 1, 1, 2);
    layout->addWidget(authorLabel, 5, 0);
    layout->addWidget(m_authorEdit, 5, 1, 1, 2);
    layout->addWidget(createddateLabel, 6, 0);
    layout->addWidget(m_createddateEdit, 6, 1, 1, 2);
    layout->addWidget(importButton, 7, 2, Qt::AlignRight);
}

void SxExperimentImportSingleDataComponent::update(SxfAction* action)
{
    return;
}

void SxExperimentImportSingleDataComponent::importButtonClicked()
{
    SxExperimentImportContainer* import_info = m_container->get_import_info();
    import_info->set_file_data_path(m_dataPath->text());
    import_info->set_file_copy_data(m_copyDataBox->isChecked());
    import_info->set_file_name(m_nameEdit->text());
    import_info->set_format(m_formatEdit->text());
    import_info->set_author(m_authorEdit->text());
    import_info->set_createddate(m_createddateEdit->text());
    m_container->send(SxExperimentStates::NewImportFile);
}

void SxExperimentImportSingleDataComponent::browseDataButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(m_widget, m_widget->tr("Import file"), "Data (*.*)");
    m_dataPath->setText(fileName[0]);
}

QWidget* SxExperimentImportSingleDataComponent::getWidget()
{
    return m_widget;  
}
