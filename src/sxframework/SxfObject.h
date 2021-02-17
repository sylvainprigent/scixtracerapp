/// \file SxfObject.h
/// \brief SxfObject class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>

#include "sxframeworkExport.h"

/// \class SxObject
/// \brief Mother class for container and action
class SXFRAMEWORK_EXPORT SxfObject : public QObject{ 

public:
    SxfObject();
    ~SxfObject();

protected:
    QString m_objectName;

};
