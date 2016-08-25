#include <bits/stdc++.h>

#define oo 100000000
#define ff first
#define ss second

using namespace std;

int capital[100005];
bool special[100005];
int c[100005];
long long sum2[100005];

int main(){
	int n, k, x;

	scanf("%d %d", &n, &k);

	long long sum = 0;

	for(int i = 0; i < n; i++){
		scanf("%d", c+i);
		sum += c[i];
	}

	for(int i = 0; i < k; i++){
		scanf("%d", capital+i); capital[i]--;
		special[ capital[i] ] = true;;
	}

	sum2[0] = c[ capital[0] ];
	for(int i = 1; i < k; i++)
		sum2[i] = sum2[i-1] + c[ capital[i] ];

	long long ans = 0;

	for(int i = 0; i < n; i++){
		ans += (c[i] * c[(i+1)%n]);
	}

	for(int i = 0; i < k; i++){
		long long tmp = sum - sum2[i];

		if(special[ (capital[i]-1+n)%n ] == false) tmp -= c[ (capital[i]-1+n)%n ];
		tmp -= c[ (capital[i]+1+n)%n ];

		ans += tmp*c[ capital[i] ];
	}
	printf("%lld\n", ans);


	return 0;
}