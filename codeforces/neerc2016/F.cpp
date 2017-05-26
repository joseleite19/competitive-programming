#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
}

int lg(int x){
	int ret = 31 - __builtin_clz(x);
	if(x & (x - 1)) ret++;

	return ret;
}

int doit(int a, int b){
	int ret = 0;
	while(a > b){
		a = (a + 1) / 2;
		ret++;
	}
	if(!ret && a != b) return -100000000;
	return ret;
}

int main(){
	// file();
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(a < b) swap(a, b);
	if(c < d) swap(c, d);

	if(a < c || b < d) return printf("-1\n"), 0;

	// printf("%d\n", lg((a + c - 1) / c) + lg((b + d - 1) / d));
	int ans1 = doit(a, c) + doit(b, d);
	int ans2 = doit(a, d) + doit(b, c);

	
	
	return 0;
}