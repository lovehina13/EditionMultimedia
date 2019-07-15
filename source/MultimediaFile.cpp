//==============================================================================
// Name        : MultimediaFile.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
// Description : Source file of the MultimediaFile class
//==============================================================================

#include "MultimediaFile.h"
#include "Tools.h"
#include <QFile>
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

int MultimediaFile::getDuration() const
{
    int duration = 0;

    const QString& inFilePath = this->getFilePath();
    const QString outFilePath = QString("%1.out.txt").arg(inFilePath);
    const QString command = QString("ffprobe -v error -show_format \"%1\" > \"%2\"").arg(inFilePath,
            outFilePath);
    executeCommand(command, true);

    const QStringList lines = readFileLines(outFilePath);
    const int nbLines = lines.count();
    for (int itLine = 0; itLine < nbLines; itLine++)
    {
        const QString& line = lines.at(itLine);
        QStringList lineItems = line.split("=");
        if (lineItems.count() < 2)
            continue;
        const QString metadata = lineItems.takeFirst();
        const QString value = lineItems.join("=");
        if (metadata == QString("duration"))
        {
            duration = (int) (value.toDouble() * 1000);
        }
    }

    QFile::remove(outFilePath);

    return duration;
}

const QImage MultimediaFile::getFrame(const int& time) const
{
    const QString& inFilePath = this->getFilePath();
    const QString outFilePath = QString("%1_out.png").arg(inFilePath);
    const QString command =
            QString(
                    "ffmpeg -y -i \"%1\" -frames:v 1 -filter:v \"scale=640:-1, select='eq(t\\,%2)'\" \"%3\"").arg(
                    inFilePath, QString::number((double) time / 1000.0), outFilePath);
    executeCommand(command, true);

    return QImage(outFilePath);
}
