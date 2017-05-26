#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("java2016.in", "r", stdin);
	freopen("java2016.out", "w", stdout);
}

int main(){
	// file();

	printf("a = ? max ?\n");
	printf("b = a max a\n");
	printf("c = b max b\n");
	printf("d = c max c\n");
	printf("e = d max d\n");
	printf("f = e max e\n");
	printf("g = f max f\n");
	printf("h = g max g\n");
	printf("i = h max h\n");
	printf("j = i max i\n");
	printf("k = j max j\n"); //-2^0
	printf("l = k + k\n"); //-2^1
	printf("m = l + l\n"); //-2^2
	printf("n = m + m\n"); //-2^3
	printf("o = n + n\n"); //-2^4
	printf("p = o + o\n"); //-2^5
	printf("q = p + p\n"); //-2^6
	printf("r = q + q\n"); //-2^7

	int c;

	scanf("%d", &c);

	printf("(k - k) - (");

	int cnt = 1;

	if(c >= 128) printf("(r + "), c -= 128, cnt++;
	if(c >= 64) printf("(q + "), c -= 64, cnt++;
	if(c >= 32) printf("(p + "), c -= 32, cnt++;
	if(c >= 16) printf("(o + "), c -= 16, cnt++;
	if(c >= 8) printf("(n + "), c -= 8, cnt++;
	if(c >= 4) printf("(m + "), c -= 4, cnt++;
	if(c >= 2) printf("(l + "), c -= 2, cnt++;
	if(c >= 1) printf("(k + "), c -= 1, cnt++;
	printf("(k - k)");
	while(cnt--) printf(")");

	printf("\n");

	return 0;
}