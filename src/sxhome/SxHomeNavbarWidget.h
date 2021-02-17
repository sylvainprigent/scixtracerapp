/// \file SxHomeNavbarWidget.h
/// \brief SxHomeNavbarWidget class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <QtWidgets>
#include "sxhomeExport.h"

/// \class SxHomeNavbarWidget
/// \brief Define a generic home bar widget
class SXHOME_EXPORT SxHomeNavbarWidget : public QWidget
{
    Q_OBJECT
public:
    SxHomeNavbarWidget(QWidget *parent = 0);

signals:
    void open(int);
    void close(int);

public slots:
    void addButton(QString icon, QString toolTip, int id, bool closable = true);
    void removeButton(int id);
    void setButtonChecked(int id, bool clicked = true);

private:
    QVBoxLayout *m_layout;
};
