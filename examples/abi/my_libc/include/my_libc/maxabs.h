#ifndef MY_LIBC_MAXABS
#define MY_LIBC_MAXABS

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

#if (defined(OLD_CODE) && (OLD_CODE != 0)) ||                                  \
    (!defined(NEW_CODE) || (NEW_CODE == 0))
typedef long long intmax_t;
extern DLL_FUNC long long maxabs(long long value) WEAK_DECL;
#else
typedef __int128_t intmax_t;
extern DLL_FUNC __int128_t __libc_maxabs_v1(__int128_t value) WEAK_DECL;
_Weak _Alias maxabs [[nodiscard]] = __libc_maxabs_v1;
#endif

extern DLL_FUNC int my_libc_magic_number (void);

#endif
