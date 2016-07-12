#include <bits/stdc++.h>

int main(){
	int n, x, kids = 0, a;
	long long d;
	char c;

	scanf("%d %d", &n, &x);
	d = x;
	for(int i = 0; i < n; i++){
		scanf(" %c %d", &c, &a);
		if(c == '+') d += a;
		else{
			if(d >= a) d -= a;
			else kids++;
		}
	}
	printf("%lld %d\n", d, kids);
}
