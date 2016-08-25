#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x, d, t, q, c;

	d = t = q = c = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(x % 2 == 0) d++;
		if(x % 3 == 0) t++;
		if(x % 4 == 0) q++;
		if(x % 5 == 0) c++;
	}
	printf("%d Multiplo(s) de 2\n", d);
	printf("%d Multiplo(s) de 3\n", t);
	printf("%d Multiplo(s) de 4\n", q);
	printf("%d Multiplo(s) de 5\n", c);

	return 0;
}