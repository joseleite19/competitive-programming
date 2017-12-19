#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 1000005;

void file(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
}

int n, v[N], in[N];


int main(){
	file();

	scanf("%d", &n);

	fore(i, 1, n+1) scanf("%d", v+i), in[ v[i] ]++;

	int ans = n;

	queue<int> q;
	fore(i, 1, n+1) if(!in[i])
		q.push(i);

	while(!q.empty()){
		ans--;
		int u = q.front(); q.pop();
		in[ v[u] ]--;
		if(!in[ v[u] ]) q.push(v[u]);
	}

	printf("%d\n", ans);





    return 0;
}
