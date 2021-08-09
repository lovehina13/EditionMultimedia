//==============================================================================
// Name        : Settings.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (03/03/2020)
// Description : Source file of the Settings class
//==============================================================================

#include "Settings.h"
#include <QStringList>
#include <cmath>

Settings::Settings() :
        _dataFilePath(QString()), _multimediaFilePath(QString()),
                _videoMethod(VIDEO_METHOD_VARIABLE), _videoSpeed(VIDEO_SPEED_MEDIUM),
                _videoQuality(VIDEO_QUALITY_MEDIUM), _videoBitRate(1200), _videoMaxSize(0.0),
                _videoFramesPerSecond(30.0), _audioMethod(AUDIO_METHOD_VARIABLE),
                _audioQuality(AUDIO_QUALITY_MEDIUM), _audioBitRate(128), _fromTime(0), _toTime(0)
{
    clear();
}

Settings::Settings(const QString& dataFilePath, const QString& multimediaFilePath,
        const int& videoMethod, const int& videoSpeed, const int& videoQuality,
        const int& videoBitRate, const double& videoMaxSize, const double& videoFramesPerSecond,
        const int& audioMethod, const int& audioQuality, const int& audioBitRate,
        const int& fromTime, const int& toTime) :
        Settings()
{
    set(dataFilePath, multimediaFilePath, videoMethod, videoSpeed, videoQuality, videoBitRate,
            videoMaxSize, videoFramesPerSecond, audioMethod, audioQuality, audioBitRate, fromTime,
            toTime);
}

Settings::Settings(const Settings& settings) :
        Settings()
{
    copy(settings);
}

Settings::~Settings()
{

}

Settings& Settings::operator=(const Settings& settings)
{
    copy(settings);
    return *this;
}

bool Settings::operator==(const Settings& settings) const
{
    return equals(settings);
}

bool Settings::operator!=(const Settings& settings) const
{
    return !equals(settings);
}

const QString& Settings::getDataFilePath() const
{
    return _dataFilePath;
}

const QString& Settings::getMultimediaFilePath() const
{
    return _multimediaFilePath;
}

const int& Settings::getVideoMethod() const
{
    return _videoMethod;
}

const int& Settings::getVideoSpeed() const
{
    return _videoSpeed;
}

const int& Settings::getVideoQuality() const
{
    return _videoQuality;
}

const int& Settings::getVideoBitRate() const
{
    return _videoBitRate;
}

const double& Settings::getVideoMaxSize() const
{
    return _videoMaxSize;
}

const double& Settings::getVideoFramesPerSecond() const
{
    return _videoFramesPerSecond;
}

const int& Settings::getAudioMethod() const
{
    return _audioMethod;
}

const int& Settings::getAudioQuality() const
{
    return _audioQuality;
}

const int& Settings::getAudioBitRate() const
{
    return _audioBitRate;
}

const int& Settings::getFromTime() const
{
    return _fromTime;
}

const int& Settings::getToTime() const
{
    return _toTime;
}

void Settings::setDataFilePath(const QString& dataFilePath)
{
    _dataFilePath = dataFilePath;
}

void Settings::setMultimediaFilePath(const QString& multimediaFilePath)
{
    _multimediaFilePath = multimediaFilePath;
}

void Settings::setVideoMethod(const int& videoMethod)
{
    _videoMethod = videoMethod;
}

void Settings::setVideoSpeed(const int& videoSpeed)
{
    _videoSpeed = videoSpeed;
}

void Settings::setVideoQuality(const int& videoQuality)
{
    _videoQuality = videoQuality;
}

void Settings::setVideoBitRate(const int& videoBitRate)
{
    _videoBitRate = videoBitRate;
}

void Settings::setVideoMaxSize(const double& videoMaxSize)
{
    _videoMaxSize = videoMaxSize;
}

void Settings::setVideoFramesPerSecond(const double& videoFramesPerSecond)
{
    _videoFramesPerSecond = videoFramesPerSecond;
}

void Settings::setAudioMethod(const int& audioMethod)
{
    _audioMethod = audioMethod;
}

void Settings::setAudioQuality(const int& audioQuality)
{
    _audioQuality = audioQuality;
}

void Settings::setAudioBitRate(const int& audioBitRate)
{
    _audioBitRate = audioBitRate;
}

void Settings::setFromTime(const int& fromTime)
{
    _fromTime = fromTime;
}

void Settings::setToTime(const int& toTime)
{
    _toTime = toTime;
}

void Settings::clear()
{
    set(QString(), QString(), VIDEO_METHOD_VARIABLE, VIDEO_SPEED_MEDIUM, VIDEO_QUALITY_MEDIUM, 1200,
            0.0, 30.0, AUDIO_METHOD_VARIABLE, AUDIO_QUALITY_MEDIUM, 128, 0, 0);
}

void Settings::set(const QString& dataFilePath, const QString& multimediaFilePath,
        const int& videoMethod, const int& videoSpeed, const int& videoQuality,
        const int& videoBitRate, const double& videoMaxSize, const double& videoFramesPerSecond,
        const int& audioMethod, const int& audioQuality, const int& audioBitRate,
        const int& fromTime, const int& toTime)
{
    setDataFilePath(dataFilePath);
    setMultimediaFilePath(multimediaFilePath);
    setVideoMethod(videoMethod);
    setVideoSpeed(videoSpeed);
    setVideoQuality(videoQuality);
    setVideoBitRate(videoBitRate);
    setVideoMaxSize(videoMaxSize);
    setVideoFramesPerSecond(videoFramesPerSecond);
    setAudioMethod(audioMethod);
    setAudioQuality(audioQuality);
    setAudioBitRate(audioBitRate);
    setFromTime(fromTime);
    setToTime(toTime);
}

void Settings::copy(const Settings& settings)
{
    set(settings.getDataFilePath(), settings.getMultimediaFilePath(), settings.getVideoMethod(),
            settings.getVideoSpeed(), settings.getVideoQuality(), settings.getVideoBitRate(),
            settings.getVideoMaxSize(), settings.getVideoFramesPerSecond(),
            settings.getAudioMethod(), settings.getAudioQuality(), settings.getAudioBitRate(),
            settings.getFromTime(), settings.getToTime());
}

bool Settings::equals(const Settings& settings) const
{
    if (getDataFilePath() != settings.getDataFilePath())
        return false;
    if (getMultimediaFilePath() != settings.getMultimediaFilePath())
        return false;
    if (getVideoMethod() != settings.getVideoMethod())
        return false;
    if (getVideoSpeed() != settings.getVideoSpeed())
        return false;
    if (getVideoQuality() != settings.getVideoQuality())
        return false;
    if (getVideoBitRate() != settings.getVideoBitRate())
        return false;
    if (getVideoMaxSize() != settings.getVideoMaxSize())
        return false;
    if (getVideoFramesPerSecond() != settings.getVideoFramesPerSecond())
        return false;
    if (getAudioMethod() != settings.getAudioMethod())
        return false;
    if (getAudioQuality() != settings.getAudioQuality())
        return false;
    if (getAudioBitRate() != settings.getAudioBitRate())
        return false;
    if (getFromTime() != settings.getFromTime())
        return false;
    if (getToTime() != settings.getToTime())
        return false;
    return true;
}

void Settings::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = fromString.split(sep);
    if (fromStringList.count() < 13)
        return;
    setDataFilePath(fromStringList.at(0));
    setMultimediaFilePath(fromStringList.at(1));
    setVideoMethod(fromStringList.at(2).toInt());
    setVideoSpeed(fromStringList.at(3).toInt());
    setVideoQuality(fromStringList.at(4).toInt());
    setVideoBitRate(fromStringList.at(5).toInt());
    setVideoMaxSize(fromStringList.at(6).toDouble());
    setVideoFramesPerSecond(fromStringList.at(7).toDouble());
    setAudioMethod(fromStringList.at(8).toInt());
    setAudioQuality(fromStringList.at(9).toInt());
    setAudioBitRate(fromStringList.at(10).toInt());
    setFromTime(fromStringList.at(11).toInt());
    setToTime(fromStringList.at(12).toInt());
}

const QString Settings::toString(const QChar& sep) const
{
    QString toString;
    toString += getDataFilePath() + sep;
    toString += getMultimediaFilePath() + sep;
    toString += QString::number(getVideoMethod()) + sep;
    toString += QString::number(getVideoSpeed()) + sep;
    toString += QString::number(getVideoQuality()) + sep;
    toString += QString::number(getVideoBitRate()) + sep;
    toString += QString::number(getVideoMaxSize()) + sep;
    toString += QString::number(getVideoFramesPerSecond()) + sep;
    toString += QString::number(getAudioMethod()) + sep;
    toString += QString::number(getAudioQuality()) + sep;
    toString += QString::number(getAudioBitRate()) + sep;
    toString += QString::number(getFromTime()) + sep;
    toString += QString::number(getToTime());
    return toString;
}

const QString Settings::getVideoSpeedToString() const
{
    const int& videoSpeed = getVideoSpeed();
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
    const int& videoQuality = getVideoQuality();
    return QString("-crf %1").arg(
            QString::number(
                    (videoQuality == VIDEO_QUALITY_HIGH) ? 18 :
                    (videoQuality == VIDEO_QUALITY_MEDIUM) ? 23 :
                    (videoQuality == VIDEO_QUALITY_LOW) ? 28 : 23));
}

const QString Settings::getVideoBitRateToString() const
{
    const int& videoBitRate = getVideoBitRate();
    return QString("-b:v %1k").arg(QString::number(videoBitRate));
}

const QString Settings::getVideoFramesPerSecondToString() const
{
    const double& videoFramesPerSecond = getVideoFramesPerSecond();
    return QString("-r %1").arg(QString::number(videoFramesPerSecond));
}

const QString Settings::getAudioQualityToString() const
{
    const int& audioQuality = getAudioQuality();
    return QString("-vbr %1").arg(QString::number(5 - audioQuality));
}

const QString Settings::getAudioBitRateToString() const
{
    const int& audioBitRate = getAudioBitRate();
    return QString("-b:a %1k").arg(QString::number(audioBitRate));
}

const QString Settings::getVideoSettings() const
{
    const int& videoMethod = getVideoMethod();
    const QString videoSpeed = getVideoSpeedToString();
    const QString videoQuality = getVideoQualityToString();
    const QString videoBitRate = getVideoBitRateToString();
    const QString videoFramesPerSecond = getVideoFramesPerSecondToString();

    if (videoMethod == VIDEO_METHOD_MAX_SIZE)
    {
        const double& videoMaxSize = getVideoMaxSize();
        const int& audioBitRate = getAudioBitRate();
        const int& fromTime = getFromTime();
        const int& toTime = getToTime();

        const int totalTime = toTime - fromTime;
        const int totalBitRate = static_cast<int>(floor(
                (videoMaxSize * 8192.0) / (static_cast<double>(totalTime) / 1000.0)));
        const int videoBitRateLocal = totalBitRate - audioBitRate;

        const Settings videoBitRateSettings = Settings(QString(), QString(), 0, 0, 0,
                videoBitRateLocal, 0.0, 0.0, 0, 0, 0, 0, 0);
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
    const int& audioMethod = getAudioMethod();
    const QString audioQuality = getAudioQualityToString();
    const QString audioBitRate = getAudioBitRateToString();

    const QString audioSet = ((audioMethod == AUDIO_METHOD_VARIABLE) ? audioQuality : audioBitRate);
    const QString audioSettings = QString("-c:a aac %1").arg(audioSet);

    return audioSettings;
}

const QString Settings::getTimeSettings() const
{
    const int& fromTime = getFromTime();
    const int& toTime = getToTime();

    const QString timeSettings = QString("-ss %1 -to %2").arg(
            QString::number(static_cast<double>(fromTime) / 1000.0),
            QString::number(static_cast<double>(toTime) / 1000.0));

    return timeSettings;
}

const QString Settings::getMetadataSettings() const
{
    return QString("-map_metadata -1");
}
