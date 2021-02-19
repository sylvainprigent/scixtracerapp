/// \file SxProcessedDataContainer.cpp
/// \brief SxProcessedDataContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxProcessedDataContainer.h"


SxProcessedDataContainer::SxProcessedDataContainer(SxfContainer* parent) : SxfContainer(parent)
{
    m_md_uri = "";
    m_processeddata = nullptr;
}

SxProcessedDataContainer::~SxProcessedDataContainer()
{

}

void SxProcessedDataContainer::set_md_uri(const QString& uri)
{
    m_md_uri = uri;
}
void SxProcessedDataContainer::set_processeddata(SxProcessedData* processeddata)
{
    m_processeddata = processeddata;
}

QString SxProcessedDataContainer::get_md_uri()
{
    return m_md_uri;
}

SxProcessedData* SxProcessedDataContainer::get_processeddata()
{
    return m_processeddata;
}
 