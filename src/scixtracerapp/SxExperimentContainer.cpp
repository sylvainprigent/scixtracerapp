/// \file SxExperimentContainer.cpp
/// \brief SxExperimentContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentContainer.h"

SxExperimentContainer::SxExperimentContainer(SxfContainer* parent) : SxfContainer(parent)
{
    m_clickedRow = -1;
}
SxExperimentContainer::~SxExperimentContainer()
{

}

QString SxExperimentContainer::get_experiment_uri()
{
    return m_experiment_uri;
}

SxExperiment* SxExperimentContainer::get_experiment()
{
    return m_experiment;
}

SxExperimentImportContainer* SxExperimentContainer::get_import_info()
{
    return m_import_info;
}

SxExperimentTagContainer* SxExperimentContainer::get_tag_info()
{
    return m_tag_info;
}

QString SxExperimentContainer::get_current_dataset_name()
{
    return m_current_dataset_name;
}

SxDataset* SxExperimentContainer::get_current_dataset()
{
    return m_current_dataset;
}

int SxExperimentContainer::get_clickedRow()
{
    return m_clickedRow;
}

void SxExperimentContainer::set_experiment_uri(const QString value)
{
    m_experiment_uri = value;
}

void SxExperimentContainer::set_experiment(SxExperiment* value)
{
    m_experiment = value;
}

void SxExperimentContainer::set_import_info(SxExperimentImportContainer* value)
{
    m_import_info = value;
}

void SxExperimentContainer::set_tag_info(SxExperimentTagContainer* value)
{
    m_tag_info = value;
}

void SxExperimentContainer::set_current_dataset_name(const QString& value)
{
    m_current_dataset_name = value;
}

void SxExperimentContainer::set_current_dataset(SxDataset* value)
{
    m_current_dataset = value;
}

void SxExperimentContainer::set_clickedRow(const int& value)
{
    m_clickedRow = value;
}