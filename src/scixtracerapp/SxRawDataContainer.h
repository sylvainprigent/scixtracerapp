/// \file SxRawDataContainer.h
/// \brief SxRawDataContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>
#include <scixtracercpp>

#include "scixtracerappExport.h"

/// \class SxRawDataContainer
/// \brief GUI Container for a raw data
class SCIXTRACERAPP_EXPORT SxRawDataContainer : public SxfContainer{ 

    Q_OBJECT

public:
    SxRawDataContainer(SxfContainer* parent = nullptr);
    ~SxRawDataContainer();

public:
    void set_md_uri(const QString& uri);
    void set_rawdata(SxRawData* rawdata);

    QString get_md_uri();
    SxRawData* get_rawdata();

protected:
    QString m_md_uri; 
    SxRawData* m_rawdata;  

};