/// \file SxHomeTileInfo.h
/// \brief SxHomeTileInfo class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxhomeExport.h"
#include "SxObject.h"

/// \class SxHomeTileInfo
/// \brief Container for tile information
class SXHOME_EXPORT SxHomeTileInfo{ 

public:
    SxHomeTileInfo();
    SxHomeTileInfo(QString action, QString name, QString tooltip, QString iconeUrl);

public:
    // setters
    void setAction(QString action);
    void setName(QString name);
    void setTooltip(QString tooltip);
    void setIconeUrl(QString url);

    // getters
    QString action();
    QString name();
    QString tooltip();
    QString iconeUrl();

protected:
    QString m_action;
    QString m_name;
    QString m_tooltip;
    QString m_iconeUrl;
};
