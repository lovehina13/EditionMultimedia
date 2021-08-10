//==============================================================================
// Name        : Settings.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.0 (10/08/2021)
// Description : Header file of the Settings class
//==============================================================================

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QChar>
#include <QList>
#include <QMap>
#include <QString>

class Settings
{
public:
    enum VideoMethod
    {
        VIDEO_METHOD_VARIABLE, VIDEO_METHOD_CONSTANT, VIDEO_METHOD_MAX_SIZE
    };

    enum VideoSpeed
    {
        VIDEO_SPEED_VERY_SLOW, VIDEO_SPEED_SLOWER, VIDEO_SPEED_SLOW, VIDEO_SPEED_MEDIUM,
        VIDEO_SPEED_FAST, VIDEO_SPEED_FASTER, VIDEO_SPEED_VERY_FAST
    };

    enum VideoQuality
    {
        VIDEO_QUALITY_HIGH, VIDEO_QUALITY_MEDIUM, VIDEO_QUALITY_LOW
    };

    enum AudioMethod
    {
        AUDIO_METHOD_VARIABLE, AUDIO_METHOD_CONSTANT
    };

    enum AudioQuality
    {
        AUDIO_QUALITY_VERY_HIGH, AUDIO_QUALITY_HIGH, AUDIO_QUALITY_MEDIUM, AUDIO_QUALITY_LOW,
        AUDIO_QUALITY_VERY_LOW
    };

    // Constructors and destructors
    Settings() = default;
    Settings(const QString& dataFilePath, const QString& multimediaFilePath,
            const VideoMethod& videoMethod, const VideoSpeed& videoSpeed,
            const VideoQuality& videoQuality, const int& videoBitRate, const double& videoMaxSize,
            const double& videoFramesPerSecond, const AudioMethod& audioMethod,
            const AudioQuality& audioQuality, const int& audioBitRate, const int& fromTime,
            const int& toTime);

    // Operators
    bool operator==(const Settings& settings) const = default;
    bool operator!=(const Settings& settings) const = default;

    // Getters
    const QString& getDataFilePath() const;
    const QString& getMultimediaFilePath() const;
    const VideoMethod& getVideoMethod() const;
    const VideoSpeed& getVideoSpeed() const;
    const VideoQuality& getVideoQuality() const;
    const int& getVideoBitRate() const;
    const double& getVideoMaxSize() const;
    const double& getVideoFramesPerSecond() const;
    const AudioMethod& getAudioMethod() const;
    const AudioQuality& getAudioQuality() const;
    const int& getAudioBitRate() const;
    const int& getFromTime() const;
    const int& getToTime() const;

    // Setters
    void setDataFilePath(const QString& dataFilePath);
    void setMultimediaFilePath(const QString& multimediaFilePath);
    void setVideoMethod(const VideoMethod& videoMethod);
    void setVideoSpeed(const VideoSpeed& videoSpeed);
    void setVideoQuality(const VideoQuality& videoQuality);
    void setVideoBitRate(const int& videoBitRate);
    void setVideoMaxSize(const double& videoMaxSize);
    void setVideoFramesPerSecond(const double& videoFramesPerSecond);
    void setAudioMethod(const AudioMethod& audioMethod);
    void setAudioQuality(const AudioQuality& audioQuality);
    void setAudioBitRate(const int& audioBitRate);
    void setFromTime(const int& fromTime);
    void setToTime(const int& toTime);

    // Generic methods
    void clear();
    void set(const QString& dataFilePath, const QString& multimediaFilePath,
            const VideoMethod& videoMethod, const VideoSpeed& videoSpeed,
            const VideoQuality& videoQuality, const int& videoBitRate, const double& videoMaxSize,
            const double& videoFramesPerSecond, const AudioMethod& audioMethod,
            const AudioQuality& audioQuality, const int& audioBitRate, const int& fromTime,
            const int& toTime);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Specific methods
    const QString getVideoSpeedToString() const;
    const QString getVideoQualityToString() const;
    const QString getVideoBitRateToString() const;
    const QString getVideoFramesPerSecondToString() const;
    const QString getAudioQualityToString() const;
    const QString getAudioBitRateToString() const;
    const QString getVideoSettings() const;
    const QString getAudioSettings() const;
    const QString getTimeSettings() const;
    const QString getMetadataSettings() const;

private:
    // Class members
    QString _dataFilePath;
    QString _multimediaFilePath;
    VideoMethod _videoMethod { VIDEO_METHOD_VARIABLE };
    VideoSpeed _videoSpeed { VIDEO_SPEED_MEDIUM };
    VideoQuality _videoQuality { VIDEO_QUALITY_MEDIUM };
    int _videoBitRate { 1200 };
    double _videoMaxSize { 0.0 };
    double _videoFramesPerSecond { 30.0 };
    AudioMethod _audioMethod { AUDIO_METHOD_VARIABLE };
    AudioQuality _audioQuality { AUDIO_QUALITY_MEDIUM };
    int _audioBitRate { 128 };
    int _fromTime { 0 };
    int _toTime { 0 };
};

using SettingsPtr = Settings*;
using SettingsList = QList<Settings>;
using SettingsPtrList = QList<SettingsPtr>;
using SettingsIdMap = QMap<int, Settings>;
using SettingsPtrIdMap = QMap<int, SettingsPtr>;
using SettingsNamesMap = QMap<QString, Settings>;
using SettingsPtrNamesMap = QMap<QString, SettingsPtr>;

#endif /* SETTINGS_H */
