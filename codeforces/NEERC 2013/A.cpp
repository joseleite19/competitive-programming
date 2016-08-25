#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {
	FILE *fin = fopen("ascii.in", "r");
	FILE * fout = fopen("ascii.out", "w");

	int k, w, h;
	int W, H;
	int n;
	char **mat;
	int i, j;

	fscanf(fin, "%d %d %d", &k, &w, &h);

	n = sqrt(k);
	H = h * n;
	W = w * n;

	mat = malloc(sizeof(char) * H * W);

	printf("%d %d\n", W, H);
	if (k == 1) {
		for (i = 1; i <= 3 * w - 2; i++) {
			for (j = 1; j <= 3 * h - 2; j++) {
				char a;
				scanf(" %c", &a);
				if (i > w - 1 && i < 2 * w) {
					if (j > h - 1 && j < 2 * h) {
						printf("%c", a);
					}
				}
			}
			if (i > w - 1 && i < 2 * w) {
					printf("\n");
				}
		}
	} else if (k == 4) {

	} else if (k == 9) {

	} else if (k == 16) {
		
	}


	return 0;
}