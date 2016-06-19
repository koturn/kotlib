/*!
 * @file cxx11.h
 * @brief Compatible utility for C++11
 * @author koturn
 */
#ifndef KOTLIB_COMPAT_CXX11_H
#define KOTLIB_COMPAT_CXX11_H

#include "defsupport.h"


#if !KOTLIB_COMPAT_IS_SUPPORT_CXX11 && defined(__GNUC__)
#  define decltype(expr)  typeof(expr)
#endif


#if KOTLIB_COMPAT_IS_SUPPORT_C11
#  define  static_assert(expr, msg)  _Static_assert(expr, msg)
#elif defined(_MSC_VER) && _MSC_VER < 1600 || \
  !(KOTLIB_COMPAT_IS_SUPPORT_CXX11 && \
    (KOTLIB_COMPAT_GNUC_PREREQ(4, 3) || KOTLIB_COMPAT_CLANG_PREREQ(2, 9)))
#  ifdef __COUNTER__
#    define KOTLIB_COMPAT_STATIC_ASSERT_ARRAY__ \
       KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO(KOTLIB_COMPAT_STATIC_ASSERT_ARRAY, _, __LINE__, _, __COUNTER__, __)
#    define KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO(arg1, arg2, arg3, arg4, arg5, arg6) \
       KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO_(arg1, arg2, arg3, arg4, arg5, arg6)
#    define KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO_(arg1, arg2, arg3, arg4, arg5, arg6) \
       KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO__(arg1, arg2, arg3, arg4, arg5, arg6)
#    define KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO__(arg1, arg2, arg3, arg4, arg5, arg6) \
       arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6
#  else
#    define KOTLIB_COMPAT_STATIC_ASSERT_ARRAY__ \
       KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO(KOTLIB_COMPAT_STATIC_ASSERT_ARRAY, _, __LINE__, __)
#    define KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO(arg1, arg2, arg3, arg4) \
       KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO_(arg1, arg2, arg3, arg4)
#    define KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO_(arg1, arg2, arg3, arg4) \
       KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO__(arg1, arg2, arg3, arg4)
#    define KOTLIB_COMPAT_STATIC_ASSERT_CONCAT_MACRO__(arg1, arg2, arg3, arg4) \
       arg1 ## arg2 ## arg3 ## arg4
#  endif
#  define KOTLIB_STATIC_ASSERT_ARRAY  KOTLIB_COMPAT_STATIC_ASSERT_ARRAY__
#  ifdef __cplusplus
#    define static_assert(expr, msg) \
       typedef char KOTLIB_STATIC_ASSERT_ARRAY[(expr) ? 1 : -static_cast<int>(sizeof(msg))];
#  else
#    define static_assert(expr, msg) \
       typedef char KOTLIB_STATIC_ASSERT_ARRAY[(expr) ? 1 : -(int) sizeof(msg)];
#  endif
#endif


#if defined(_MSC_VER) && _MSC_VER < 1600 || \
  !(KOTLIB_COMPAT_IS_SUPPORT_CXX11 && \
    (KOTLIB_COMPAT_GNUC_PREREQ(4, 6) || KOTLIB_COMPAT_CLANG_PREREQ(3, 0)))
#  define nullptr  NULL
#endif


#if defined(_MSC_VER) && _MSC_VER < 1700 || !KOTLIB_COMPAT_IS_SUPPORT_CXX11
#  define final
#  define override
#endif


#if defined(_MSC_VER) && _MSC_VER < 1800 || \
  !(KOTLIB_COMPAT_IS_SUPPORT_CXX11 && KOTLIB_COMPAT_GNUC_PREREQ(4, 6))
#  define noexcept
#endif


#if _MSC_FULL_VER < 190023506L || \
  !(KOTLIB_COMPAT_IS_SUPPORT_CXX11 && \
    (KOTLIB_COMPAT_GNUC_PREREQ(4, 6) || KOTLIB_COMPAT_CLANG_PREREQ(3, 1)))
#  define constexpr  const
#endif


#if !(KOTLIB_COMPAT_IS_SUPPORT_CXX11 && \
  (KOTLIB_COMPAT_GNUC_PREREQ(4, 8) || KOTLIB_COMPAT_CLANG_PREREQ(3, 3)))
#  if defined(_MSC_VER) && 1600 <= _MSC_VER && _MSC_VER < 1800
#    define thread_local  __declspec(thread)
#  elif defined(__GNUC__)
#    define thread_local  __thread
#  elif KOTLIB_COMPAT_IS_SUPPORT_C11
#    define thread_local  _Thread_local
#  endif
#endif


#if !(KOTLIB_COMPAT_IS_SUPPORT_CXX11 && \
  (KOTLIB_COMPAT_GNUC_PREREQ(4, 8) || KOTLIB_COMPAT_CLANG_PREREQ(3, 3)))
#  if defined(_MSC_VER) && 1300 <= _MSC_VER && _MSC_VER < 1800
#    define alignas(n)  __declspec(align(n))
#  elif defined(__GNUC__)
#    define alignas(n)  __attribute__((aligned(n)))
#  elif KOTLIB_COMPAT_IS_SUPPORT_C11
#    define alignas(n)  _Alignas(n)
#  endif
#endif


#if defined(_MSC_VER) && 1300 <= _MSC_VER && _MSC_VER < 1800 || \
  !KOTLIB_COMPAT_IS_SUPPORT_CXX11 && defined(__GNUC__)
#  define alignof(n)  __alignof(n)
#endif


// #include "undefsupport.h"

#endif  // KOTLIB_COMPAT_CXX11_H
