#ifndef MY_LIBC_DEFS_H
#define MY_LIBC_DEFS_H

#if defined(_MSC_VER)
#define WEAK_DECL
#if defined(MY_LIBC_BUILDING)
#define DLL_FUNC __declspec(dllexport)
#else
#define DLL_FUNC __declspec(dllimport)
#endif
#else
#define WEAK_DECL __attribute__((weak))
#if defined(_WIN32)
#if defined(MY_LIBC_BUILDING)
#define DLL_FUNC __attribute__(dllexport)
#else
#define DLL_FUNC __attribute__(dllimport)
#endif
#else
#define DLL_FUNC __attribute__((visibility("default")))
#endif
#endif

#if (defined(OLD_CODE) && (OLD_CODE != 0)) ||                                  \
    (!defined(NEW_CODE) || (NEW_CODE == 0))
    #define MY_LIBC_NEW_CODE 0
#else
    #define MY_LIBC_NEW_CODE 1
#endif

#endif
