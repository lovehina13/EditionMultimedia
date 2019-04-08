//==============================================================================
// Name        : Settings.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
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
    // Constructors and destructors
    Settings();
    Settings(const QString& dataFilePath, const QString& multimediaFilePath, const int& videoMethod,
            const int& videoQuality, const int& videoSpeed, const int& videoBitRate,
            const double& videoMaxSize, const double& videoFramesPerSecond, const int& audioMethod,
            const int& audioBitRate);
    Settings(const Settings& settings);
    virtual ~Settings();

    // Getters
    const QString& getDataFilePath() const;
    const QString& getMultimediaFilePath() const;
    const int& getVideoMethod() const;
    const int& getVideoQuality() const;
    const int& getVideoSpeed() const;
    const int& getVideoBitRate() const;
    const double& getVideoMaxSize() const;
    const double& getVideoFramesPerSecond() const;
    const int& getAudioMethod() const;
    const int& getAudioBitRate() const;

    // Setters
    void setDataFilePath(const QString& dataFilePath);
    void setMultimediaFilePath(const QString& multimediaFilePath);
    void setVideoMethod(const int& videoMethod);
    void setVideoQuality(const int& videoQuality);
    void setVideoSpeed(const int& videoSpeed);
    void setVideoBitRate(const int& videoBitRate);
    void setVideoMaxSize(const double& videoMaxSize);
    void setVideoFramesPerSecond(const double& videoFramesPerSecond);
    void setAudioMethod(const int& audioMethod);
    void setAudioBitRate(const int& audioBitRate);

    // Generic methods
    void clear();
    void set(const QString& dataFilePath, const QString& multimediaFilePath, const int& videoMethod,
            const int& videoQuality, const int& videoSpeed, const int& videoBitRate,
            const double& videoMaxSize, const double& videoFramesPerSecond, const int& audioMethod,
            const int& audioBitRate);
    void copy(const Settings& settings);
    bool equals(const Settings& settings) const;
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Specific methods
    bool operator==(const Settings& settings) const;
    bool operator!=(const Settings& settings) const;

    enum videoMethods
    {
        VIDEO_METHOD_VARIABLE, VIDEO_METHOD_CONSTANT, VIDEO_METHOD_MAX_SIZE
    };

    enum videoQualities
    {
        VIDEO_QUALITY_HIGH, VIDEO_QUALITY_MEDIUM, VIDEO_QUALITY_LOW
    };

    enum videoSpeeds
    {
        VIDEO_SPEED_VERY_SLOW, VIDEO_SPEED_SLOWER, VIDEO_SPEED_SLOW, VIDEO_SPEED_MEDIUM,
        VIDEO_SPEED_FAST, VIDEO_SPEED_FASTER, VIDEO_SPEED_VERY_FAST
    };

    enum audioMethods
    {
        AUDIO_METHOD_VARIABLE, AUDIO_METHOD_CONSTANT
    };

private:
    // Class members
    QString dataFilePath;
    QString multimediaFilePath;
    int videoMethod;
    int videoQuality;
    int videoSpeed;
    int videoBitRate;
    double videoMaxSize;
    double videoFramesPerSecond;
    int audioMethod;
    int audioBitRate;
};

typedef Settings* SettingsPtr;
typedef QList<Settings> SettingsList;
typedef QList<SettingsPtr> SettingsPtrList;
typedef QMap<int, Settings> SettingsIdMap;
typedef QMap<int, SettingsPtr> SettingsPtrIdMap;
typedef QMap<QString, Settings> SettingsNamesMap;
typedef QMap<QString, SettingsPtr> SettingsPtrNamesMap;

#endif /* SETTINGS_H */
