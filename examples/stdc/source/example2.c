int zzz(int requested_sleep_time) { return requested_sleep_time;}
_Alias sleep_alias = zzz;
_Alias sleep_alias = sleep_alias;
_Alias sleep_alias_alias = zzz;
_Alias sleep_alias = sleep_alias_alias;
void func(void) {}

int main() {
  typedef void(func_type)(void);
  func_type *old_f = func;
  // Inner scope.
  _Alias func = func;
  func_type *new_f = func;
  if (old_f != new_f) {
    return 1;
  }
  return 0;
}
