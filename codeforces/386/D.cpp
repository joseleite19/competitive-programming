#include <bits/stdc++.h>

using namespace std;

char s[100005];

int n, k, a, b;

int check(int a, int b){
	int ka, kb;
	ka = a/k;
}

int main(){

	scanf("%d %d %d %d", &n, &k, &a, &b);
	char c, d;
	c = 'G', d = 'B';

	if(a > b){
		swap(a, b);
		swap(c, d);
	}

	int ptr = 0;
	int tmp = (b % k) != 0;
	tmp += b/k;
	if((long long)(a+1)*k < b){
		printf("NO\n");
		return 0;
	}

	for(int i = 0; i < n; i++){
		tmp = b/(a+1) + ((b % (a+1)) != 0);
		int tmp1 = min(tmp, min(k, b));
		for(; i < n && tmp1; i++){
			s[ptr++] = d;
			b--;
			tmp1--;
		}
		s[ptr++] = c;
		a--;
	}

	s[n] = 0;

	printf("%s\n", s);

	return 0;
}