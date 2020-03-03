//==============================================================================
// Name        : Data.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (03/03/2020)
// Description : Source file of the Data class
//==============================================================================

#include "Data.h"
#include "Tools.h"
#include <QStringList>

Data::Data() :
        settings(Settings()), multimediaFile(MultimediaFile())
{
    this->clear();
}

Data::Data(const Settings& settings, const MultimediaFile& multimediaFile) :
        Data()
{
    this->set(settings, multimediaFile);
}

Data::Data(const Data& data) :
        Data()
{
    this->copy(data);
}

Data::~Data()
{

}

Data& Data::operator=(const Data& data)
{
    this->copy(data);
    return *this;
}

bool Data::operator==(const Data& data) const
{
    return this->equals(data);
}

bool Data::operator!=(const Data& data) const
{
    return !this->equals(data);
}

const Settings& Data::getSettings() const
{
    return this->settings;
}

const MultimediaFile& Data::getMultimediaFile() const
{
    return this->multimediaFile;
}

void Data::setSettings(const Settings& settings)
{
    this->settings = settings;
}

void Data::setMultimediaFile(const MultimediaFile& multimediaFile)
{
    this->multimediaFile = multimediaFile;
}

void Data::clear()
{
    this->set(Settings(), MultimediaFile());
}

void Data::set(const Settings& settings, const MultimediaFile& multimediaFile)
{
    this->setSettings(settings);
    this->setMultimediaFile(multimediaFile);
}

void Data::copy(const Data& data)
{
    this->set(data.getSettings(), data.getMultimediaFile());
}

bool Data::equals(const Data& data) const
{
    if (this->getSettings() != data.getSettings())
        return false;
    if (this->getMultimediaFile() != data.getMultimediaFile())
        return false;
    return true;
}

void Data::fromString(const QString& fromString, const QChar& sep)
{
    // TODO void Data::fromString(const QString& fromString, const QChar& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString Data::toString(const QChar& sep) const
{
    // TODO const QString Data::toString(const QChar& sep) const
    Q_UNUSED(sep);
    return QString();
}

void Data::loadData(const QString& filePath)
{
    const QStringList lines = readFileLines(filePath);
    const int nbLines = lines.count();
    for (int itLine = 0; itLine < nbLines; itLine++)
    {
        const QString& line = lines.at(itLine);
        if (itLine == 0)
        {
            Settings settings = this->getSettings();
            settings.fromString(line, QChar(';'));
            this->setSettings(settings);
        }
        else
        {
            MultimediaFile multimediaFile = this->getMultimediaFile();
            multimediaFile.fromString(line, QChar(';'));
            this->setMultimediaFile(multimediaFile);
        }
    }
}

void Data::saveData(const QString& filePath)
{
    Settings settings = this->getSettings();
    settings.setDataFilePath(filePath);
    this->setSettings(settings);

    const MultimediaFile& multimediaFile = this->getMultimediaFile();

    QStringList lines;
    lines.append(settings.toString(QChar(';')));
    lines.append(multimediaFile.toString(QChar(';')));
    writeFileLines(filePath, lines);
}

void Data::decodeFile()
{
    MultimediaFile multimediaFile = this->getMultimediaFile();
    multimediaFile.decodeFile();
    this->setMultimediaFile(multimediaFile);
}

void Data::encodeFile() const
{
    const Settings& settings = this->getSettings();
    const MultimediaFile& multimediaFile = this->getMultimediaFile();
    multimediaFile.encodeFile(settings);
}
