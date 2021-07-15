#include "rs_debug.h"
#include <iostream>
#include <cstdio>
#include <cstdarg>
#include <QDateTime>
#include <QString>

static RS_Debug* uniqueInstance = nullptr;

void debugHeader(const char *file, const char *func, int line)
{
    std::cout << file << " : " << func << " : line " << line << std::endl;
}

/**
 * Gets the one and only RS_Debug instance
 * (creates a new one on first call only)
 *
 * @return Pointer to the single instance of this singleton class
 */
RS_Debug *RS_Debug::instance()
{
    if (!uniqueInstance) {
        QDateTime now = QDateTime::currentDateTime();
        QString nowStr;
        nowStr = now.toString("yyyyMMdd_hhmmss");

        QString fName = QString("debug_%1.log").arg(nowStr);

        uniqueInstance = new RS_Debug;
        uniqueInstance->stream = fopen(fName.toLatin1(), "wt");
        // uniqueInstance->stream = stderr;
    }
    return uniqueInstance;
}

/**
 * Deletes the one and only RS_Debug instance.
 */
void RS_Debug::deleteInstance()
{
    if (uniqueInstance) {
        fclose(uniqueInstance->stream);
        delete uniqueInstance;
        uniqueInstance = nullptr;
    }
}

/**
 * Sets the debugging level.
 */
void RS_Debug::setLevel(RS_DebugLevel level)
{
    if (debugLevel == level) {
        return;
    }
    debugLevel = level;
    print( D_NOTHING, "RS_DEBUG::setLevel(%d)", level );
    print( D_CRITICAL, "RS_DEBUG: Critical" );
    print( D_ERROR, "RS_DEBUG: Error" );
    print( D_WARNING, "RS_DEBUG: Warning" );
    print( D_INFORMATIONAL, "RS_DEBUG: Infomational" );
    print( D_DEBUGGING, "RS_DEBUG: Debugging" );
}

/**
 * Returns the current debugging level.
 */
RS_Debug::RS_DebugLevel RS_Debug::getLevel()
{
    return debugLevel;
}

/**
 * Prints the given message to stdout if the current debug level
 * is lower then the given level
 */
void RS_Debug::print(RS_DebugLevel level, const char* format ...)
{
    if (level <= debugLevel) {
        va_list ap;
        va_start(ap, format);
        vfprintf(stream, format, ap);
        fprintf(stream, "\n");
        va_end(ap);
        fflush(stream);
    }
}

/**
 * Prints the given message to stdout if the given level is D_DEBUGGING.
 */
void RS_Debug::print(const char *format ...)
{
    if (debugLevel == D_DEBUGGING) {
        va_list ap;
        va_start(ap, format);
        vfprintf(stream, format, ap);
        fprintf(stream, "\n");
        va_end(ap);
        fflush(stream);
    }
}

/**
 * Constructor setting the default debug level.
 */
RS_Debug::RS_Debug()
    : debugLevel(D_DEBUGGING)
{

}
