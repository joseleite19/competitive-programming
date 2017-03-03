#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("pulp.in", "r", stdin);
	freopen("pulp.out", "w", stdout);
}

long long dp[100005];
bool mark[100005];

int main(){
	int n;

	pair<int, int> v[100005];

	long long tot = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d %d", &v[i].ff, &v[i].ss);

	sort(v, v+n);

	long long t = 0;

	multiset<int> q; // qnt falta

	long long delta = 0;
	long long dia = 0;
	for(int i = 0; i < n; i++){
		if(!q.empty()){
			while(!q.empty() && *q.begin() <= delta){
				t += v[i].ff + (*q.begin() - delta);
				delta -= *q.begin();
				q.erase(q.begin());
			}
			if(!q.empty() && delta > 0){
				long long a = *q.begin();
				q.erase(q.begin());
				a -= delta;
				q.insert(a);
			}
		}

		q.insert(v[i].ss);

		// if(!q.empty() && v[i].ff + v[i].ss < *q.begin()){

		// 	long long tmp = *q.begin();
		// 	q.erase(q.begin());

		// 	q.insert(v[i].ff + v[i].ss);
		// 	tmp += v[i].ss;
		// 	q.insert(tmp);
		// }
		// else{
		// 	if(!q.empty()) q.insert(*q.rbegin() + v[i].ss);
		// 	else q.insert(v[i].ff + v[i].ss);

		// }
		delta = v[i+1].ff - v[i].ff;
	}

	dia = v[n-1].ff;
	while(!q.empty()){
		t += *q.begin() + dia;
		dia += *q.begin();
		q.erase(q.begin());
	}

	printf("%lld\n", t);


	return 0;
}