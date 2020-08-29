#ifndef RA_LOG_H
#define RA_LOG_H
#pragma once

#include "services\ILogger.hh"

#ifdef RA_UTEST

#define RA_LOG_LEVEL(lvl, ...)
#define RA_LOG(...)

#else

#include "RA_StringUtils.h"

#include "services\ServiceLocator.hh"

#define RA_LOG_LEVEL(lvl, ...) \
{ \
    const auto& __pLogger = ra::services::ServiceLocator::Get<ra::services::ILogger>(); \
    if (__pLogger.IsEnabled(lvl)) \
        __pLogger.LogMessage(lvl, ra::StringPrintf(__VA_ARGS__)); \
}

#endif

#define RA_LOG_INFO(...) RA_LOG_LEVEL(ra::services::LogLevel::Info, __VA_ARGS__)
#define RA_LOG_WARN(...) RA_LOG_LEVEL(ra::services::LogLevel::Warn, __VA_ARGS__)
#define RA_LOG_ERR(...) RA_LOG_LEVEL(ra::services::LogLevel::Error, __VA_ARGS__)

#endif // !RA_LOG_H
