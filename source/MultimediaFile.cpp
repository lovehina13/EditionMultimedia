//==============================================================================
// Name        : MultimediaFile.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
// Description : Source file of the MultimediaFile class
//==============================================================================

#include "MultimediaFile.h"
#include <QStringList>

MultimediaFile::MultimediaFile() :
        filePath(QString())
{
    this->clear();
}

MultimediaFile::MultimediaFile(const QString& filePath) :
        MultimediaFile()
{
    this->set(filePath);
}

MultimediaFile::MultimediaFile(const MultimediaFile& multimediaFile) :
        MultimediaFile()
{
    this->copy(multimediaFile);
}

MultimediaFile::~MultimediaFile()
{

}

const QString& MultimediaFile::getFilePath() const
{
    return this->filePath;
}

void MultimediaFile::setFilePath(const QString& filePath)
{
    this->filePath = filePath;
}

void MultimediaFile::clear()
{
    this->set(QString());
}

void MultimediaFile::set(const QString& filePath)
{
    this->setFilePath(filePath);
}

void MultimediaFile::copy(const MultimediaFile& multimediaFile)
{
    this->set(multimediaFile.getFilePath());
}

bool MultimediaFile::equals(const MultimediaFile& multimediaFile) const
{
    if (this->getFilePath() != multimediaFile.getFilePath())
        return false;
    return true;
}

void MultimediaFile::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = fromString.split(sep);
    if (fromStringList.count() < 1)
        return;
    this->setFilePath(fromStringList.at(0));
}

const QString MultimediaFile::toString(const QChar& sep) const
{
    Q_UNUSED(sep); // TODO Remove

    QString toString;
    toString += this->getFilePath();
    return toString;
}

bool MultimediaFile::operator==(const MultimediaFile& multimediaFile) const
{
    return this->equals(multimediaFile);
}

bool MultimediaFile::operator!=(const MultimediaFile& multimediaFile) const
{
    return !(this->equals(multimediaFile));
}

void MultimediaFile::decodeFile()
{
    // TODO void MultimediaFile::decodeFile()
}

void MultimediaFile::encodeFile(const Settings& settings) const
{
    // TODO void MultimediaFile::encodeFile(const Settings& settings) const
    Q_UNUSED(settings);
}
