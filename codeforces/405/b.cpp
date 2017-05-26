#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD (1000000007)
#define oo (1000000000000000000)

using namespace std;

int main(){
	int a, b;

	scanf("%d %d", &a, &b);

	int cnt = 0;

	while(a <= b){
		a *= 3;
		b *= 2;
		cnt++;
	}

	printf("%d\n", cnt);


	return 0;
}