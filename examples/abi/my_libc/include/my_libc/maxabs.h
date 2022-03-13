#ifndef MY_LIBC_MAXABS_H
#define MY_LIBC_MAXABS_H

#include <my_libc/defs.h>

extern DLL_FUNC int my_libc_magic_number (void);

#if (MY_LIBC_NEW_CODE == 0)
	typedef long long intmax_t;
	extern DLL_FUNC long long maxabs(long long value) WEAK_DECL;
#else
	typedef __int128_t intmax_t;
	extern DLL_FUNC __int128_t __libc_maxabs_v1(__int128_t value) WEAK_DECL;
	_Alias maxabs [[nodiscard]] = __libc_maxabs_v1;
#endif

#endif

#endif
