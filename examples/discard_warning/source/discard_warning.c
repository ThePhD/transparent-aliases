#include <call.h>

int main() {
	direct_call(-50); // does not warn
	alias_call_right_nodiscard(-50); // attribute applies: warns
	alias_call_left_nodiscard(-50); // attribute applies: warns
	return 0;
}
