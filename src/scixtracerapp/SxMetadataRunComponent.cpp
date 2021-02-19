/// \file SxMetadataRunComponent.cpp
/// \brief SxMetadataRunComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxMetadataRunComponent.h"
#include "SxRunStates.h"

SxMetadataRunComponent::SxMetadataRunComponent(SxRunDataContainer* container) : SxfComponent()
{
    m_objectName = "SxMetadataRunComponent";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QScrollArea();
    m_widget->setObjectName("SxWidget");
    m_widget->setWidgetResizable(true);
    m_widget->setMinimumWidth(150);

    QWidget* widget = new QWidget();
    widget->setAttribute(Qt::WA_StyledBackground, true);
    widget->setObjectName("BiSideBar");
    QGridLayout* layout = new QGridLayout();
    widget->setLayout(layout);
    m_widget->setWidget(widget);

    QLabel* toolLabel = new QLabel("Tool");
    m_toolEdit = new QLineEdit();
    m_toolEdit->setEnabled(false);

    QLabel* tooluriLabel = new QLabel("Name");
    m_tooluriEdit = new QLineEdit();
    m_tooluriEdit->setEnabled(false);

    QLabel* parametersLabel = new QLabel("Parameters");
    parametersLabel->setObjectName("SxMetadataTitle");

    m_parametersTable = new QTableWidget();

    QLabel* inputsLabel = new QLabel("Inputs");
    inputsLabel->setObjectName("SxMetadataTitle");

    m_inputsTable = new QTableWidget();

    QWidget* tagsWidget = new QWidget();
    m_tagsLayout = new QGridLayout();
    m_tagsLayout->setContentsMargins(0,0,0,0);
    tagsWidget->setLayout(m_tagsLayout);

    layout->addWidget(toolLabel, 0, 0);
    layout->addWidget(m_toolEdit, 0, 1);
    layout->addWidget(tooluriLabel, 1, 0);
    layout->addWidget(m_tooluriEdit, 1, 1);
    layout->addWidget(parametersLabel, 2, 0, 1, 2);
    layout->addWidget(m_parametersTable, 3, 0, 1, 2);
    layout->addWidget(inputsLabel, 4, 0, 1, 2);
    layout->addWidget(m_inputsTable, 5, 0, 1, 2);
    layout->addWidget(new QWidget(), 6, 0, 1, 2, Qt::AlignTop);
}

void SxMetadataRunComponent::update(SxfAction* action)
{
        if (action->state() == SxRunStates::Loaded)
        {
            SxRun* metadata = m_container->get_run();

            m_toolEdit->setText(metadata->get_process_name());
            m_tooluriEdit->setText(metadata->get_process_uri());

            // parameters
            m_parametersTable->setColumnCount(2);
            m_parametersTable->setHorizontalHeaderLabels({"Name", "Value"});
            m_parametersTable->setRowCount(0);
            m_parametersTable->setRowCount(metadata->get_parameters_count());
            int row_idx = 0;
            for (int i = 0 ; i < metadata->get_parameters_count() ; ++i){
                SxRunParameter* param = metadata->get_parameter(i);
                m_parametersTable->setItem(row_idx, 0, new QTableWidgetItem(param->get_name()));
                m_parametersTable->setItem(row_idx, 1, new QTableWidgetItem(param->get_value()));
                row_idx += 1;
            }

            // inputs
            m_inputsTable->setColumnCount(3);
            m_inputsTable->setHorizontalHeaderLabels({"Name", "Dataset", "Query"});
            m_inputsTable->setRowCount(0);
            m_inputsTable->setRowCount(metadata->get_inputs_count());
            row_idx = 0;
            for (int i = 0 ; i < metadata->get_inputs_count() ; ++i){
                SxRunInput* input = metadata->get_input(i);
                m_inputsTable->setItem(row_idx, 0, new QTableWidgetItem(input->get_name()));
                m_inputsTable->setItem(row_idx, 1, new QTableWidgetItem(input->get_dataset()));  
                m_inputsTable->setItem(row_idx, 2, new QTableWidgetItem(input->get_query()));  
                row_idx += 1;
            }
        }
}

QWidget* SxMetadataRunComponent::getWidget()
{ 
    return m_widget;
}      