#include <my_libc/maxabs.h>

extern DLL_FUNC long long maxabs(long long __value) {
  if (__value < 0) {
    __value = -__value;
  }
  return __value;
}

#if (!defined(OLD_CODE) || (OLD_CODE == 0)) ||                                  \
    (defined(NEW_CODE) && (NEW_CODE != 0))
extern DLL_FUNC __int128_t __libc_maxabs_v1(__int128_t __value) {
  if (__value < 0) {
    __value = -__value;
  }
  return __value;
}
#endif

extern DLL_FUNC int my_libc_magic_number (void) {
#if (!defined(OLD_CODE) || (OLD_CODE == 0)) ||                                  \
    (defined(NEW_CODE) && (NEW_CODE != 0))
  return 1;
#else
  return 0;
#endif
}

