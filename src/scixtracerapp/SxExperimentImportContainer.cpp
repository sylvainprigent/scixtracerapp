/// \file SxExperimentImportContainer.cpp
/// \brief SxExperimentImportContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentImportContainer.h"

SxExperimentImportContainer::SxExperimentImportContainer(SxfContainer* parent) : SxfContainer(parent)
{
    m_dir_recursive = false;
    m_dir_copy_data = true;
    m_file_copy_data = true; 
}

SxExperimentImportContainer::~SxExperimentImportContainer()
{

}

QString SxExperimentImportContainer::get_dir_data_path()
{
    return m_dir_data_path;
}

bool SxExperimentImportContainer::get_dir_recursive()
{
    return m_dir_recursive;
}

QString SxExperimentImportContainer::get_dir_filter()
{
    return m_dir_filter;
}

QString SxExperimentImportContainer::get_dir_filter_value()
{
    return m_dir_filter_value;
}

bool SxExperimentImportContainer::get_dir_copy_data()
{
    return m_dir_copy_data;
}

QString SxExperimentImportContainer::get_file_data_path()
{
    return m_file_data_path;
}

bool SxExperimentImportContainer::get_file_copy_data()
{
    return m_file_copy_data;
}

QString SxExperimentImportContainer::get_file_name()
{
    return m_file_name;
}

QString SxExperimentImportContainer::get_format()
{
    return m_format;
}

QString SxExperimentImportContainer::get_author()
{
    return m_author;
}

QString SxExperimentImportContainer::get_createddate()
{
    return m_createddate;
}

void SxExperimentImportContainer::set_dir_data_path(const QString& value)
{
    m_dir_data_path = value;
}

void SxExperimentImportContainer::set_dir_recursive(const bool& value)
{
    m_dir_recursive = value;
}

void SxExperimentImportContainer::set_dir_filter(const QString& value)
{
    m_dir_filter = value;
}

void SxExperimentImportContainer::set_dir_filter_value(const QString& value)
{
    m_dir_filter_value = value;
}

void SxExperimentImportContainer::set_dir_copy_data(const bool& value)
{
    m_dir_copy_data = value;
}

void SxExperimentImportContainer::set_file_data_path(const QString& value)
{
    m_file_data_path = value;
}

void SxExperimentImportContainer::set_file_copy_data(const bool& value)
{
    m_file_copy_data = value;
}

void SxExperimentImportContainer::set_file_name(const QString& value)
{
    m_file_name = value;
}

void SxExperimentImportContainer::set_format(const QString& value)
{
    m_format = value;
}

void SxExperimentImportContainer::set_author(const QString& value)
{
    m_author = value;
}

void SxExperimentImportContainer::set_createddate(const QString& value)
{
    m_createddate = value;
}