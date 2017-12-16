#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

pair<char, int> v[200105];
int nxt[200105];

int qwe[200105];

int main(){
	file();
	int n;

	scanf("%d", &n);

	for(int i = 2; i <= n; i++)
		scanf(" %c %d", &v[i].ff, &v[i].ss);

	int mx = 1000000000;
	int pr = n;
	int cnt = 0;
	for(int i = n-1; i >= 2; i--){
		if(v[i].ff == 'd') continue;
		// printf("## %d %d\n", i, v[i].ss);

		v[i].ss = min(v[i].ss, mx);
		mx = v[i].ss;
		nxt[i] = pr;
		pr = i;
		cnt = v[i].ss-1;
	}
	// printf("%d\n", mx);
	if(pr == n) cnt = 1000000000;

	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;

	// printf("..%d\n", cnt);
	for(int i = 2; i <= n; i++){
		if(v[i].ff == 'd'){
			if(pq.size() < cnt){
				pq.push(mp(v[i].ss, i));
			}
			else if(cnt != 0){
				if(pq.empty() || pq.top().ff < v[i].ss){
					if(!pq.empty()) pq.pop();
					pq.push(mp(v[i].ss, i));
				}
			}
		}
		else{
			if(nxt[i] == n) cnt = 1000000000;
			else cnt = v[ nxt[i] ].ss-1;
		}
	}

	long long ans = 0;
	long long ans1 = pq.size();

	if(pq.size() < v[n].ss){
		printf("-1\n");
		return 0;
	}

	while(!pq.empty()){
		ans += pq.top().ff;
		qwe[ pq.top().ss ] = 1;
		pq.pop();
	}

	printf("%lld\n%lld\n", ans, ans1);

	for(int i = 0; i <= n; i++){
		if(qwe[i])
			printf(" %d", i);
	}
	printf("\n");



	return 0;
}