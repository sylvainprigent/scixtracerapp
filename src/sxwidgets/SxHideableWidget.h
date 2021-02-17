/// \file SxHideableWidget.h
/// \brief SxHideableWidget
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2014
///
/// Copyright (C) SciXtracer 2014

#ifndef SxHideableWidget_H
#define SxHideableWidget_H

#include <QtWidgets>
#include "sxwidgetsExport.h"
#include "SxFlowLayout.h"

class SXWIDGETS_EXPORT SxHideableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SxHideableWidget(QString title, int level = 1, QWidget *parent = 0, bool useFlowLayout = false);

signals:

public:
    void addWidget(QWidget* widget);
    void setUseAnimation(bool useAnimation);

private slots:
    void switchView();

private:
    QWidget *m_hideableWidget;
    QVBoxLayout *m_layout;
    SxFlowLayout *m_flowLayout;
    QPushButton *m_button;
    bool m_useFlowLayout;

    bool m_isVisible;
    int m_height;
    QPropertyAnimation *m_animation;
    bool m_useAnimation;

};

#endif // SxHideableWidget_H
