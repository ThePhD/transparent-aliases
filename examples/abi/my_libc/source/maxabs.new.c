#include <my_libc/defs.h>

#if (MY_LIBC_NEW_CODE > 0)
extern DLL_FUNC __int128_t __libc_maxabs_v1(__int128_t __value) {
	if (__value < 0) {
		__value = -__value;
	}
	return __value;
}
#endif
