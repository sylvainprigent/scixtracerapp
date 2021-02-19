/// \file SxMetadataExperimentContainer.cpp
/// \brief SxMetadataExperimentContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxMetadataExperimentContainer.h"


SxMetadataExperimentContainer::SxMetadataExperimentContainer(SxfContainer* parent) : SxfContainer(parent)
{
    m_md_uri = "";
    m_experiment = nullptr;
}

SxMetadataExperimentContainer::~SxMetadataExperimentContainer()
{

}

void SxMetadataExperimentContainer::set_md_uri(const QString& uri)
{
    m_md_uri = uri;
}
void SxMetadataExperimentContainer::set_experiment(SxExperiment* experiment)
{
    m_experiment = experiment;
}

QString SxMetadataExperimentContainer::get_md_uri()
{
    return m_md_uri;
}

SxExperiment* SxMetadataExperimentContainer::get_experiment()
{
    return m_experiment;
}
 