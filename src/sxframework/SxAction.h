/// \file SxExperimentWidget.h
/// \brief SxExperimentWidget class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>

#include "sxframeworkExport.h"

#include "SxfObject.h"

/// \class SxAction
/// \brief Contains instructions for a GUI action (click...)
class SXFRAMEWORK_EXPORT SxAction : public SxfObject{ 

    Q_OBJECT

public:
    SxAction(const QString& state);
    ~SxAction();

public:
    void setState(const QString& state);
    QString state();
    void setParentContainer(SxfObject* container);
    SxfObject* parentContainer();

protected:
    QString m_state;
    SxfObject* m_parentContainer;
};
