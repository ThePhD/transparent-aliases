double purr(void) { return 1.0; }
_Weak _Alias meow = purr;
double meow(int a) { return a + 2.0; }

int main() {
  double v = meow(2); // calls newest meow; alias is gone
  _Weak _Alias meow = purr; // shadows meow function declaration
  double x = meow(); // calls purr
  return ((int)(v + x) == 5 ? 0 : 1); // expects 5 (4 + 1)
}
