/*!
 * @file  c99.h
 * @brief  Provide C99 compatibility
 * @author  koturn
 */
#ifndef KOTLIB_COMPAT_C99_H
#define KOTLIB_COMPAT_C99_H

#include "defsupport.h"


#if defined(_MSC_VER) || KOTLIB_COMPAT_IS_SUPPORT_C99
#  define __func__  __FUNCTION__
#endif


#ifndef __cplusplus
#  if defined(_MSC_VER)
#    define inline      __inline
#    define __inline__  __inline
#  elif !defined(__GNUC__) && KOTLIB_COMPAT_IS_SUPPORT_C99
#    define inline
#    define __inline
#  endif
#endif


#if defined(_MSC_VER) && _MSC_VER >= 1400
#  define restrict      __restrict
#  define __restrict__  __restrict
#elif !KOTLIB_COMPAT_IS_SUPPORT_C99
#  if defined(__GNUC__)
#    define restrict    __restrict
#  else
#    define restrict
#    define __restrict
#    define __restrict__
#  endif
#endif


#endif  // KOTLIB_COMPAT_C99_H
