/// \file SxProcessedDataContainer.h
/// \brief SxProcessedDataContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>
#include <scixtracercpp>

#include "scixtracerappExport.h"

/// \class SxProcessedDataContainer
/// \brief GUI Container for a processed data
class SCIXTRACERAPP_EXPORT SxProcessedDataContainer : public SxfContainer{ 

    Q_OBJECT

public:
    SxProcessedDataContainer(SxfContainer* parent = nullptr);
    ~SxProcessedDataContainer();

public:
    void set_md_uri(const QString& uri);
    void set_processeddata(SxProcessedData* rawdata);

    QString get_md_uri();
    SxProcessedData* get_processeddata();

protected:
    QString m_md_uri; 
    SxProcessedData* m_processeddata;  

};