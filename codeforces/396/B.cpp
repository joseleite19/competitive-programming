#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int main(){
	int n;
	long long v[100005];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	sort(v, v+n);

	bool can = false;
	for(int i = 0; i < n-2; i++)
		if(v[i] + v[i+1] > v[i+2])
			can = true;


	if(!can) printf("NO\n");
	else printf("YES\n");



	return 0;
}