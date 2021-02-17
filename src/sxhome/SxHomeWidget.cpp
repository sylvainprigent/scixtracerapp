#include "SxHomeWidget.h"
#include "SxHomeTileWidget.h"

SxHomeWidget::SxHomeWidget(QWidget *parent)
    : QWidget(parent){

    m_layout = new QVBoxLayout;
    m_layout->addWidget(new QWidget(this), 1, Qt::AlignTop);
    this->setLayout(m_layout);
}

void SxHomeWidget::addSection(QString name, int strech, bool useFlowLayout){

    SxHideableWidget *sectionWidget = new SxHideableWidget(name, 2, this, useFlowLayout);
    m_layout->insertWidget(0, sectionWidget, strech, Qt::AlignTop);
    m_sectionsNames.append(name);
    m_sectionsWidgets.append(sectionWidget);
}

void SxHomeWidget::addTile(QString section, SxHomeTileInfo info){

    for (int i = 0 ; i < m_sectionsNames.count() ; ++i){
        if (m_sectionsNames[i] == section){
            SxHomeTileWidget *tile = new SxHomeTileWidget(info, this);
            m_sectionsWidgets[i]->addWidget(tile);
            connect(tile, SIGNAL(clicked(blHomeTileInfo)), this, SIGNAL(action(blHomeTileInfo)));
            break;
        }
    }
}

void SxHomeWidget::addWidget(QString section, QWidget *widget){

    for (int i = 0 ; i < m_sectionsNames.count() ; ++i){
        if (m_sectionsNames[i] == section){
            m_sectionsWidgets[i]->addWidget(widget);
            break;
        }
    }
}
