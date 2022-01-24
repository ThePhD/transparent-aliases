int zzz(int requested_sleep_time) { return requested_sleep_time;}
_Alias sleep_alias = zzz;
_Alias sleep_alias = sleep_alias;
_Alias sleep_alias_alias = zzz;
_Alias sleep_alias = sleep_alias_alias;
_Alias redecl_zzz = zzz;
int redecl_zzz(int requested_sleep_time); // okay, considered redeclaration
void func(void) {}

int main() {
  typedef void(func_type)(void);
  typedef int(zzz_type)(int);
  func_type *old_func = func;
  // Inner scope.
  _Alias func = func;
  func_type *new_func = func;
  if (old_func != new_func) {
    return 1;
  }
  zzz_type* old_zzz = zzz;
  zzz_type* new_zzz = redecl_zzz;
  if (old_zzz != new_zzz) {
    return 2;
  }
  return 0;
}
