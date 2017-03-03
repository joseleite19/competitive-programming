#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

pair<int, int> v[300005];
int n, k;

struct bit{
	vector<int> ft;
	int n;
	void add(int x, int v){
		for(; x <= n; x += x&-x)
			ft[x] += v;
	}

	int sum(int x){
		int ans = 0;
		for(; x; x -= x&-x)
			ans += ft[x];
		return ans;
	}
	bit(int size): n(size), ft(size+1, 0){}
};

map<int, int> vai, volta;

vector<int> tmp;

vector< vector<int> > vv;
int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &v[i].ff, &v[i].ss);
		tmp.push_back(v[i].ff);
		tmp.push_back(v[i].ss);
	}

	sort(tmp.begin(), tmp.end());
	int ptr = 1;

	for(int i = 0; i < (int)tmp.size(); i++){
		if(vai.count(tmp[i])) continue;
		vai[ tmp[i] ] = ptr;
		volta[ ptr ] = tmp[i];
		ptr++;
	}

	vv.assign(ptr+1, vector<int> ());
	for(int i = 0; i < n; i++){
		vv[ vai[ v[i].ff ] ].push_back(vai[ v[i].ss ]);
	}

	bit b(ptr+100);

	vector<pair<int, int> > ans;
	for(int i = 1; i < ptr; i++){
		for(int j = 0; j < (int)vv[i].size(); j++){
			b.add(i, 1);
			b.add(vv[i][j]+1, -1);
		}

		if(b.sum(i) < k) continue;
		int hi = ptr-1, lo = i;

		while(lo + 1 < hi){
			int mid = (lo + hi) / 2;
			if(b.sum(mid) < k) hi = mid-1;
			else lo = mid;
		}
		if(b.sum(hi) < k) hi--;
		ans.push_back(mp(i, hi));
	}

	if(!ans.size()){
		printf("0\n");
		for(int i = 1; i <= k; i++)
			printf("%d ", i);
		printf("\n");

		return 0;
	}

	int id = 0;

	for(int i = 1; i < (int)ans.size(); i++){
		if(volta[ ans[i].ss ] - volta[ ans[i].ff ] + 1 >
			volta[ ans[id].ss ] - volta[ ans[id].ff ] + 1)
			id = i;
	}

	printf("%d\n", volta[ ans[id].ss ] - volta[ ans[id].ff ] + 1);

	int l = volta[ ans[id].ff ], r = volta[ ans[id].ss ];

	int cnt = k;
	for(int i = 0; i < n && cnt; i++){
		if(v[i].ff <= l && v[i].ss >= r){
			printf("%d ", i+1);
			cnt--;
		}
	}
	printf("\n");
	
	return 0;
}