#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m, p[200005], ans[200005], back[200005];

map<int,int> special;
pair<int, int> s[200005];

map<int, vector<int> > volta;

int f(int x){
	return (x+1) / 2;
}

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", p+i);
		special[ p[i] ]++;
		volta[ p[i] ].push_back(i);
	}

	for(int i = 0; i < m; i ++){
		scanf("%d", &s[i].ff);
		s[i].ss = i;
	}

	sort(s, s+m);
	int resp = 0;
	for(int i = 0; i < m; i++){
		int tmp = s[i].ff;
		int last = -1;
		int cnt = 0;
		while(tmp != last){
			if(special[tmp]){
				special[tmp]--;
				resp++;
				ans[ s[i].ss ] = cnt;
				int q = volta[tmp][ volta[tmp].size()-1 ];
				volta[tmp].pop_back();
				back[ q ] = s[i].ss +1;
				break;
			}
			last = tmp;
			tmp = f(tmp);
			cnt++;
		}
	}

	long long sum = 0;
	for(int i = 0; i < m; i++)
		sum += ans[i];

	printf("%d %lld\n", resp, sum);

	for(int i = 0; i < m; ++i){
		printf("%d ", ans[i]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", back[i]);
	}
	printf("\n");	

	return 0;
}