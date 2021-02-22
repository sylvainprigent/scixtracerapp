/// \file SxTagWidget.cpp
/// \brief SxTagWidget
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020
///
/// Copyright (C) SciXtracer 2020

#include "SxTagWidget.h"

SxTagWidget::SxTagWidget(QWidget* parent) : QWidget()
{
    QHBoxLayout* layout = new QHBoxLayout();
    layout->setContentsMargins(0,0,0,0);

    m_tagName = new QLineEdit();
    m_tagName->setReadOnly(true);
    layout->addWidget(m_tagName);

    QPushButton* removeButton = new QPushButton(this->tr("Remove"));
    removeButton->setObjectName("btnDanger");
    layout->addWidget(removeButton, 0, Qt::AlignRight);
    connect(removeButton, SIGNAL(released), this, SLOT(emitRemove()));

    this->setLayout(layout);
}

void SxTagWidget::setContent(const QString& content)
{
    m_tagName->setText(content);
}

QString SxTagWidget::content()
{
    return m_tagName->text();
}

void SxTagWidget::emitRemove()
{
    emit remove(m_tagName->text());
}
