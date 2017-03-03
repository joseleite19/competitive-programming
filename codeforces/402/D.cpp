#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

char p[200005], t[200005];

int a[200005], can[200005], n, m;

bool f(int mid){
	for(int i = 0; i <= mid; i++)
		can[ a[i]-1 ] = 1;

	int ptr = 0;
	bool ret = 0;

	for(int i = 0; i < n; i++){
		if(can[i]) continue;
		
		if(t[i] == p[ptr]) ptr++;
		if(ptr == m){
			ret = 1;
			break;
		}
	}

	for(int i = 0; i <= mid; i++)
		can[ a[i]-1 ] = 0;

	return ret;
}

int main(){

	scanf(" %s %s", t, p);

	n = strlen(t);
	m = strlen(p);

	for(int i = 0; i < n; i++)
		scanf("%d", a+i);

	int hi = n-1, lo = 0;

	while(lo + 1 < hi){
		int mid = (lo + hi) / 2;

		if(f(mid)) lo = mid;
		else hi = mid-1;
	}

	while(hi >= 0 && !f(hi)) hi--;

	printf("%d\n", hi+1);
	
	return 0;
}