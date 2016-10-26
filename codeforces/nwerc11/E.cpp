#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long cnt[300];
long long cnt2[300];

int main(){
	long long t,n;
	char s[30000];

	scanf("%lld", &t);

	while(t--){
		scanf("%lld", &n);
		scanf(" %s", s);
		memset(cnt, 0, sizeof cnt);
		for(long long i = 0; s[i]; i++){
			cnt[s[i]]++;
		}
		memset(cnt2, 0, sizeof cnt2);
		long long normal = 0, espera = 0;
		for(long long i = 0; s[i]; i++){
			normal += espera*5;
			cnt2[s[i]]++;
			espera++;
			if(cnt2[s[i]] == cnt[s[i]]) espera -= cnt[s[i]];
		}

		long long otim = 0;
		for(long long i = 0; i <= 255; i++){
			otim += 5*cnt[i]*(cnt[i]-1)/2;
		}
		printf("%lld\n", normal - otim);
	}

	return 0;
}