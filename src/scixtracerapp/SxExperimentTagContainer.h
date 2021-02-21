/// \file SxExperimentTagContainer.h
/// \brief SxExperimentTagContainer class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include <sxframework>

#include "scixtracerappExport.h"

/// \class SxExperimentTagContainer
/// \brief GUI Container for a experiment tag editor
class SCIXTRACERAPP_EXPORT SxExperimentTagContainer : public SxfContainer{ 

    Q_OBJECT

public:
    SxExperimentTagContainer(SxfContainer* parent = nullptr);
    ~SxExperimentTagContainer();

public:
    QStringList get_tags();
    QString get_usingname_tag();
    QStringList get_usingname_search();
    QStringList get_usingseparator_tags();
    QStringList get_usingseparator_separator();
    QStringList get_usingseparator_position(); 

    void set_tags(const QStringList& value);
    void set_usingname_tag(const QString& value);
    void set_usingname_search(const QStringList& value);
    void set_usingseparator_tags(const QStringList& value);
    void set_usingseparator_separator(const QStringList& value);
    void set_usingseparator_position(const QStringList& value); 

private:
    QStringList m_tags;
    QString m_usingname_tag ;
    QStringList m_usingname_search;
    QStringList m_usingseparator_tags;
    QStringList m_usingseparator_separator;
    QStringList m_usingseparator_position; 
};