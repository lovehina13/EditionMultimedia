//==============================================================================
// Name        : Data.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.0 (10/08/2021)
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
    Data() = default;
    Data(const Settings& settings, const MultimediaFile& multimediaFile);

    // Operators
    bool operator==(const Data& data) const = default;
    bool operator!=(const Data& data) const = default;

    // Getters
    const Settings& getSettings() const;
    const MultimediaFile& getMultimediaFile() const;

    // Setters
    void setSettings(const Settings& settings);
    void setMultimediaFile(const MultimediaFile& multimediaFile);

    // Generic methods
    void clear();
    void set(const Settings& settings, const MultimediaFile& multimediaFile);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Specific methods
    void loadData(const QString& filePath);
    void saveData(const QString& filePath);
    void decodeFile();
    void encodeFile() const;

private:
    // Class members
    Settings _settings;
    MultimediaFile _multimediaFile;
};

using DataPtr = Data*;
using DataList = QList<Data>;
using DataPtrList = QList<DataPtr>;
using DataIdMap = QMap<int, Data>;
using DataPtrIdMap = QMap<int, DataPtr>;
using DataNamesMap = QMap<QString, Data>;
using DataPtrNamesMap = QMap<QString, DataPtr>;

#endif /* DATA_H */
