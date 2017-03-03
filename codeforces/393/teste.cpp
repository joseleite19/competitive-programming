#include <bits/stdc++.h>

int main(){


	long long m = 48324459;

	long long x = 9832;

	int cnt = 0;
	while(m >= (x + cnt)){
		m -= (x+cnt);
		// x++;
		cnt++;
	}
	printf("%d\n", cnt);



	return 0;
}