#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int p[100005];
long long cnt[100005];
long long sz[100005];

vector<int> g[100005];

int n, m, qq;

long long d[100005];
long long dx[100005];

map<pair<int, int>, double> table;

int vis1[100005];
int vis2[100005];
int vis3[100005];
int vis4[100005];

vector<int> c[100005];
vector<int> sum[100005];

int f(int x){
	return x == p[x] ? x : p[x] = f(p[x]);
}

int main(){

	scanf("%d %d %d", &n, &m, &qq);

	for(int i = 1; i <= n; i++) p[i] = i;

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
		p[f(u)] = f(v);
	}

	for(int i = 1; i <= n; i++){
		if(vis1[i]) continue;

		int big1 = 1, mx = -1;
		{
			queue<int> q;
			q.push(i);
			d[i] = 0;
			vis1[i] = 1;

			while(!q.empty()){
				int u = q.front(); q.pop();
				if(d[u] > mx) mx = d[u], big1 = u;

				for(int v : g[u]){
					if(vis1[v]) continue;
					vis1[v] = 1;
					d[v] = d[u]+1;
					q.push(v);
				}
			}
		}

		int big2 = 1;
		mx = -1;

		{
			queue<int> q;
			q.push(big1);
			d[big1] = 0;
			vis2[big1] = 1;

			while(!q.empty()){
				int u = q.front(); q.pop();
				if(d[u] > mx) mx = d[u], big2 = u;
				dx[u] = d[u];

				for(int v : g[u]){
					if(vis2[v]) continue;
					vis2[v] = 1;
					d[v] = d[u]+1;
					q.push(v);
				}
			}
		}

		{
			queue<int> q;
			q.push(big2);
			d[big2] = 0;
			vis3[big2] = 1;

			while(!q.empty()){
				int u = q.front(); q.pop();
				dx[u] = max(dx[u], d[u]);
                c[f(u)].push_back(dx[u]);
				cnt[f(u)] += dx[u];
				sz[f(u)]++;

				for(int v : g[u]){
					if(vis3[v]) continue;
					vis3[v] = 1;
					d[v] = d[u]+1;
					q.push(v);
				}
			}
		}
        sort(c[f(i)].begin(), c[f(i)].end());
        sum[f(i)].push_back(0);
        for(int d : c[f(i)])
            sum[f(i)].push_back(sum[f(i)].back() + d);
	}

	while(qq--){
		scanf("%d %d", &u, &v);
        u = f(u), v = f(v);
        if(sz[u] > sz[v]) swap(u, v);
		if(u == v) printf("-1\n");
		else{
            if(table.count(mp(u, v))){
                printf("%.20lf\n", table[mp(u, v)]);
                continue;
            }

            long long num = 0, den;

            long long mx = max(c[v].back(), c[u].back());
            for(int d : c[u]){
                int id = lower_bound(c[v].begin(), c[v].end(), mx - (d+1)) - c[v].begin();
                num += sum[v].back() - sum[v][id] + (sz[v] - id)*(d+1) + id*mx;
            }

			den = sz[u] * sz[v];

			printf("%.20lf\n", double(num) / den);
            table[mp(u, v)] = double(num) / den;
		}
	}


	return 0;
}
