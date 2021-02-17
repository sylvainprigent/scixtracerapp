/// \file SxClosableButton.h
/// \brief SxClosableButton
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2014
///
/// Copyright (C) SciXtracer 2014

#pragma once

#include <QtWidgets>
#include "sxwidgetsExport.h"

class SXWIDGETS_EXPORT SxClosableButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SxClosableButton(bool closable = true, QWidget *parent = 0);

signals:
    void clicked(int id);
    void closed(int id);

public:
    int id();
    //QPushButton *button();

public slots:
    void setId(int id);
    //void setChecked(bool value);

private slots:
    void emitClicked();
    void emitClosed();

private:
    int m_id;
    //QPushButton *m_button;
};
