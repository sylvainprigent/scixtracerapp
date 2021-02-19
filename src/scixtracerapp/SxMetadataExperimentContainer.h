/// \file SxMetadataExperimentContainer.h
/// \brief SxMetadataExperimentContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>
#include <scixtracercpp>

#include "scixtracerappExport.h"

/// \class SxMetadataExperimentContainer
/// \brief GUI Container for a run metadata
class SCIXTRACERAPP_EXPORT SxMetadataExperimentContainer : public SxfContainer{ 

    Q_OBJECT

public:
    SxMetadataExperimentContainer(SxfContainer* parent = nullptr);
    ~SxMetadataExperimentContainer();

public:
    void set_md_uri(const QString& uri);
    void set_experiment(SxExperiment* experiment);

    QString get_md_uri();
    SxExperiment* get_experiment();

protected:
    QString m_md_uri; 
    SxExperiment* m_experiment;  

};