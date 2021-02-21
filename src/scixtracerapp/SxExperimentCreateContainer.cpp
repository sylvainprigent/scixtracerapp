/// \file SxExperimentCreateContainer.cpp
/// \brief SxExperimentCreateContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentCreateContainer.h"

SxExperimentCreateContainer::SxExperimentCreateContainer(SxfContainer* parent) : SxfContainer(parent)
{

}

SxExperimentCreateContainer::~SxExperimentCreateContainer()
{

}

QString SxExperimentCreateContainer::get_experiment_destination_dir()
{
    return m_experiment_destination_dir;
}

QString SxExperimentCreateContainer::get_experiment_name()
{
    return m_experiment_name;
}

QString SxExperimentCreateContainer::get_experiment_author()
{
    return m_experiment_author;
}

QString SxExperimentCreateContainer::get_errorMessage()
{
    return m_errorMessage;
}

QString SxExperimentCreateContainer::get_experiment_dir()
{
    return m_experiment_dir;
}

void SxExperimentCreateContainer::set_experiment_destination_dir(const QString& value)
{
    m_experiment_destination_dir = value;
}

void SxExperimentCreateContainer::set_experiment_name(const QString& value)
{
    m_experiment_name = value;
}

void SxExperimentCreateContainer::set_experiment_author(const QString& value)
{
    m_experiment_author = value;
}

void SxExperimentCreateContainer::set_errorMessage(const QString& value)
{
    m_errorMessage = value;
}

void SxExperimentCreateContainer::set_experiment_dir(const QString& value)
{
    m_experiment_dir = value;
}
