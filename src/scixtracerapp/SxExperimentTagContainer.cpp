/// \file SxExperimentTagContainer.cpp
/// \brief SxExperimentTagContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentTagContainer.h"

SxExperimentTagContainer::SxExperimentTagContainer(SxfContainer* parent) : SxfContainer(parent)
{

}

SxExperimentTagContainer::~SxExperimentTagContainer()
{

}

QStringList SxExperimentTagContainer::get_tags()
{
    return m_tags;
}

QString SxExperimentTagContainer::get_usingname_tag()
{
    return m_usingname_tag;
}

QStringList SxExperimentTagContainer::get_usingname_search()
{
    return m_usingname_search;
}

QStringList SxExperimentTagContainer::get_usingseparator_tags()
{
    return m_usingseparator_tags;
}

QStringList SxExperimentTagContainer::get_usingseparator_separator()
{
    return m_usingseparator_separator;
}

QList<int> SxExperimentTagContainer::get_usingseparator_position()
{
    return m_usingseparator_position;
} 

void SxExperimentTagContainer::set_tags(const QStringList& value)
{
    m_tags = value;
}

void SxExperimentTagContainer::set_usingname_tag(const QString& value)
{
    m_usingname_tag = value;
}

void SxExperimentTagContainer::set_usingname_search(const QStringList& value)
{
    m_usingname_search = value;
}

void SxExperimentTagContainer::set_usingseparator_tags(const QStringList& value)
{
    m_usingseparator_tags = value;
}

void SxExperimentTagContainer::set_usingseparator_separator(const QStringList& value)
{
    m_usingseparator_separator = value;
}

void SxExperimentTagContainer::set_usingseparator_position(const QList<int>& value)
{
    m_usingseparator_position = value;
}
