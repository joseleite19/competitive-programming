#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

pair<int, pair<int, int> > v[300005];
int n, k, apagado[300005];
int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &v[i].ff, &v[i].ss.ff);
		v[i].ss.ss = i;
	}

	sort(v, v+n);

	priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pr;
	
	for(int i = 0; i < k-1; i++)
		pr.push(mp(v[i].ss.ff, v[i].ss.ss));

	int ansr, ansl, ans = -1;
	for(int i = k-1; i < n; i++){
		int l = v[i].ff, r = v[i].ss.ff;
		if(!pr.empty() && pr.top().ff < r) r = pr.top().ff;

		int tmp = r - l + 1;
		if(tmp > ans){
			ans = tmp;
			ansr = r;
			ansl = l;
		}

		pr.push(mp(v[i].ss.ff, v[i].ss.ss));
		pr.pop();
	}

	if(ans == -1){
		printf("0\n");
		for(int i = 1; i <= k; i++)
			printf("%d ", i);
		printf("\n");

		return 0;
	}

	printf("%d\n", ans);

	int cnt = k;
	for(int i = 0; i < n && cnt; i++){
		if(v[i].ff <= ansl && v[i].ss.ff >= ansr){
			printf("%d ", v[i].ss.ss+1);
			cnt--;
		}
	}
	printf("\n");




	return 0;
}