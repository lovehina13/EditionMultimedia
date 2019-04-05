//==============================================================================
// Name        : Data.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
// Description : Source file of the Data class
//==============================================================================

#include "Data.h"

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
