/// \file SxHideableWidget.cpp
/// \brief SxHideableWidget
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2014
///
/// Copyright (C) SciXtracer 2014

#include "SxHideableWidget.h"

SxHideableWidget::SxHideableWidget(QString title, int level, QWidget *parent, bool useFlowLayout) : QWidget(parent)
{
    m_useFlowLayout = useFlowLayout;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    this->setLayout(layout);

    // title area
    QLabel *titleLabel = new QLabel(title, this);
    titleLabel->setObjectName(QString("SxHideableWidgetTitleText") + QString("Level") + QString::number(level));
    m_button = new QPushButton(this);
    m_button->setCheckable(true);
    m_button->setObjectName(QString("SxHideableWidgetTitleButton") + QString("Level") + QString::number(level));

    QWidget *titleArea = new QWidget(this);
    titleArea->setObjectName(QString("SxHideableWidgetTitle") + QString("Level") + QString::number(level));
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->setContentsMargins(0,0,0,0);
    titleArea->setLayout(titleLayout);
    titleLayout->addWidget(titleLabel, 1, Qt::AlignLeft);
    titleLayout->addWidget(m_button, 0, Qt::AlignRight);

    layout->addWidget(titleArea);

    // hideable widget
    m_hideableWidget = new QWidget(this);
    m_hideableWidget->setObjectName(QString("SxHideableWidget") + QString("Level") + QString::number(level));
    m_isVisible = true;
    m_animation = new QPropertyAnimation(m_hideableWidget, "maximumHeight", this);
    m_useAnimation = true;

    if (useFlowLayout){
        m_flowLayout = new SxFlowLayout;
        m_hideableWidget->setLayout(m_flowLayout);
    }
    else{
        m_layout = new QVBoxLayout;
        m_hideableWidget->setLayout(m_layout);
    }

    layout->addWidget(m_hideableWidget);

    // connections
    connect(m_button, SIGNAL(pressed()), this, SLOT(switchView()));
}

void SxHideableWidget::setUseAnimation(bool useAnimation){
    m_useAnimation = useAnimation;
}

void SxHideableWidget::switchView(){
    if (m_isVisible){

        if (m_useAnimation){
            m_animation->setDuration(1000);
            m_animation->setStartValue(m_height);
            m_animation->setEndValue(0);
            m_animation->start();
        }
        else{
            m_hideableWidget->setVisible(false);
        }
        m_isVisible = false;

        //m_button->setText(">");
    }
    else{
        if (m_useAnimation){
            m_animation->setDuration(2000);
            m_animation->setStartValue(0);
            m_animation->setEndValue(m_height);
            m_animation->start();
        }
        else{
            m_hideableWidget->setVisible(true);
        }
        m_isVisible = true;
        //m_button->setText("<");
    }
}

void SxHideableWidget::addWidget(QWidget* widget){
    if (m_useFlowLayout){
        m_flowLayout->addWidget(widget);
    }
    else{
        m_layout->addWidget(widget);
    }
    m_height = 500;
}
