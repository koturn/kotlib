/*!
 * @file defsupport.h
 * @brief Define support macros
 * @author koturn
 */
#ifndef KOTLIB_COMPAT_DEFSUPPORT_H
#define KOTLIB_COMPAT_DEFSUPPORT_H


#define KOTLIB_COMPAT_IS_SUPPORT_C99 \
  (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
#define KOTLIB_COMPAT_IS_SUPPORT_C11 \
  (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
#define KOTLIB_COMPAT_IS_SUPPORT_CXX11 \
  (defined(__cplusplus) && __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__))
#define KOTLIB_COMPAT_IS_SUPPORT_CXX14 \
  (defined(__cplusplus) && __cplusplus >= 201300L)


#define KOTLIB_COMPAT_GNUC_PREREQ(major, minor) \
  (defined(__GNUC__) && defined(__GNUC_MINOR__) && \
    (__GNUC__ > (major) || (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor))))
#define KOTLIB_COMPAT_CLANG_PREREQ(major, minor) \
  (defined(__clang_major__) && defined(__clang_minor__) && \
    (__clang_major__ > (major) || (__clang_major__ == (major) && __clang_minor__ >= (minor))))


#endif  // KOTLIB_COMPAT_DEFSUPPORT_H
