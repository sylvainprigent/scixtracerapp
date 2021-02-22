/// \file SxExperimentContainer.h
/// \brief SxExperimentContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "SxExperimentImportContainer.h"
#include "SxExperimentTagContainer.h"

#include "scixtracerappExport.h"

/// \class SxExperimentContainer
/// \brief GUI Container for a full experiment editor
class SCIXTRACERAPP_EXPORT SxExperimentContainer : public SxfContainer{ 

    Q_OBJECT

public:
    SxExperimentContainer(SxfContainer* parent = nullptr);
    ~SxExperimentContainer();

public:
    QString get_experiment_uri();
    SxExperiment* get_experiment();
    SxExperimentImportContainer* get_import_info();
    SxExperimentTagContainer* get_tag_info();
    QString get_current_dataset_name();
    SxDataset* get_current_dataset();
    int get_clickedRow();
    int get_progress();

    void set_experiment_uri(const QString value);
    void set_experiment(SxExperiment* value);
    void set_import_info(SxExperimentImportContainer* value);
    void set_tag_info(SxExperimentTagContainer* value);
    void set_current_dataset_name(const QString& value);
    void set_current_dataset(SxDataset* value);
    void set_clickedRow(const int& value);
    void set_progress(const int& value);

protected:
    QString m_experiment_uri;
    SxExperiment* m_experiment;
    SxExperimentImportContainer* m_import_info;
    SxExperimentTagContainer* m_tag_info;
    QString m_current_dataset_name;
    SxDataset* m_current_dataset;
    int m_clickedRow;
    int m_progress;
};
