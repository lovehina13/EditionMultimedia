//==============================================================================
// Name        : MultimediaFile.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
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
    MultimediaFile();
    MultimediaFile(const QString& filePath);
    MultimediaFile(const MultimediaFile& multimediaFile);
    virtual ~MultimediaFile();

    // Getters
    const QString& getFilePath() const;

    // Setters
    void setFilePath(const QString& filePath);

    // Generic methods
    void clear();
    void set(const QString& filePath);
    void copy(const MultimediaFile& multimediaFile);
    bool equals(const MultimediaFile& multimediaFile) const;
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Specific methods
    bool operator==(const MultimediaFile& multimediaFile) const;
    bool operator!=(const MultimediaFile& multimediaFile) const;
    void decodeFile();
    void encodeFile(const Settings& settings) const;
    int getDuration() const;
    const QImage getFrame(const int& time) const;

private:
    // Class members
    QString filePath;
};

typedef MultimediaFile* MultimediaFilePtr;
typedef QList<MultimediaFile> MultimediaFilesList;
typedef QList<MultimediaFilePtr> MultimediaFilesPtrList;
typedef QMap<int, MultimediaFile> MultimediaFilesIdMap;
typedef QMap<int, MultimediaFilePtr> MultimediaFilesPtrIdMap;
typedef QMap<QString, MultimediaFile> MultimediaFilesNamesMap;
typedef QMap<QString, MultimediaFilePtr> MultimediaFilesPtrNamesMap;

#endif /* MULTIMEDIAFILE_H */
