//==============================================================================
// Name        : Data.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
// Description : Header file of the Data class
//==============================================================================

#ifndef DATA_H
#define DATA_H

#include "MultimediaFile.h"
#include "Settings.h"
#include <QChar>
#include <QList>
#include <QMap>
#include <QString>

class Data
{
public:
    // Constructors and destructors
    Data();
    Data(const Settings& settings, const MultimediaFile& multimediaFile);
    Data(const Data& data);
    virtual ~Data();

    // Getters
    const Settings& getSettings() const;
    const MultimediaFile& getMultimediaFile() const;

    // Setters
    void setSettings(const Settings& settings);
    void setMultimediaFile(const MultimediaFile& multimediaFile);

    // Generic methods
    void clear();
    void set(const Settings& settings, const MultimediaFile& multimediaFile);
    void copy(const Data& data);
    bool equals(const Data& data) const;
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Specific methods

private:
    // Class members
    Settings settings;
    MultimediaFile multimediaFile;
};

typedef Data* DataPtr;
typedef QList<Data> DataList;
typedef QList<DataPtr> DataPtrList;
typedef QMap<int, Data> DataIdMap;
typedef QMap<int, DataPtr> DataPtrIdMap;
typedef QMap<QString, Data> DataNamesMap;
typedef QMap<QString, DataPtr> DataPtrNamesMap;

#endif /* DATA_H */