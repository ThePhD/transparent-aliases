int direct_call(int x) { return x; }
_Alias alias_call_right_nodsicard [[nodiscard]] = direct_call;
[[nodiscard]] _Alias alias_call_left_nodsicard = direct_call;
