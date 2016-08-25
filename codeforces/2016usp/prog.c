#include <stdio.h>

int main(){
	int i;
	float f;

	f = 0.0;

	for(i = 0; i < 10; i++)
		f += 0.1;

	printf("%f\n", f);
}