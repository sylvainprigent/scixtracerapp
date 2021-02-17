/// \file SxClickableIcon.cpp
/// \brief SxClickableIcon
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2014
///
/// Copyright (C) BioImageLab 2014

#include "SxClickableIcon.h"

SxClickableIcon::SxClickableIcon(QString cheminImage, QString textIcone , int large,int haut, int marge,QWidget *parent): QLabel(parent)
{
    text_icone=textIcone;// pour transmetre aux events
    largeM=large;
    hautM=haut;
    margeM=marge;
    /// 2- Ajoute l'image
    /// 2.1- Cree le layout de l'image
    /// 2.3- Ajoute l'image et ses proprietees au layout icone
    this->setPixmap(QPixmap::fromImage(QImage(cheminImage)).scaledToHeight(haut,Qt::SmoothTransformation));
    this->setMaximumSize(QSize(large+marge,haut+marge));
    this->setAlignment(Qt::AlignHCenter);
    this->setCursor(Qt::PointingHandCursor);

    this->setMinimumSize(QSize(large+marge,haut+marge));
    this->setContentsMargins(0,0,0,0);
}

void SxClickableIcon::ChangeIcon(QString textIcone)
{
    QString cheminIcones="../AgentC/icones/";
    QString cheminImage=cheminIcones + textIcone + ".png";
    text_icone=textIcone;// pour transmetre aux events

    QImage image=(QImage(cheminImage));
    image=image.scaledToHeight(hautM,Qt::SmoothTransformation);
    QPixmap pixmap;
    pixmap.fromImage(image,Qt::AutoColor );
    /// 2.3- Ajoute l'image et ses proprietees au layout icone
    this->setPixmap(pixmap);
}

void SxClickableIcon::mouseReleaseEvent(QMouseEvent *event)//,QString textIcone
{
    if(event->button() == Qt::LeftButton)
    {
        iconClicked(text_icone);
        iconClicked(m_posInFolder);
        clicked();
    }
}

void SxClickableIcon::setPositionNumber(int pos)
{
    m_posInFolder = pos;
}

void SxClickableIcon::setIdx(int idx){
    m_idx = idx;
}

int SxClickableIcon::idx(){
    return m_idx;
}
