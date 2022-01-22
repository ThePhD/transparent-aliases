#include <call.h>

int main() {
	direct_call(-50); // does not warn
	alias_call_right_nodsicard(-50); // attribute applies: warns
	alias_call_left_nodsicard(-50); // attribute applies: warns
	return 0;
}
