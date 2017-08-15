#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;

	scanf("%d", &n);

	vector <long long> v; 

	for(int i = 0; i < n; i++){
		long long val;
		scanf("%lld", &val);
		v.push_back(val);
	}

	sort(v.begin(),v.end());

	long long maior = 1e13;

	for(int i = 0; i < n/2; i++){
		maior = min(maior,v[i]+v[n-i-1]);
	}

	printf("%lld\n",maior );

	return 0;
}