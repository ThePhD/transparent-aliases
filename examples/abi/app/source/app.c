#include <my_libc/maxabs.h>

int main() {
  intmax_t abi_is_hard = -(intmax_t)sizeof(intmax_t);
  intmax_t but_not_that_hard = maxabs(abi_is_hard);
  return ((int)(but_not_that_hard) == sizeof(intmax_t)) ? 0 : 1;
}
