#pragma once

#include <QtWidgets>
#include "SxHomeTileInfo.h"
#include "sxhomeExport.h"

#include <sxwidgets>

/// \class SxHomeWidget
/// \brief Define a generic home tiling widget
class SXHOME_EXPORT SxHomeWidget : public QWidget
{
    Q_OBJECT
public:
    SxHomeWidget(QWidget *parent = 0);

signals:
    void action(SxHomeTileInfo action);

public:
    void addSection(QString name, int strech = 0, bool useFlowLayout = true);
    void addTile(QString section, SxHomeTileInfo info);
    void addWidget(QString section, QWidget *widget);


private:
    QStringList m_sectionsNames;
    QList<SxHideableWidget*> m_sectionsWidgets;

private:
    QVBoxLayout *m_layout;
};
