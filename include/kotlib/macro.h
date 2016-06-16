/*!
 * @file    macro.h
 * @brief Macro utility
 * @author  koturn
 */
#ifndef KOTLIB_MACRO_H
#define KOTLIB_MACRO_H

#include <string>


#if defined(_MSC_VER)
#  define KOTLIB_FUNCTION  __FUNCSIG__
#elif defined(__GNUC__)
#  define KOTLIB_FUNCTION  __PRETTY_FUNCTION__
#else
#  define KOTLIB_FUNCTION  __func__
#endif


#define KOTLIB_STRINGIFY(x)  KOTLIB_STRINGIFY__(x)
#define KOTLIB_STRINGIFY__(x)  #x

#define KOTLIB_LOCATION  ("File: " __FILE__ " at line " KOTLIB_STRINGIFY(__LINE__) " " + std::string(KOTLIB_FUNCTION))

#define KOTLIB_MAKE_EXCEPTION_MSG(msg) \
  KOTLIB_MAKE_EXCEPTION_MSG__("", msg)

#define KOTLIB_MAKE_EXCEPTION_MSG__(HEAD_STRLITERAL, msg) \
  (HEAD_STRLITERAL + KOTLIB_LOCATION + ": " + msg)

#define KOTLIB_THROW(EXCEPTION, msg) \
  throw EXCEPTION(KOTLIB_MAKE_EXCEPTION_MSG__(KOTLIB_STRINGIFY(EXCEPTION) ": ",  msg));

#define KOTLIB_THROW_IF(cond, EXCEPTION, msg) \
  if (cond) KOTLIB_THROW(EXCEPTION, "if (" #cond "): " + msg)

#define KOTLIB_THROW_IFNOT(cond, EXCEPTION, msg) \
  if (!(cond)) KOTLIB_THROW(EXCEPTION, "unless (" #cond "): " + msg)

#define KOTLIB_THROW_ELSEIF(cond, EXCEPTION, msg) \
  else if (cond) KOTLIB_THROW(EXCEPTION, "if (" #cond "): " + msg)

#define KOTLIB_THROW_ELSEIFNOT(cond, EXCEPTION, msg) \
  else if (!(cond)) KOTLIB_THROW(EXCEPTION, "unless (" #cond "): " + msg)

#define KOTLIB_THROW_ELSE(EXCEPTION, msg) \
  else KOTLIB_THROW(EXCEPTION, msg)


#ifdef KOTLIB_DEFINE_MACRO_WITHOUT_PREFIX
#  define FUNCTION  KOTLIB_FUNCTION
#  define STRINGIFY(x)  KOTLIB_STRINGIFY(x)
#  define LOCATION  KOTLIB_LOCATION
#  define MAKE_EXCEPTION_MSG(msg)  KOTLIB_MAKE_EXCEPTION_MSG(msg)
#  define THROW(EXCEPTION, msg)  KOTLIB_THROW(EXCEPTION, msg)
#  define THROW_IF(cond, EXCEPTION, msg)  KOTLIB_THROW_IF(cond, EXCEPTION, msg)
#  define THROW_IFNOT(cond, EXCEPTION, msg)  KOTLIB_THROW_IFNOT(cond, EXCEPTION, msg)
#  define THROW_ELSEIF(cond, EXCEPTION, msg)  KOTLIB_THROW_ELSEIF(cond, EXCEPTION, msg)
#  define THROW_ELSEIFNOT(cond, EXCEPTION, msg)  KOTLIB_THROW_ELSEIFNOT(cond, EXCEPTION, msg)
#  define THROW_ELSE(EXCEPTION, msg)  KOTLIB_THROW_ELSE(EXCEPTION, msg)
#endif  // KOTLIB_DEFINE_MACRO_WITHOUT_PREFIX


#endif  // KOTLIB_MACRO_H
