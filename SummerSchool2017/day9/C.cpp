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

int p[100005];

int f(int x){
	return x == p[x] ? x : p[x] = f(p[x]);
}

map<int, int> muda;
pair<int, pair<int, pair<int, pair<int, int> > > > v[100005];

int main(){
	int n;

	int ptr = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d %d %d", &a, &b, &v[i].ff, &v[i].ss.ff);
		v[i].ss.ss.ff = i+1;
		if(!muda.count(a)) muda[a] = ptr++;
		if(!muda.count(b)) muda[b] = ptr++;
		a = muda[a];
		b = muda[b];
		v[i].ss.ss.ss.ff = a;
		v[i].ss.ss.ss.ss = b;
	}

	for(int i = 1; i <= 2*n; i++) p[i] = i;

	sort(v, v+n);

	long long ans = 0;
	for(int i = n-1; i >= 0; i--){
		int a = v[i].ss.ss.ss.ff;
		int b = v[i].ss.ss.ss.ss;
		if(f(a) != f(b)){
			p[f(a)] = f(b);
			ans += v[i].ss.ff;
		}
	}

	printf("%lld\n", ans);

	for(int i = 0; i < n; i++)
		printf("%d ", v[i].ss.ss.ff);
	printf("\n");


	return 0;
}