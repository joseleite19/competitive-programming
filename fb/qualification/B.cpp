#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int t, n, v[200];

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
			scanf("%d", v+i);
		sort(v, v+n);

		int cnt = 0;
		int l = 0, r = n-1;
		while(l <= r){
			int tmp = v[r];
			while(tmp < 50){
				tmp += v[r];
				l++;
			}
			if(l <= r) cnt++;
			r--;
		}
		printf("Case #%d: %d\n", tc, cnt);
	}
	
	return 0;
}