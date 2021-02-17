/// \file SxContainer.cpp
/// \brief SxContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxContainer.h"

#include "SxStates.h"

SxContainer::SxContainer(SxContainer* parent) : SxfObject()
{
    m_currentState = SxStates::DEFAULT;    

    m_parent = parent;
    if (parent){
        parent->addChild(this);
    }
}

SxContainer::~SxContainer(){

}

void SxContainer::addChild(SxContainer* child)
{
    m_childs.append(child);
}

void SxContainer::subscribe(SxActuator* observer)
{
    m_observers.append(observer);
}
        
void SxContainer::send(const QString& stateName)
{
    m_currentState = stateName;
    SxAction* action = new SxAction(stateName);
    action->setParentContainer(this);
    this->sendAction(action);
}

void SxContainer::sendAction(SxAction* action)
{
    for (int i = 0 ; i < m_observers.count() ; ++i)
    {
        m_observers[i]->update(action);
    }
}
