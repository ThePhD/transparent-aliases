#include <my_libc/defs.h>

extern DLL_FUNC int my_libc_magic_number (void) {
#if (MY_LIBC_NEW_CODE == 0)
	return 0;
#else
	return 1;
#endif
}

extern DLL_FUNC long long maxabs(long long __value) {
	if (__value < 0) {
		__value = -__value;
	}
	return __value;
}
