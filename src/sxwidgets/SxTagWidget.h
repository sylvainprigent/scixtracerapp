/// \file SxTagWidget.h
/// \brief SxTagWidget
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020
///
/// Copyright (C) SciXtracer 2020

#pragma once

#include <QtWidgets>

#include "sxwidgetsExport.h"

class SXWIDGETS_EXPORT SxTagWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SxTagWidget(QWidget* parent = nullptr);

signals:
    void remove(QString);

public slots:
    QString content();

public:
    void setContent(const QString& content);    

private slots:
    void emitRemove();

private:
    QLineEdit* m_tagName;

};