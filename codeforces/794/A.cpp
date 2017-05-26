#include <bits/stdc++.h>

using namespace std;

long long v[100000];

int main(){
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	sort(v, v+n);

	long long ans = 0;

	for(int i = 0; i < n; i++){
		if(v[i] > b && v[i] < c){
			ans++;
		}
	}

	printf("%lld\n", ans);



	return 0;
}