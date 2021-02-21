/// \file SxExperimentStates.h
/// \brief SxExperimentStates class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#pragma once

#include "sxframeworkExport.h"

#include <sxframework>

/// \class SxExperimentStates
/// \brief States for a experiment full editor
class SXFRAMEWORK_EXPORT SxExperimentStates : public SxfStates{ 

public:

    static QString ImportClicked; 
    static QString TagClicked;
    static QString ProcessClicked; 
    static QString Load;
    static QString Loaded;
    static QString TagsModified;
    static QString TagUsingSeparators;
    static QString TagUsingName;
    static QString RawDataImported;
    static QString NewImport;
    static QString Progress;
    static QString NewImportDir;
    static QString NewImportFile;
    static QString DataImported;
    static QString TagsSaved;
    static QString DataTagged;
    static QString EditInfoClicked;
    static QString DataSetClicked;
    static QString DataSetLoaded;
    static QString RawDataClicked;
    static QString ProcessedDataClicked;
    static QString RefreshClicked;
    static QString CloseClicked;
};