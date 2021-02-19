/// \file SxfAction.h
/// \brief SxfAction class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>

#include "sxframeworkExport.h"

#include "SxfObject.h"

/// \class SxAction
/// \brief Contains instructions for a GUI action (click...)
class SXFRAMEWORK_EXPORT SxfAction : public SxfObject{ 

    Q_OBJECT

public:
    SxfAction(const QString& state);
    ~SxfAction();

public:
    void setState(const QString& state);
    QString state();
    void setParentContainer(SxfObject* container);
    SxfObject* parentContainer();

protected:
    QString m_state;
    SxfObject* m_parentContainer;
};
