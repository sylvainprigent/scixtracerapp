/// \file SxExperimentCreateContainer.h
/// \brief SxExperimentCreateContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "scixtracerappExport.h"

/// \class SxExperimentCreateContainer
/// \brief GUI Container to create a new experiment
class SCIXTRACERAPP_EXPORT SxExperimentCreateContainer : public SxfContainer{ 

    Q_OBJECT

public:
    SxExperimentCreateContainer(SxfContainer* parent = nullptr);
    ~SxExperimentCreateContainer();

public:
    QString get_experiment_destination_dir();
    QString get_experiment_name();
    QString get_experiment_author();
    QString get_errorMessage();
    QString get_experiment_dir();

    void set_experiment_destination_dir(const QString& value);
    void set_experiment_name(const QString& value);
    void set_experiment_author(const QString& value);
    void set_errorMessage(const QString& value);
    void set_experiment_dir(const QString& value);

private:
    QString m_experiment_destination_dir;
    QString m_experiment_name;
    QString m_experiment_author;
    QString m_errorMessage;
    QString m_experiment_dir;
};
