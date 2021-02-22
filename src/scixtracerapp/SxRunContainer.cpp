/// \file SxRunContainer.cpp
/// \brief SxRunContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxRunContainer.h"


SxRunContainer::SxRunContainer(SxfContainer* parent) : SxfContainer(parent)
{
    m_md_uri = "";
    m_run = nullptr;
}

SxRunContainer::~SxRunContainer()
{

}

void SxRunContainer::set_md_uri(const QString& uri)
{
    m_md_uri = uri;
}
void SxRunContainer::set_run(SxRun* run)
{
    m_run = run;
}

QString SxRunContainer::get_md_uri()
{
    return m_md_uri;
}

SxRun* SxRunContainer::get_run()
{
    return m_run;
}
 