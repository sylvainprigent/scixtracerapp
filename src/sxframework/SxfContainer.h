/// \file SxfContainer.h
/// \brief SxfContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxframeworkExport.h"

#include "SxfActuator.h"
#include "SxfAction.h"

/// \class SxfContainer
/// \brief Contains the state of a GUI region
class SXFRAMEWORK_EXPORT SxfContainer : public SxfObject{ 

    Q_OBJECT

public:
    SxfContainer(SxfContainer* parent = nullptr);
    ~SxfContainer();

public:
    void addChild(SxfContainer* child);
    void subscribe(SxfActuator* observer);
    void send(const QString& stateName);
    void sendAction(SxfAction* action);

protected:
    QList<SxfActuator*> m_observers;
    QString m_currentState;    
    QList<SxfContainer*> m_childs;
    SxfContainer* m_parent;
};
