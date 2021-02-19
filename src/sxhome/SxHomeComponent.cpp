/// \file SxHomeComponent.cpp
/// \brief SxHomeComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxHomeComponent.h"

SxHomeComponent::SxHomeComponent() : SxfComponent()
{
    m_widget = new QWidget();

    m_widget->setObjectName("SxHomeWidget");

    // global layout
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    m_widget->setLayout(layout);

    // bar
    m_bar = new SxHomeNavbarWidget(m_widget);
    m_bar->setFixedWidth(44);
    m_centralWidget = new SxSlidingStackedWidget(m_widget);

    layout->addWidget(m_bar);
    layout->addWidget(m_centralWidget);

    this->addHomeButton();

    // connections
    connect(m_bar, SIGNAL(open(int)), this, SLOT(showTab(int)));
    connect(m_bar, SIGNAL(close(int)), this, SLOT(closeTab(int)));
}

SxHomeComponent::~SxHomeComponent()
{

}

void SxHomeComponent::addHomeButton(){

    QString buttonIcon = "";
    m_bar->addButton(buttonIcon, "Home", 0, false);
    m_home = new SxHomeWidget(m_widget);
    m_home->addSection("Applications");
    m_centralWidget->addWidget(m_home);
    m_bar->setButtonChecked(0, false);

    //connect(home, SIGNAL(action(blHomeTileInfo)), this, SLOT(openApp(blHomeTileInfo)));
}

void SxHomeComponent::showTab(int id){
    m_centralWidget->slideInIdx(id);
    m_bar->setButtonChecked(id);
}

void SxHomeComponent::closeTab(int id){

    if (m_centralWidget->currentIndex() == id){
        m_bar->setButtonChecked(id-1, false);
        m_centralWidget->setCurrentIndex(id-1);
    }
    m_bar->removeButton(id);
    delete m_centralWidget->widget(id);
}

void SxHomeComponent::update(SxfAction* action)
{
    /// \todo implement actions
}
   
QWidget* SxHomeComponent::getWidget()
{
    return m_widget;
}
