/// \file SxAction.cpp
/// \brief SxAction class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxAction.h"

SxAction::SxAction(const QString& state) : SxfObject()
{
    m_state = state;
}

SxAction::~SxAction()
{

}

void SxAction::setState(const QString& state)
{
    m_state = state;
}
    
QString SxAction::state()
{
    return m_state;
}

void SxAction::setParentContainer(SxfObject* container)
{
    m_parentContainer = container;
}

SxfObject* SxAction::parentContainer()
{
    return m_parentContainer;
}
