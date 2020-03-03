//==============================================================================
// Name        : Tools.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (03/03/2020)
// Description : Source file of the Tools elements
//==============================================================================

#include "Tools.h"
#include <QFile>
#include <QIODevice>
#include <QProcess>
#include <QTextStream>
#include <iostream>

int executeCommand(const QString& command, const bool& log)
{
    QProcess process;
    const int returnCode = process.execute(command);
    if (log)
    {
        std::cout << "Command: " << command.toStdString() << std::endl;
        std::cout << "ReturnCode: " << returnCode << std::endl;
    }
    return returnCode;
}

int executeCommand(const QString& command, const QString& outputFilePath,
        const QString& errorFilePath, const bool& log)
{
    QProcess process;
    process.start(command);
    process.waitForFinished(-1);
    const int returnCode = process.exitCode();
    if (log)
    {
        std::cout << "Command: " << command.toStdString() << std::endl;
        std::cout << "ReturnCode: " << returnCode << std::endl;
    }
    const QString output = process.readAllStandardOutput();
    const QString error = process.readAllStandardError();
    writeFileLines(outputFilePath, QStringList() << output);
    writeFileLines(errorFilePath, QStringList() << error);
    return returnCode;
}

const QStringList readFileLines(const QString& filePath)
{
    QStringList lines;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            const QString line = stream.readLine();
            lines.append(line);
        }
        file.close();
    }
    return lines;
}

void writeFileLines(const QString& filePath, const QStringList& lines)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        const int nbLines = lines.count();
        for (int itLine = 0; itLine < nbLines; itLine++)
        {
            const QString& line = lines.at(itLine);
            stream << line << endl;
        }
        file.close();
    }
}
