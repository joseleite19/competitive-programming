#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d;

	int v[4];
	scanf("%d %d %d %d", &v[3], &v[2], &v[1], &v[0]);

	int e, f, g, h, i, j, k;

	e = v[0] | v[1];
	e = !e;

	f = v[2] ^ v[3];
	f = !f;

	g = v[1] & v[2];
	g = !g;

	h = v[0] | v[3];
	h = !h;

	i = e & f;
	i = !i;

	j = g ^ h;
	j = !j;

	k = i | j;
	k = !k;
	printf("%d\n", k);

	return 0;
}