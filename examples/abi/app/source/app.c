#include <my_libc/maxabs.h>

#include <stdio.h>

int main() {
  intmax_t abi_is_hard = -(intmax_t)sizeof(intmax_t);
  intmax_t but_not_that_hard = maxabs(abi_is_hard);
  printf("%d\n", my_libc_magic_number());
  return ((int)(but_not_that_hard) == sizeof(intmax_t)) ? 0 : 1;
}
