/// \file SxExperimentComponent.cpp
/// \brief SxExperimentComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxExperimentComponent.h"


SxExperimentComponent::SxExperimentComponent() : SxfComponent()
{

}

SxExperimentComponent::~SxExperimentComponent()
{

}

void SxExperimentComponent::update(SxfAction* action)
{

}

QWidget* SxExperimentComponent::getWidget()
{
    return new QLabel("hello Experiment");
}
