#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n, m, k;
int f[1000006];
int s[1000006];
int indexes[1000006];

int v[2000006];

bool F(int x){

	int i = 0;
	int j = x;

	int K = 0;

	while(i < n && j < m){
		if(f[i] < s[j]) v[K++] = f[i++];
		else v[K++] = s[j++];
	}

	while(i < n) v[K++] = f[i++];
	while(j < m) v[K++] = s[j++];

	int lastcnt = 0;
	int day = 0;

	for(int i = 0; i < K; i++){
		if(v[i] < day) return 0;
		lastcnt++;

		if(lastcnt == k){
			day++;
			lastcnt = 0;
		}
	}
	return 1;
}

int main(){
	
	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", f+i);

	sort(f, f+n);

	{
		pair<int, int> tmp[1000006];
		for(int i = 0; i < m; i++){
			scanf("%d", &tmp[i].ff);
			tmp[i].ss = i+1;
		}
		sort(tmp, tmp+m);

		for(int i = 0; i < m; i++)
			s[i] = tmp[i].ff, indexes[i] = tmp[i].ss;
	}

	if(!F(m)){
		printf("-1\n");
		return 0;
	}

	int hi = m, lo = 0;

	while(lo+1 < hi){
		int mid = (lo + hi)/2;
		if(F(mid)) hi = mid;
		else lo = mid+1;
	}

	if(!F(lo)) lo++;

	printf("%d\n", m - lo);
	for(int i = lo; i < m; i++)
		printf("%d ", indexes[i]);
	printf("\n");

	return 0;
}