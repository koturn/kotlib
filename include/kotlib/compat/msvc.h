/*!
 * @file  msvc.h
 * @brief  Provide MSVC compatibility
 * @author  koturn
 */
#ifndef KOTLIB_COMPAT_MSVC_H
#define KOTLIB_COMPAT_MSVC_H


#ifndef _MSC_VER
#  define _declspec(x)
#  define __declspec(x)
#endif


#endif  // KOTLIB_COMPAT_MSVC_H
