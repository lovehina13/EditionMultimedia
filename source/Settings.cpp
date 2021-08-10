//==============================================================================
// Name        : Settings.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.0 (10/08/2021)
// Description : Source file of the Settings class
//==============================================================================

#include "Settings.h"
#include <QStringList>
#include <cmath>

using VideoMethod = Settings::VideoMethod;
using VideoSpeed = Settings::VideoSpeed;
using VideoQuality = Settings::VideoQuality;
using AudioMethod = Settings::AudioMethod;
using AudioQuality = Settings::AudioQuality;

Settings::Settings(const QString& dataFilePath, const QString& multimediaFilePath,
        const VideoMethod& videoMethod, const VideoSpeed& videoSpeed,
        const VideoQuality& videoQuality, const int& videoBitRate, const double& videoMaxSize,
        const double& videoFramesPerSecond, const AudioMethod& audioMethod,
        const AudioQuality& audioQuality, const int& audioBitRate, const int& fromTime,
        const int& toTime) :
        _dataFilePath(dataFilePath), _multimediaFilePath(multimediaFilePath),
                _videoMethod(videoMethod), _videoSpeed(videoSpeed), _videoQuality(videoQuality),
                _videoBitRate(videoBitRate), _videoMaxSize(videoMaxSize),
                _videoFramesPerSecond(videoFramesPerSecond), _audioMethod(audioMethod),
                _audioQuality(audioQuality), _audioBitRate(audioBitRate), _fromTime(fromTime),
                _toTime(toTime)
{
}

const QString& Settings::getDataFilePath() const
{
    return _dataFilePath;
}

const QString& Settings::getMultimediaFilePath() const
{
    return _multimediaFilePath;
}

const VideoMethod& Settings::getVideoMethod() const
{
    return _videoMethod;
}

const VideoSpeed& Settings::getVideoSpeed() const
{
    return _videoSpeed;
}

const VideoQuality& Settings::getVideoQuality() const
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

const AudioMethod& Settings::getAudioMethod() const
{
    return _audioMethod;
}

const AudioQuality& Settings::getAudioQuality() const
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

void Settings::setVideoMethod(const VideoMethod& videoMethod)
{
    _videoMethod = videoMethod;
}

void Settings::setVideoSpeed(const VideoSpeed& videoSpeed)
{
    _videoSpeed = videoSpeed;
}

void Settings::setVideoQuality(const VideoQuality& videoQuality)
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

void Settings::setAudioMethod(const AudioMethod& audioMethod)
{
    _audioMethod = audioMethod;
}

void Settings::setAudioQuality(const AudioQuality& audioQuality)
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
    *this = Settings();
}

void Settings::set(const QString& dataFilePath, const QString& multimediaFilePath,
        const VideoMethod& videoMethod, const VideoSpeed& videoSpeed,
        const VideoQuality& videoQuality, const int& videoBitRate, const double& videoMaxSize,
        const double& videoFramesPerSecond, const AudioMethod& audioMethod,
        const AudioQuality& audioQuality, const int& audioBitRate, const int& fromTime,
        const int& toTime)
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

void Settings::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = fromString.split(sep);
    if (fromStringList.count() < 13)
        return;
    setDataFilePath(fromStringList.at(0));
    setMultimediaFilePath(fromStringList.at(1));
    setVideoMethod(static_cast<VideoMethod>(fromStringList.at(2).toInt()));
    setVideoSpeed(static_cast<VideoSpeed>(fromStringList.at(3).toInt()));
    setVideoQuality(static_cast<VideoQuality>(fromStringList.at(4).toInt()));
    setVideoBitRate(fromStringList.at(5).toInt());
    setVideoMaxSize(fromStringList.at(6).toDouble());
    setVideoFramesPerSecond(fromStringList.at(7).toDouble());
    setAudioMethod(static_cast<AudioMethod>(fromStringList.at(8).toInt()));
    setAudioQuality(static_cast<AudioQuality>(fromStringList.at(9).toInt()));
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
    const VideoSpeed& videoSpeed = getVideoSpeed();
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
    const VideoQuality& videoQuality = getVideoQuality();
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
    const AudioQuality& audioQuality = getAudioQuality();
    return QString("-vbr %1").arg(QString::number(5 - audioQuality));
}

const QString Settings::getAudioBitRateToString() const
{
    const int& audioBitRate = getAudioBitRate();
    return QString("-b:a %1k").arg(QString::number(audioBitRate));
}

const QString Settings::getVideoSettings() const
{
    const VideoMethod& videoMethod = getVideoMethod();
    const QString videoSpeedText = getVideoSpeedToString();
    const QString videoQualityText = getVideoQualityToString();
    const QString videoBitRateText = getVideoBitRateToString();
    const QString videoFramesPerSecondText = getVideoFramesPerSecondToString();

    if (videoMethod == VIDEO_METHOD_MAX_SIZE)
    {
        const VideoSpeed& videoSpeed = getVideoSpeed();
        const VideoQuality& videoQuality = getVideoQuality();
        const double& videoMaxSize = getVideoMaxSize();
        const double& videoFramesPerSecond = getVideoFramesPerSecond();
        const AudioMethod& audioMethod = getAudioMethod();
        const AudioQuality& audioQuality = getAudioQuality();
        const int& audioBitRate = getAudioBitRate();
        const int& fromTime = getFromTime();
        const int& toTime = getToTime();

        const int totalTime = toTime - fromTime;
        const int totalBitRate = static_cast<int>(floor(
                (videoMaxSize * 8192.0) / (static_cast<double>(totalTime) / 1000.0)));
        const int videoBitRateUpdated = totalBitRate - audioBitRate;

        const Settings videoBitRateSettings = Settings(QString(), QString(), videoMethod,
                videoSpeed, videoQuality, videoBitRateUpdated, videoMaxSize, videoFramesPerSecond,
                audioMethod, audioQuality, audioBitRate, fromTime, toTime);
        const QString videoBitRateUpdatedText = videoBitRateSettings.getVideoBitRateToString();
        const_cast<QString&>(videoBitRateText) = videoBitRateUpdatedText;
    }

    const QString videoSet = (
            (videoMethod == VIDEO_METHOD_VARIABLE) ? videoQualityText : videoBitRateText);
    const QString videoSettings = QString("-c:v libx264 %1 %2 %3").arg(videoSpeedText, videoSet,
            videoFramesPerSecondText);

    return videoSettings;
}

const QString Settings::getAudioSettings() const
{
    const int& audioMethod = getAudioMethod();
    const QString audioQualityText = getAudioQualityToString();
    const QString audioBitRateText = getAudioBitRateToString();

    const QString audioSet = (
            (audioMethod == AUDIO_METHOD_VARIABLE) ? audioQualityText : audioBitRateText);
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
