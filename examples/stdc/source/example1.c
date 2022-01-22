int do_work(void) { return 0; }
int take_nap(void) { return 1; }
_Alias work_alias = do_work;
_Alias nap_alias = take_nap;
_Alias alias_of_work_alias = work_alias;
_Alias alias_of_nap_alias = nap_alias;

int main() {
  _Alias local_work_alias = alias_of_work_alias;
  
  if (&do_work != &work_alias) {
    return 1;
  }
  if (&do_work != &alias_of_work_alias) {
    return 2;
  }
  if (&work_alias != &alias_of_work_alias) {
    return 3;
  }
  if (&take_nap != &nap_alias) {
    return 4;
  }
  if (&take_nap != &alias_of_nap_alias) {
    return 5;
  }
  if (&nap_alias != &alias_of_nap_alias) {
    return 6;
  }
  if (&take_nap == &work_alias) {
    return 7;
  }
  if (&do_work == &alias_of_nap_alias) {
    return 8;
  }
  if (&local_work_alias != &alias_of_work_alias) {
    return 9;
  }

  // calls do_work
  if (do_work() != 0) {
    return 10;
  }
  // calls do_work
  if (work_alias() != 0) {
    return 11;
  }
  // calls do_work
  if (alias_of_work_alias() != 0) {
    return 12;
  }
  // calls do_work
  if (local_work_alias() != 0) {
    return 13;
  }

  // calls take_nap
  if (take_nap() != 1) {
    return 14;
  }
  // calls take_nap
  if (nap_alias() != 1) {
    return 15;
  }
  // calls take_nap
  if (alias_of_nap_alias() != 1) {
    return 16;
  }
  return 0;
}
