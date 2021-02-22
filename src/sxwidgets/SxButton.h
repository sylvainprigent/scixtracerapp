/// \file SxButton.h
/// \brief SxButton
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2014
///
/// Copyright (C) SciXtracer 2014

#pragma once

#include <QPushButton>
#include "sxwidgetsExport.h"

class SXWIDGETS_EXPORT SxButton : public QPushButton
{
    Q_OBJECT
    
public:
    SxButton(QString title, QWidget* parent = nullptr);

public:
    void setContent(const QString& value);

signals:
    void clickedId(int);
    void clickedContent(QString);

protected slots:
    void emitClicked();  

private:
    int m_id;
    QString m_content; 

};
