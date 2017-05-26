#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

vector<pair<int, pair<long long, int> > > g[205]; // <vx, <edge weight, id reverse edge>>

int lvl[100005], vis[100005], source, target;

size_t px[100005];

long long run(int s, long long minE){
	if(s == target) return minE;

	long long ans = 0;

	for(; px[s] < g[s].size(); px[s]++){
		auto &v = g[s][ px[s] ];
		if(lvl[v.ff] != lvl[s]+1 || !v.ss.ff) continue;
		long long tmp = run(v.ff, min(minE, v.ss.ff));
		v.ss.ff -= tmp;
		g[v.ff][v.ss.ss].ss.ff += tmp;
		ans += tmp;
		minE -= tmp;
		if(minE == 0) break;
	}
	return ans;
}

int pass;
int bfs(){

	queue<int> q;
	q.push(source);
	lvl[source] = 1;
	vis[source] = ++pass;

	while(!q.empty()){
		int u = q.front(); q.pop();
		px[u] = 0;

		for(auto v : g[u]){
			if(v.ss.ff <= 0 || vis[v.ff] == pass) continue;
			vis[v.ff] = pass;
			lvl[v.ff] = lvl[u]+1;
			q.push(v.ff);
		}
	}

	return vis[target] == pass;
}

long long flow(){

	long long ans = 0;
	while(bfs())
		ans += run(source, oo);
	return ans;
}

void addEdge(int u, int v, long long c){
    // printf("{%d, %d}(%lld)\n", u, v, c);
	pair<int, pair<long long, int> > a, b;
	a = {u, {0, g[u].size()}};
	b = {v, {c, g[v].size()}};
	g[u].push_back(b);
	g[v].push_back(a);
}

int ptr = 1;

int n, k;
int p[200], c[200], l[200];

bool is_prime[200005];

void precalc(){
    bool tmp[200005] = {0};
    is_prime[2] = 1;
    for(long long i = 3; i < 200005; i += 2){
        if(!tmp[i]){
            is_prime[i] = 1;

            for(long long j = i*i; j < 200005; j += i)
                tmp[j] = 1;
        }
    }
}

bool f(int mid){

    map<int, bool> mo, me;
    int tot = 0;
    for(int i = 0; i < n; i++){
        if(l[i] > mid) continue;
        tot += p[i];
        for(int j = i+1; j < n; j++){
            if(l[j] > mid) continue;
            if(is_prime[c[i] + c[j]]){
                pair<int, pair<int, int> > odd = mp(i, mp(p[i], c[i]));
                pair<int, pair<int, int> >even = mp(j, mp(p[j], c[j]));
                if(even.ss.ss & 1) swap(odd, even);
                if(!mo[odd.ff]) addEdge(source, odd.ff, odd.ss.ff); // source -> odd (c[odd])
                if(!me[even.ff]) addEdge(even.ff,target,even.ss.ff); // even -> target (c[even])
                addEdge(odd.ff, even.ff, oo);    // odd -> eve (oo)
                mo[odd.ff] = me[even.ff] = 1;
                // printf("%d->%d (%d)\n", source, odd.ff, odd.ss);
                // printf("%d->%d (%d)\n", even.ff,target,even.ss);
                // printf("%d->%d (%d)\n", odd.ff, even.ff, oo);
            }
        }
    }

    int mf = tot - flow();

    for(int i = 0; i < 205; i++) g[i].clear();
    // printf("%d %d %d %d\n", mid, mf, k, tot); exit(0);
    return mf >= k;
}

int main(){
    precalc();
    target = 204, source = 203;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d %d %d", p+i, c+i, l+i);

    {
        int best_one =-1;
        for(int i = 0; i < n; i++){
            if(c[i] == 1){
                if(best_one == -1) best_one = i;
                else if(p[i] > p[best_one]) best_one = i;
            }
        }
        int j = 0;
        for(int i = 0; i < n; i++){
            if(c[i] != 1 || best_one == i){
                c[j] = c[i], p[j] = p[i], l[j] = l[i];
                j++;
            }
        }
        n = j;
    }

    int hi = 200, lo = 0;
    while(lo+1 < hi){
        int mid = (lo + hi) / 2;
        if(f(mid)) hi = mid;
        else lo = mid+1;
    }
    if(!f(lo)) lo++;

    if(!f(lo)) lo = -1;

	printf("%d\n", lo);

	return 0;
}
