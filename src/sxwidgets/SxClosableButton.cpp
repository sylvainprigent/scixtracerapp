/// \file SxClosableButton.cpp
/// \brief SxClosableButton
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2014
///
/// Copyright (C) SciXtracer 2014

#include "SxClosableButton.h"

SxClosableButton::SxClosableButton(bool closable, QWidget *parent)
    :QPushButton(parent){

/*
    QVBoxLayout *tlayout = new QVBoxLayout;
    tlayout->setContentsMargins(0,0,0,0);
    m_button = new QPushButton(this);
    tlayout->addWidget(m_button);
    m_button->setCheckable(true);
    this->setLayout(tlayout);
    */


    if (closable){
        QVBoxLayout *layout = new QVBoxLayout;
        layout->setContentsMargins(0,0,0,0);
        QPushButton *closeButton = new QPushButton(this);
        closeButton->setObjectName("blCloseButton");
        closeButton->setFixedSize(12,12);
        layout->addWidget(closeButton, 1, Qt::AlignTop | Qt::AlignRight);
        this->setLayout(layout);
        connect(closeButton, SIGNAL(pressed()), this, SLOT(emitClosed()));
    }

    connect(this, SIGNAL(pressed()), this, SLOT(emitClicked()));
}

int SxClosableButton::id(){
    return m_id;
}

void SxClosableButton::setId(int id){
    m_id = id;
}

void SxClosableButton::emitClicked(){
    emit clicked(m_id);
}

void SxClosableButton::emitClosed(){
    emit closed(m_id);
}

/*
void SxClosableButton::setChecked(bool value){
    m_button->setChecked(value);
}

QPushButton *SxClosableButton::button(){
    return m_button;
}
*/
