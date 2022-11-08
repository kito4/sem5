#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#define print_var(x) printf(#x " is %d\n", x )
#define y 20
int main() {
	int z = 30;
	print_var(10);
	print_var(y);
	print_var(z);
	return 0;
}
