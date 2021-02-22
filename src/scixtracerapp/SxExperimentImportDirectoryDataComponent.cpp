/// \file SxExperimentImportDirectoryDataComponent.cpp
/// \brief SxExperimentImportDirectoryDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentImportDirectoryDataComponent.h"
#include "SxExperimentStates.h"

SxExperimentImportDirectoryDataComponent::SxExperimentImportDirectoryDataComponent(SxExperimentContainer* container) : SxfComponent()
{
    m_objectName = "SxExperimentImportDirectoryDataComponent";
    m_container = container;
    m_container->subscribe(this);  

    m_widget = new QWidget();
    m_widget->setAttribute(Qt::WA_StyledBackground, true);
    m_widget->setObjectName("SxWidget");

    QGridLayout* layout = new QGridLayout();
    m_widget->setLayout(layout);

    // title
    QLabel* title = new QLabel(m_widget->tr("Import from folder"));
    title->setObjectName("SxLabelFormHeader1");

    QLabel* dataLabel = new QLabel(m_widget->tr("Folder"));
    dataLabel->setObjectName("BiWidget");
    m_dataPath = new QLineEdit();
    QPushButton* browseDataButton = new QPushButton(m_widget->tr("..."));
    browseDataButton->setObjectName("SxBrowseButton");

    connect(browseDataButton, SIGNAL(released()), this, SLOT(browseDataButtonClicked()));
        
    QLabel* recursiveLabel = new QLabel(m_widget->tr("Recursive"));
    recursiveLabel->setObjectName("SxWidget");
    m_recursiveBox = new QCheckBox();
    m_recursiveBox->setChecked(true);

    QLabel* filterLabel = new QLabel(m_widget->tr("Filter"));
    filterLabel->setObjectName("SxWidget");
    m_filterComboBox = new QComboBox();
    m_filterComboBox->addItem(m_widget->tr("Ends With"));
    m_filterComboBox->addItem(m_widget->tr("Start With"));
    m_filterComboBox->addItem(m_widget->tr("Contains"));
    m_filterEdit = new QLineEdit();
    m_filterEdit->setText(".tif");

    QLabel* copyDataLabel = new QLabel(m_widget->tr("Copy data"));
    copyDataLabel->setObjectName("SxWidget");
    m_copyDataBox = new QCheckBox();
    m_copyDataBox->setChecked(true);

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

    layout->addWidget(title, 0, 0, 1, 4);
    layout->addWidget(dataLabel, 1, 0);
    layout->addWidget(m_dataPath, 1, 1, 1, 2);
    layout->addWidget(browseDataButton, 1, 3);
    layout->addWidget(recursiveLabel, 2, 0);
    layout->addWidget(m_recursiveBox, 2, 1, 1, 2);
    layout->addWidget(filterLabel, 3, 0);
    layout->addWidget(m_filterComboBox, 3, 1, 1, 1);
    layout->addWidget(m_filterEdit, 3, 2, 1, 2);
    layout->addWidget(copyDataLabel, 4, 0);
    layout->addWidget(m_copyDataBox, 4, 1, 1, 2);
    layout->addWidget(formatLabel, 5, 0);
    layout->addWidget(m_formatEdit, 5, 1, 1, 2);
    layout->addWidget(authorLabel, 6, 0);
    layout->addWidget(m_authorEdit, 6, 1, 1, 2);
    layout->addWidget(createddateLabel, 7, 0);
    layout->addWidget(m_createddateEdit, 7, 1, 1, 2);
    layout->addWidget(importButton, 8, 3, Qt::AlignRight);

    QProgressBar* m_progressBar = new QProgressBar();
    m_progressBar->setVisible(false);
    layout->addWidget(m_progressBar, 8, 1, 1, 3);
}

void SxExperimentImportDirectoryDataComponent::update(SxfAction* action)
{
    if (action->state() == SxExperimentStates::Progress)
    {
        //if (m_container->get_progress().contains("progress"))
        //{
            m_progressBar->setVisible(true);
            m_progressBar->setValue(m_container->get_progress());
            if (m_container->get_progress() == 100)
            {
                m_progressBar->setVisible(false);
            }
        //}
    }
}

void SxExperimentImportDirectoryDataComponent::importButtonClicked()
{
    SxExperimentImportContainer* importInfo = m_container->get_import_info();
    importInfo->set_dir_data_path(m_dataPath->text());
    importInfo->set_dir_recursive(m_recursiveBox->isChecked()); 
    importInfo->set_dir_filter(m_filterComboBox->currentIndex());
    importInfo->set_dir_filter_value(m_filterEdit->text());
    importInfo->set_dir_copy_data(m_copyDataBox->isChecked());
    importInfo->set_author(m_authorEdit->text());
    importInfo->set_format(m_formatEdit->text());
    importInfo->set_createddate(m_createddateEdit->text());
    m_container->send(SxExperimentStates::NewImportDir);
}

void SxExperimentImportDirectoryDataComponent::browseDataButtonClicked()
{
    QString directory = QFileDialog::getExistingDirectory(m_widget, m_widget->tr("Select Directory"),
                                       "",
                                       QFileDialog::ShowDirsOnly
                                       | QFileDialog::DontResolveSymlinks);
    m_dataPath->setText(directory);
}

QWidget* SxExperimentImportDirectoryDataComponent::getWidget()
{
    return m_widget;  
}
