/// \file SxfContainer.cpp
/// \brief SxfContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxfContainer.h"

#include "SxfStates.h"

SxfContainer::SxfContainer(SxfContainer* parent) : SxfObject()
{
    m_currentState = SxfStates::DEFAULT;    

    m_parent = parent;
    if (parent){
        parent->addChild(this);
    }
}

SxfContainer::~SxfContainer(){

}

void SxfContainer::addChild(SxfContainer* child)
{
    m_childs.append(child);
}

void SxfContainer::subscribe(SxfActuator* observer)
{
    m_observers.append(observer);
}
        
void SxfContainer::send(const QString& stateName)
{
    m_currentState = stateName;
    SxfAction* action = new SxfAction(stateName);
    action->setParentContainer(this);
    this->sendAction(action);
}

void SxfContainer::sendAction(SxfAction* action)
{
    for (int i = 0 ; i < m_observers.count() ; ++i)
    {
        m_observers[i]->update(action);
    }
}
