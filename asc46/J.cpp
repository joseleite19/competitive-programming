#include <bits/stdc++.h>

using namespace std;

void file(){
	freopen("jingles.in", "r", stdin);
	freopen("jingles.out", "w", stdout);
}

int better[1<<26];
int v[3000006], pt;

char s[100005];

int main(){
	file();

	int t;

	scanf("%d", &t);

	while(t--){
		pt = 0;

		scanf(" %s", s);
		int n = strlen(s);

		vector<int> oc[26];

		for(int i = 0; i < n; i++)
			oc[ s[i]-'a' ].push_back(i);
		for(int i = 0; i < 26; i++)
			oc[i].push_back(n);

		long long ans = 0;

		for(int i = 0; i < n; i++){
			int bit = 1 << (s[i]-'a');
			int j = i;
			while(j < n){
				v[pt++] = bit;
				int nx = n;
				for(int k = 0; k < 26; k++)
					if((bit & (1 << k)) == 0)
						nx = min(nx, *lower_bound(oc[k].begin(), oc[k].end(), j));
				j = nx;
				better[bit] = max(better[bit], j - i);
				if(j < n) bit = bit | (1 << (s[j]-'a'));
			}
		}

		int cnt = 0;
		for(int i = 0; i < pt; i++){
			if(better[ v[i] ]) ans += __builtin_popcount(v[i]) * better[ v[i] ], cnt++;
			better[ v[i] ] = 0;
		}
		printf("%d %lld\n", cnt, ans);
	}




	return 0;
}