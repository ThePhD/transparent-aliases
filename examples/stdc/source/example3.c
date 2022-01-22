int zzz(int requested_sleep_time);
int truncated_zzz(int requested_sleep_time);
_Alias sleep_alias = sleep_alias;     // constraint violation: sleep_alias does
                                      // not exist until the
                                      // semicolon is reached
_Alias zzz = truncated_zzz;           // constraint violation: cannot hide
                                      // existing declaration
_Alias truncated_zzz = truncated_zzz; // constraint violation: cannot change
                                      // function declaration
                                      // to function alias
_Alias valid_sleep_alias = zzz;
int valid_sleep_alias(int requested_sleep_time); // constraint violation:
                                                 // redeclaring function alias

int x;
_Alias xa = x;

int main() { return 0; }
