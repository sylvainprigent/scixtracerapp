/// \file SxExperimentImportContainer.h
/// \brief SxExperimentImportContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>
#include <scixtracercpp>

#include "scixtracerappExport.h"

/// \class SxExperimentImportContainer
/// \brief GUI Container for a full experiment editor
class SCIXTRACERAPP_EXPORT SxExperimentImportContainer : public SxfContainer{ 

    Q_OBJECT

public:
    SxExperimentImportContainer(SxfContainer* parent = nullptr);
    ~SxExperimentImportContainer();

public:
    QString get_dir_data_path();
    bool get_dir_recursive();
    int get_dir_filter();
    QString get_dir_filter_value();
    bool get_dir_copy_data();
    QString get_file_data_path();
    bool get_file_copy_data();
    QString get_file_name();
    QString get_format();
    QString get_author();
    QString get_createddate();

    void set_dir_data_path(const QString& value);
    void set_dir_recursive(const bool& value);
    void set_dir_filter(const int& value);
    void set_dir_filter_value(const QString& value);
    void set_dir_copy_data(const bool& value);
    void set_file_data_path(const QString& value);
    void set_file_copy_data(const bool& value);
    void set_file_name(const QString& value);
    void set_format(const QString& value);
    void set_author(const QString& value);
    void set_createddate(const QString& value);

private:
    QString m_dir_data_path;
    bool m_dir_recursive;
    int m_dir_filter;
    QString m_dir_filter_value;
    bool m_dir_copy_data;
    QString m_file_data_path;
    bool m_file_copy_data;
    QString m_file_name;
    QString m_format;
    QString m_author;
    QString m_createddate;
};
