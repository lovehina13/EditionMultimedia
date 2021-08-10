//==============================================================================
// Name        : Data.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.0 (10/08/2021)
// Description : Source file of the Data class
//==============================================================================

#include "Data.h"
#include "Tools.h"
#include <QStringList>

Data::Data(const Settings& settings, const MultimediaFile& multimediaFile) :
        _settings(settings), _multimediaFile(multimediaFile)
{
}

const Settings& Data::getSettings() const
{
    return _settings;
}

const MultimediaFile& Data::getMultimediaFile() const
{
    return _multimediaFile;
}

void Data::setSettings(const Settings& settings)
{
    _settings = settings;
}

void Data::setMultimediaFile(const MultimediaFile& multimediaFile)
{
    _multimediaFile = multimediaFile;
}

void Data::clear()
{
    *this = Data();
}

void Data::set(const Settings& settings, const MultimediaFile& multimediaFile)
{
    setSettings(settings);
    setMultimediaFile(multimediaFile);
}

void Data::fromString(const QString& fromString, const QChar& sep)
{
    // TODO void Data::fromString(const QString& fromString, const QChar& sep)
    Q_UNUSED(fromString)
    Q_UNUSED(sep)
}

const QString Data::toString(const QChar& sep) const
{
    // TODO const QString Data::toString(const QChar& sep) const
    Q_UNUSED(sep)
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
            Settings settings = getSettings();
            settings.fromString(line, QChar(';'));
            setSettings(settings);
        }
        else
        {
            MultimediaFile multimediaFile = getMultimediaFile();
            multimediaFile.fromString(line, QChar(';'));
            setMultimediaFile(multimediaFile);
        }
    }
}

void Data::saveData(const QString& filePath)
{
    Settings settings = getSettings();
    settings.setDataFilePath(filePath);
    setSettings(settings);

    const MultimediaFile& multimediaFile = getMultimediaFile();

    QStringList lines;
    lines.append(settings.toString(QChar(';')));
    lines.append(multimediaFile.toString(QChar(';')));
    writeFileLines(filePath, lines);
}

void Data::decodeFile()
{
    MultimediaFile multimediaFile = getMultimediaFile();
    multimediaFile.decodeFile();
    setMultimediaFile(multimediaFile);
}

void Data::encodeFile() const
{
    const Settings& settings = getSettings();
    const MultimediaFile& multimediaFile = getMultimediaFile();
    multimediaFile.encodeFile(settings);
}
