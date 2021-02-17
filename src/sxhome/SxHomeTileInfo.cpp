/// \file SxHomeTileInfo.cpp
/// \brief SxHomeTileInfo class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxHomeTileInfo.h"

SxHomeTileInfo::SxHomeTileInfo(){

}

SxHomeTileInfo::SxHomeTileInfo(QString action, QString name, QString tooltip, QString iconeUrl){
    m_action = action;
    m_name = name;
    m_tooltip = tooltip;
    m_iconeUrl = iconeUrl;
}


// setters
void SxHomeTileInfo::setAction(QString action){
    m_action = action;
}

void SxHomeTileInfo::setName(QString name){
    m_name = name;
}

void SxHomeTileInfo::setTooltip(QString tooltip){
    m_tooltip = tooltip;
}

void SxHomeTileInfo::setIconeUrl(QString url){
    m_iconeUrl = url;
}

// getters
QString SxHomeTileInfo::action(){
    return m_action;
}

QString SxHomeTileInfo::name(){
    return m_name;
}

QString SxHomeTileInfo::tooltip(){
    return m_tooltip;
}

QString SxHomeTileInfo::iconeUrl(){
    return m_iconeUrl;
}