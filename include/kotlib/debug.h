/*!
 * @file debug.h
 * @brief Debug utilities
 * @author koturn
 */
#ifndef KOTLIB_DEBUG_H
#define KOTLIB_DEBUG_H


#if defined(_MSC_VER) && !defined(NDEBUG)
#  define _CRTDBG_MAP_ALLOC
#  include <crtdbg.h>
#endif  // defined(_MSC_VER) && !defined(NDEBUG)
#include <iostream>
#include <string>
#include "macro.h"


#ifdef NDEBUG
#  define KOTLIB_DBGLOG(...)  static_cast<void>(0)
#  define KOTLIB_DBGDUMP(var)  static_cast<void>(0)
#else
#  define KOTLIB_DBGLOG(...)  kot::dbglog(KOTLIB_LOCATION, ##__VA_ARGS__)
#  define KOTLIB_DBGDUMP(var)  kot::dbgdump(KOTLIB_LOCATION, #var, var)


namespace kot
{

static inline void
dbglog(const std::string& location)
{
  std::cerr << location << std::endl;
}


static inline void
dbglog(const std::string& location, const std::string& msg)
{
  std::cerr << location << ": " << msg << std::endl;
}


template<typename T>
static inline void
dbgdump(const std::string& location, const char* varname, const T& var)
{
  std::cerr << location << ": " << varname << " = " << var << std::endl;
}

}  // namespace kot
#endif  //  NDEBUG

#ifdef KOTLIB_DEFINE_MACRO_WITHOUT_PREFIX
#  define DBGLOB(...)  KOTLIB_DBGLOG(__VA_ARGS__)
#  define DBGDUMP(var)  KOTLIB_DBGDUMP(var)
#endif  // KOTLIB_DEFINE_MACRO_WITHOUT_PREFIX


namespace kot
{

static inline void
enableMSVCMemoryDebug()
{
#if defined(_MSC_VER) && !defined(NDEBUG)
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_DELAY_FREE_MEM_DF);
  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
  _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
#endif  // defined(_MSC_VER) && !defined(NDEBUG)
}

}


#endif  // KOTLIB_DEBUG_H
