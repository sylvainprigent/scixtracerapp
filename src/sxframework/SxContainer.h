/// \file SxContainer.h
/// \brief SxContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxframeworkExport.h"

#include "SxActuator.h"
#include "SxAction.h"

/// \class SxContainer
/// \brief Contains the state of a GUI region
class SXFRAMEWORK_EXPORT SxContainer : public SxfObject{ 

    Q_OBJECT

public:
    SxContainer(SxContainer* parent = nullptr);
    ~SxContainer();

public:
    void addChild(SxContainer* child);
    void subscribe(SxActuator* observer);
    void send(const QString& stateName);
    void sendAction(SxAction* action);

protected:
    QList<SxActuator*> m_observers;
    QString m_currentState;    
    QList<SxContainer*> m_childs;
    SxContainer* m_parent;
};
