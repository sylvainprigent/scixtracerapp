/// \file SxButton.cpp
/// \brief SxButton
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2014
///
/// Copyright (C) SciXtracer 2014

#include "SxButton.h"

SxButton::SxButton(QString title, QWidget* parent) : QPushButton(title, parent)
{
    this->setCursor(QCursor(Qt::PointingHandCursor));
    connect(this, SIGNAL(pressed()), this, SLOT(emitClicked()));
    m_id = 0;
    m_content = "";
}

void SxButton::setContent(const QString& value)
{
    m_content = value;
}

void SxButton::emitClicked()
{
    emit clickedId(m_id);
    emit clickedContent(m_content);
}  
