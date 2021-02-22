/// \file SxExperimentDataSetViewComponent.cpp
/// \brief SxExperimentDataSetViewComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentDataSetViewComponent.h"
#include "SxExperimentStates.h"

SxExperimentDataSetViewComponent::SxExperimentDataSetViewComponent(SxExperimentContainer* container) : SxfComponent()
{ 
    m_objectName = "SxExperimentDataSetComponent";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QWidget();
    m_widget->setObjectName("SxWidget");
    m_widget->setAttribute(Qt::WA_StyledBackground, true);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(3,3,3,3);
    m_widget->setLayout(layout);

    m_tableWidget = new QTableWidget();
    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_tableWidget->setColumnCount(4);

    QStringList labels = {"", "Name", "Author", "Date"};
    m_tableWidget->setHorizontalHeaderLabels(labels);
    m_tableWidget->horizontalHeader()->setStretchLastSection(true);

    connect(m_tableWidget, SIGNAL(cellClicked()), this, SLOT(cellClicked()));
    connect(m_tableWidget, SIGNAL(cellDoubleClicked()), this, SLOT(cellDoubleClicked()));
    
    layout->addWidget(m_tableWidget);
} 

void SxExperimentDataSetViewComponent::update(SxfAction* action)
{
    if (action->state() == SxExperimentStates::DataSetLoaded)
    {
        if (m_container->get_current_dataset_name() == "data")
        {
            this->drawRawDataset();
        }
        else
        {
            this->drawProcessedDataSet();
        }   
    } 
}   
                 
void SxExperimentDataSetViewComponent::drawRawDataset()
{
    // headers
    QStringList tags = m_container->get_experiment()->get_tags_keys();
    m_tableWidget->setColumnCount(4 + tags.count());
    QStringList labels = {"Name"};
    for (int i = 0 ; i < tags.count() ; i++)
    {
        labels.append(tags[i]);
    }
    labels.append("Format");
    labels.append("Author");
    labels.append("Date");
    m_tableWidget->setHorizontalHeaderLabels(labels);

    int exp_size = m_container->get_current_dataset()->get_data_count();
    m_tableWidget->setRowCount(0);
    m_tableWidget->setRowCount(exp_size);
    if (exp_size < 10)
    {
        m_tableWidget->verticalHeader()->setFixedWidth(20);
    }
    else if (exp_size >= 10 && exp_size < 100)
    {
        m_tableWidget->verticalHeader()->setFixedWidth(40);
    }  
    else if (exp_size >= 100 && exp_size < 1000)
    {    
        m_tableWidget->verticalHeader()->setFixedWidth(60);
    } 

    QStringList data_list = m_container->get_current_dataset()->get_data_list();
        
    for (int i = 0 ; i < data_list.count() ; i++)
    {
        SxRawData* raw_metadata = SxServices::request()->read_rawdata(data_list[i]);
        // name
        int col_idx  = 0;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(raw_metadata->get_name()));
        // tags
        for (int t = 0 ; t < tags.count() ; ++t)
        {
            col_idx += 1;
            if (raw_metadata->get_tags()->get_keys().contains(tags[t]))
            {
                m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(raw_metadata->get_tags()->get_tag(tags[t]))); 
            }
        }
        // format
        col_idx += 1;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(raw_metadata->get_format()->get_name()));                
        // author
        col_idx += 1;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(raw_metadata->get_author()->get_username()));
        //created date
        col_idx += 1;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(raw_metadata->get_date()->get_to_string("YYYY-MM-DD")));
    }
}

void SxExperimentDataSetViewComponent::cellClicked(int row, int col)
{
    m_container->set_clickedRow(row);
    this->highlightLine(row);
    if (m_container->get_current_dataset_name() == "data")
    {
        m_container->send(SxExperimentStates::RawDataClicked);
    }
    else
    { 
        m_container->send(SxExperimentStates::ProcessedDataClicked);
    }
}

void SxExperimentDataSetViewComponent::cellDoubleClicked(int row, int col)
{
    QString uri = m_container->get_current_dataset()->get_data_uri(row);
    SxData* data = SxServices::request()->read_rawdata(uri);
    /// \todo implement viewer open    
    //SxDataView* viewer = new SxDataView(data->get_uri(), data->get_format());
    //viewer->show();
}

void SxExperimentDataSetViewComponent::highlightLine(int row)
{
    for (int col = 0 ; col < m_tableWidget->columnCount() ; col++)
    {
        if (m_tableWidget->item(row, col))
        {
            m_tableWidget->item(row, col)->setSelected(true); 
        }
    }
}

void SxExperimentDataSetViewComponent::drawProcessedDataSet()
{
    // headers
    QStringList tags = m_container->get_experiment()->get_tags_keys();
    m_tableWidget->setColumnCount(6 + tags.count());
    QStringList labels = {"Name"};
    labels.append("Parent");
    labels.append("Label");
    for (int i = 0 ; i < tags.count() ; ++i)
    {
        labels.append(tags[i]);
    }
    labels.append("Format");
    labels.append("Author");
    labels.append("Date");
    m_tableWidget->setHorizontalHeaderLabels(labels);

    int exp_size = m_container->get_current_dataset()->get_data_count();
    m_tableWidget->setRowCount(0);
    m_tableWidget->setRowCount(exp_size);
    if (exp_size < 10)
    {
        m_tableWidget->verticalHeader()->setFixedWidth(20);
    }
    else if(exp_size >= 10 and exp_size < 100)
    {
        m_tableWidget->verticalHeader()->setFixedWidth(40);
    }  
    else if (exp_size >= 100 and exp_size < 1000)
    {   
        m_tableWidget->verticalHeader()->setFixedWidth(60);
    }

    QStringList data_list = m_container->get_current_dataset()->get_data_list();
        
    for (int i = 0 ; i < data_list.count() ; ++i)
    {
        SxProcessedData* metadata = SxServices::request()->read_processeddata(data_list[i]);
        SxData* parent_metadata = SxServices::request()->get_parent(data_list[i]);
        SxRawData* origin_metadata = SxServices::request()->get_origin(data_list[i]);
        // name
        int col_idx = 0;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(metadata->get_name()));
        // origin
        col_idx  += 1;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(parent_metadata->get_name()));
        // label
        col_idx  += 1;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(metadata->get_run_output()->get_label()));
        // tags
        if (origin_metadata)
        {
            //tags
            for (int t = 0 ; t < tags.count() ; ++t)
            {
                col_idx += 1;
                if (origin_metadata->get_tags()->get_keys().contains(tags[t]))
                {
                    m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(origin_metadata->get_tags()->get_tag(tags[t])));
                } 
            }
        }
        else
        {
            for (int t = 0 ; t < tags.count() ; ++t)
            {
                col_idx += 1;
                m_tableWidget->setItem(i, col_idx, new QTableWidgetItem("")); 
            } 
        }                
        // format
        col_idx += 1;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(metadata->get_format()->get_name()));                
        // author
        col_idx += 1;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(metadata->get_author()->get_username()));
        // created date
        col_idx += 1;
        m_tableWidget->setItem(i, col_idx, new QTableWidgetItem(metadata->get_date()->get_to_string("YYYY-MM-DD")));
    }
}             

QWidget* SxExperimentDataSetViewComponent::getWidget()
{ 
    return m_widget;
}  