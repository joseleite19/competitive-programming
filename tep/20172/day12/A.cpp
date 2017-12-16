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

const int N = 3005;

int len[N], nx[N];

int prox(int x){
	int ans = 0, t;
	for(int i = 1; i * i <= x; i++) if(x % i == 0){
		t = i;
		while(t) ans += t % 10, t /= 10;
		if(x / i != i){
			t = x / i;
			while(t) ans += t % 10, t /= 10;
		}
	}
	return ans;
}

int f(int x){
	if(len[x]) return len[x];
	len[x] = 1;
	return len[x] = 1 + f(nx[x]);
}

int vis[N], pass;

void print(int x){
	if(vis[x] == pass) return;
	printf(" %d", x);
	vis[x] = pass;
	print(nx[x]);
}

int main(){

	fore(i, 1, N) nx[i] = prox(i);
	fore(i, 1, N) f(i);

	int n, m;

	for(int tc = 1; scanf("%d %d", &n, &m) == 2; tc++){
		pass++;
		int id = min(n, m);
		fore(i, min(n, m), max(n, m)+1) if(len[i] > len[id])
			id = i;
		printf("Input%d: %d %d\n", tc, n, m);
		printf("Output%d:", tc); print(id);
		printf("\n");
	}


    return 0;
}
