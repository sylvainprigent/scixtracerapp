/// \file SxRunContainer.h
/// \brief SxRunContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>
#include <scixtracercpp>

#include "scixtracerappExport.h"

/// \class SxRunContainer
/// \brief GUI Container for a run metadata
class SCIXTRACERAPP_EXPORT SxRunContainer : public SxfContainer{ 

    Q_OBJECT

public:
    SxRunContainer(SxfContainer* parent = nullptr);
    ~SxRunContainer();

public:
    void set_md_uri(const QString& uri);
    void set_run(SxRun* run);

    QString get_md_uri();
    SxRun* get_run();

protected:
    QString m_md_uri; 
    SxRun* m_run;  

};