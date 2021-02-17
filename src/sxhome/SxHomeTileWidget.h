/// \file SxHomeTileWidget.h
/// \brief SxHomeTileWidget class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>
#include "SxHomeTileInfo.h"

#include "sxhomeExport.h"

/// \class SxHomeTileWidget
/// \brief Define a tile for the home tiling menu
class SXHOME_EXPORT SxHomeTileWidget : public QWidget
{
    Q_OBJECT
public:
    SxHomeTileWidget(QWidget *parent = 0);
    SxHomeTileWidget(SxHomeTileInfo info, QWidget *parent=0);

signals:
    void clicked();
    void clicked(SxHomeTileInfo info);

public slots:
    void setText(QString txt);
    void setIcon(QString icon);

private slots:
    void emitClicked();

private:
    QLabel *m_label;
    QPushButton *m_button;
    SxHomeTileInfo m_info;

private:
    void buildButton();
};