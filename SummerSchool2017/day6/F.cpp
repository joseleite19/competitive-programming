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

priority_queue<int> v[4004];

vector<pair<int, int> > tmp;


// int v[4004];
int main(){
	file();
	int n, k;

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		int m, c;
		scanf("%d %d", &m, &c);
		v[m].push(c);
		// if(v[m].size() > k) v[m].pop();
	}

	if(k > n){
		printf("0 0\n");
		return 0;
	}


	for(int i = 0; i < 4004; i++){
		if(v[i].empty()) continue;
		tmp.push_back(mp(v[i].size(), i));
	}

	if(k > tmp.size()){
		printf("0 0\n");
		return 0;
	}

	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());

	int cnt = 1000000000;
	for(int i = 0; i < k; i++){
	//	// if(tmp[i].ff < k) break;
	//	v[tmp[i].ff] = v[tmp[i-1].ff] + 1;
	//	if(v[tmp[i].ff] >= tmp[i].ff && tmp[i].ff <= k) break;
		cnt = min(cnt, tmp[i].ff);
	}


	vector<long long> tmp2;
	for(int i = 0; i < 4004; i++){
		if(v[i].size() < cnt) continue;

		long long qwe = 0;

		for(int j = 0; j < cnt; j++){
			qwe += v[i].top();
			v[i].pop();
		}
		tmp2.push_back(qwe);
	}

	sort(tmp2.begin(), tmp2.end());
	reverse(tmp2.begin(), tmp2.end());

	long long ans = 0;

	for(int i = 0; i < k; i++)
		ans += tmp2[i];

	printf("%d %lld\n", cnt, ans);

	return 0;
}