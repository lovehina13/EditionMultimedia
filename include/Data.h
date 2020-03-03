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

    // Operators
    Data& operator=(const Data& data);
    bool operator==(const Data& data) const;
    bool operator!=(const Data& data) const;

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
    void loadData(const QString& filePath);
    void saveData(const QString& filePath);
    void decodeFile();
    void encodeFile() const;

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
