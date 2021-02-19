/// \file SxRunDataContainer.cpp
/// \brief SxRunDataContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxRunDataContainer.h"


SxRunDataContainer::SxRunDataContainer(SxfContainer* parent) : SxfContainer(parent)
{
    m_md_uri = "";
    m_run = nullptr;
}

SxRunDataContainer::~SxRunDataContainer()
{

}

void SxRunDataContainer::set_md_uri(const QString& uri)
{
    m_md_uri = uri;
}
void SxRunDataContainer::set_run(SxRun* run)
{
    m_run = run;
}

QString SxRunDataContainer::get_md_uri()
{
    return m_md_uri;
}

SxRun* SxRunDataContainer::get_run()
{
    return m_run;
}
 