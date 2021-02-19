/// \file SxfAction.cpp
/// \brief SxfAction class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxfAction.h"

SxfAction::SxfAction(const QString& state) : SxfObject()
{
    m_state = state;
}

SxfAction::~SxfAction()
{

}

void SxfAction::setState(const QString& state)
{
    m_state = state;
}
    
QString SxfAction::state()
{
    return m_state;
}

void SxfAction::setParentContainer(SxfObject* container)
{
    m_parentContainer = container;
}

SxfObject* SxfAction::parentContainer()
{
    return m_parentContainer;
}
