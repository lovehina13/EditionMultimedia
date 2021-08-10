//==============================================================================
// Name        : MultimediaFile.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (03/03/2020)
// Description : Header file of the MultimediaFile class
//==============================================================================

#ifndef MULTIMEDIAFILE_H
#define MULTIMEDIAFILE_H

#include "Settings.h"
#include <QChar>
#include <QImage>
#include <QList>
#include <QMap>
#include <QString>

class MultimediaFile
{
public:
    // Constructors and destructors
    MultimediaFile() = default;
    MultimediaFile(const QString& filePath);

    // Operators
    bool operator==(const MultimediaFile& multimediaFile) const = default;
    bool operator!=(const MultimediaFile& multimediaFile) const = default;

    // Getters
    const QString& getFilePath() const;

    // Setters
    void setFilePath(const QString& filePath);

    // Generic methods
    void clear();
    void set(const QString& filePath);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Specific methods
    void decodeFile();
    void encodeFile(const Settings& settings) const;
    int getDuration() const;
    const QImage getFrame(const int& time) const;

private:
    // Class members
    QString _filePath;
};

using MultimediaFilePtr = MultimediaFile*;
using MultimediaFilesList = QList<MultimediaFile>;
using MultimediaFilesPtrList = QList<MultimediaFilePtr>;
using MultimediaFilesIdMap = QMap<int, MultimediaFile>;
using MultimediaFilesPtrIdMap = QMap<int, MultimediaFilePtr>;
using MultimediaFilesNamesMap = QMap<QString, MultimediaFile>;
using MultimediaFilesPtrNamesMap = QMap<QString, MultimediaFilePtr>;

#endif /* MULTIMEDIAFILE_H */
