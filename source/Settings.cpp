//==============================================================================
// Name        : Settings.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
// Description : Source file of the Settings class
//==============================================================================

#include "Settings.h"
#include <QStringList>
#include <cmath>

Settings::Settings() :
        dataFilePath(QString()), multimediaFilePath(QString()), videoMethod(VIDEO_METHOD_VARIABLE),
                videoSpeed(VIDEO_SPEED_MEDIUM), videoQuality(VIDEO_QUALITY_MEDIUM),
                videoBitRate(1200), videoMaxSize(0.0), videoFramesPerSecond(30.0),
                audioMethod(AUDIO_METHOD_VARIABLE), audioQuality(AUDIO_QUALITY_MEDIUM),
                audioBitRate(128)
{
    this->clear();
}

Settings::Settings(const QString& dataFilePath, const QString& multimediaFilePath,
        const int& videoMethod, const int& videoSpeed, const int& videoQuality,
        const int& videoBitRate, const double& videoMaxSize, const double& videoFramesPerSecond,
        const int& audioMethod, const int& audioQuality, const int& audioBitRate) :
        Settings()
{
    this->set(dataFilePath, multimediaFilePath, videoMethod, videoSpeed, videoQuality, videoBitRate,
            videoMaxSize, videoFramesPerSecond, audioMethod, audioQuality, audioBitRate);
}

Settings::Settings(const Settings& settings) :
        Settings()
{
    this->copy(settings);
}

Settings::~Settings()
{

}

const QString& Settings::getDataFilePath() const
{
    return this->dataFilePath;
}

const QString& Settings::getMultimediaFilePath() const
{
    return this->multimediaFilePath;
}

const int& Settings::getVideoMethod() const
{
    return this->videoMethod;
}

const int& Settings::getVideoSpeed() const
{
    return this->videoSpeed;
}

const int& Settings::getVideoQuality() const
{
    return this->videoQuality;
}

const int& Settings::getVideoBitRate() const
{
    return this->videoBitRate;
}

const double& Settings::getVideoMaxSize() const
{
    return this->videoMaxSize;
}

const double& Settings::getVideoFramesPerSecond() const
{
    return this->videoFramesPerSecond;
}

const int& Settings::getAudioMethod() const
{
    return this->audioMethod;
}

const int& Settings::getAudioQuality() const
{
    return this->audioQuality;
}

const int& Settings::getAudioBitRate() const
{
    return this->audioBitRate;
}

void Settings::setDataFilePath(const QString& dataFilePath)
{
    this->dataFilePath = dataFilePath;
}

void Settings::setMultimediaFilePath(const QString& multimediaFilePath)
{
    this->multimediaFilePath = multimediaFilePath;
}

void Settings::setVideoMethod(const int& videoMethod)
{
    this->videoMethod = videoMethod;
}

void Settings::setVideoSpeed(const int& videoSpeed)
{
    this->videoSpeed = videoSpeed;
}

void Settings::setVideoQuality(const int& videoQuality)
{
    this->videoQuality = videoQuality;
}

void Settings::setVideoBitRate(const int& videoBitRate)
{
    this->videoBitRate = videoBitRate;
}

void Settings::setVideoMaxSize(const double& videoMaxSize)
{
    this->videoMaxSize = videoMaxSize;
}

void Settings::setVideoFramesPerSecond(const double& videoFramesPerSecond)
{
    this->videoFramesPerSecond = videoFramesPerSecond;
}

void Settings::setAudioMethod(const int& audioMethod)
{
    this->audioMethod = audioMethod;
}

void Settings::setAudioQuality(const int& audioQuality)
{
    this->audioQuality = audioQuality;
}

void Settings::setAudioBitRate(const int& audioBitRate)
{
    this->audioBitRate = audioBitRate;
}

void Settings::clear()
{
    this->set(QString(), QString(), VIDEO_METHOD_VARIABLE, VIDEO_SPEED_MEDIUM, VIDEO_QUALITY_MEDIUM,
            1200, 0.0, 30.0, AUDIO_METHOD_VARIABLE, AUDIO_QUALITY_MEDIUM, 128);
}

void Settings::set(const QString& dataFilePath, const QString& multimediaFilePath,
        const int& videoMethod, const int& videoSpeed, const int& videoQuality,
        const int& videoBitRate, const double& videoMaxSize, const double& videoFramesPerSecond,
        const int& audioMethod, const int& audioQuality, const int& audioBitRate)
{
    this->setDataFilePath(dataFilePath);
    this->setMultimediaFilePath(multimediaFilePath);
    this->setVideoMethod(videoMethod);
    this->setVideoSpeed(videoSpeed);
    this->setVideoQuality(videoQuality);
    this->setVideoBitRate(videoBitRate);
    this->setVideoMaxSize(videoMaxSize);
    this->setVideoFramesPerSecond(videoFramesPerSecond);
    this->setAudioMethod(audioMethod);
    this->setAudioQuality(audioQuality);
    this->setAudioBitRate(audioBitRate);
}

void Settings::copy(const Settings& settings)
{
    this->set(settings.getDataFilePath(), settings.getMultimediaFilePath(),
            settings.getVideoMethod(), settings.getVideoSpeed(), settings.getVideoQuality(),
            settings.getVideoBitRate(), settings.getVideoMaxSize(),
            settings.getVideoFramesPerSecond(), settings.getAudioMethod(),
            settings.getAudioQuality(), settings.getAudioBitRate());
}

bool Settings::equals(const Settings& settings) const
{
    if (this->getDataFilePath() != settings.getDataFilePath())
        return false;
    if (this->getMultimediaFilePath() != settings.getMultimediaFilePath())
        return false;
    if (this->getVideoMethod() != settings.getVideoMethod())
        return false;
    if (this->getVideoSpeed() != settings.getVideoSpeed())
        return false;
    if (this->getVideoQuality() != settings.getVideoQuality())
        return false;
    if (this->getVideoBitRate() != settings.getVideoBitRate())
        return false;
    if (this->getVideoMaxSize() != settings.getVideoMaxSize())
        return false;
    if (this->getVideoFramesPerSecond() != settings.getVideoFramesPerSecond())
        return false;
    if (this->getAudioMethod() != settings.getAudioMethod())
        return false;
    if (this->getAudioQuality() != settings.getAudioQuality())
        return false;
    if (this->getAudioBitRate() != settings.getAudioBitRate())
        return false;
    return true;
}

void Settings::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = fromString.split(sep);
    if (fromStringList.count() < 11)
        return;
    this->setDataFilePath(fromStringList.at(0));
    this->setMultimediaFilePath(fromStringList.at(1));
    this->setVideoMethod(fromStringList.at(2).toInt());
    this->setVideoSpeed(fromStringList.at(3).toInt());
    this->setVideoQuality(fromStringList.at(4).toInt());
    this->setVideoBitRate(fromStringList.at(5).toInt());
    this->setVideoMaxSize(fromStringList.at(6).toDouble());
    this->setVideoFramesPerSecond(fromStringList.at(7).toDouble());
    this->setAudioMethod(fromStringList.at(8).toInt());
    this->setAudioQuality(fromStringList.at(9).toInt());
    this->setAudioBitRate(fromStringList.at(10).toInt());
}

const QString Settings::toString(const QChar& sep) const
{
    QString toString;
    toString += this->getDataFilePath() + sep;
    toString += this->getMultimediaFilePath() + sep;
    toString += QString::number(this->getVideoMethod()) + sep;
    toString += QString::number(this->getVideoSpeed()) + sep;
    toString += QString::number(this->getVideoQuality()) + sep;
    toString += QString::number(this->getVideoBitRate()) + sep;
    toString += QString::number(this->getVideoMaxSize()) + sep;
    toString += QString::number(this->getVideoFramesPerSecond()) + sep;
    toString += QString::number(this->getAudioMethod()) + sep;
    toString += QString::number(this->getAudioQuality()) + sep;
    toString += QString::number(this->getAudioBitRate());
    return toString;
}

bool Settings::operator==(const Settings& settings) const
{
    return this->equals(settings);
}

bool Settings::operator!=(const Settings& settings) const
{
    return !(this->equals(settings));
}

const QString Settings::getVideoSpeedToString() const
{
    const int& videoSpeed = this->getVideoSpeed();
    return QString("-preset %1").arg(
            (videoSpeed == VIDEO_SPEED_VERY_SLOW) ? QString("veryslow") :
            (videoSpeed == VIDEO_SPEED_SLOWER) ? QString("slower") :
            (videoSpeed == VIDEO_SPEED_SLOW) ? QString("slow") :
            (videoSpeed == VIDEO_SPEED_MEDIUM) ? QString("medium") :
            (videoSpeed == VIDEO_SPEED_FAST) ? QString("fast") :
            (videoSpeed == VIDEO_SPEED_FASTER) ? QString("faster") :
            (videoSpeed == VIDEO_SPEED_VERY_FAST) ? QString("veryfast") : QString("medium"));
}

const QString Settings::getVideoQualityToString() const
{
    const int& videoQuality = this->getVideoQuality();
    return QString("-crf %1").arg(
            QString::number(
                    (videoQuality == VIDEO_QUALITY_HIGH) ? 18 :
                    (videoQuality == VIDEO_QUALITY_MEDIUM) ? 23 :
                    (videoQuality == VIDEO_QUALITY_LOW) ? 28 : 23));
}

const QString Settings::getVideoBitRateToString() const
{
    const int& videoBitRate = this->getVideoBitRate();
    return QString("-b:v %1k").arg(QString::number(videoBitRate));
}

const QString Settings::getVideoFramesPerSecondToString() const
{
    const double& videoFramesPerSecond = this->getVideoFramesPerSecond();
    return QString("-r %1").arg(QString::number(videoFramesPerSecond));
}

const QString Settings::getAudioQualityToString() const
{
    const int& audioQuality = this->getAudioQuality();
    return QString("-vbr %1").arg(QString::number(5 - audioQuality));
}

const QString Settings::getAudioBitRateToString() const
{
    const int& audioBitRate = this->getAudioBitRate();
    return QString("-b:a %1k").arg(QString::number(audioBitRate));
}

const QString Settings::getVideoSettings(const int& duration) const
{
    const int& videoMethod = this->getVideoMethod();
    const QString videoSpeed = this->getVideoSpeedToString();
    const QString videoQuality = this->getVideoQualityToString();
    const QString videoBitRate = this->getVideoBitRateToString();
    const QString videoFramesPerSecond = this->getVideoFramesPerSecondToString();

    if (videoMethod == VIDEO_METHOD_MAX_SIZE)
    {
        const double& videoMaxSize = this->getVideoMaxSize();
        const int& audioBitRate = this->getAudioBitRate();

        const double totalTime = static_cast<double>(duration) / 1000.0;
        const int totalBitRate = static_cast<int>(floor(videoMaxSize * 8192.0 / totalTime));
        const int videoBitRateLocal = totalBitRate - audioBitRate;

        const Settings videoBitRateSettings = Settings(QString(), QString(), 0, 0, 0,
                videoBitRateLocal, 0.0, 0.0, 0, 0, 0);
        const QString videoBitRateUpdate = videoBitRateSettings.getVideoBitRateToString();
        const_cast<QString&>(videoBitRate) = videoBitRateUpdate;
    }

    const QString videoSet = ((videoMethod == VIDEO_METHOD_VARIABLE) ? videoQuality : videoBitRate);
    const QString videoSettings = QString("-c:v libx264 %1 %2 %3").arg(videoSpeed, videoSet,
            videoFramesPerSecond);

    return videoSettings;
}

const QString Settings::getAudioSettings() const
{
    const int& audioMethod = this->getAudioMethod();
    const QString audioQuality = this->getAudioQualityToString();
    const QString audioBitRate = this->getAudioBitRateToString();

    const QString audioSet = ((audioMethod == AUDIO_METHOD_VARIABLE) ? audioQuality : audioBitRate);
    const QString audioSettings = QString("-c:a aac %1").arg(audioSet);

    return audioSettings;
}

const QString Settings::getMetadataSettings() const
{
    return QString("-map_metadata -1");
}
