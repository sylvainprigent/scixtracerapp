/// \file SxRawDataContainer.cpp
/// \brief SxRawDataContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxRawDataContainer.h"


SxRawDataContainer::SxRawDataContainer(SxfContainer* parent) : SxfContainer(parent)
{
    m_md_uri = "";
    m_rawdata = nullptr;
}

SxRawDataContainer::~SxRawDataContainer()
{

}

void SxRawDataContainer::set_md_uri(const QString& uri)
{
    m_md_uri = uri;
}
void SxRawDataContainer::set_rawdata(SxRawData* rawdata)
{
    m_rawdata = rawdata;
}

QString SxRawDataContainer::get_md_uri()
{
    return m_md_uri;
}

SxRawData* SxRawDataContainer::get_rawdata()
{
    return m_rawdata;
}
 