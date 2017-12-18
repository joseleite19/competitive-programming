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

const int N = 100005;

int n, k, w;
pair<int, int> v[N];

int main(){

	scanf("%d %d %d", &k, &w, &n);

	forn(i, n) scanf("%d", &v[i].ff);
	forn(i, n) scanf("%d", &v[i].ss);

	sort(v, v+n);

	priority_queue<int> q;
	int j = 0;

	while(k--){
		while(j < n && v[j].ff <= w) q.push(v[j++].ss);
		if(q.empty()) break;
		w += q.top(); q.pop();
	}
	printf("%d\n", w);



    return 0;
}
