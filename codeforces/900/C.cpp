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

int n, v[N];

int cnt[N], good[N];

int main(){

	scanf("%d", &n);

	forn(i, n) scanf("%d", v+i);

	set<int> s;

	forn(i, n){
		set<int>::iterator it = s.upper_bound(v[i]);
		if(it != s.end()){
			int x = *it;
			it++;
			if(it == s.end()){
				cnt[x]++;
				//cnt[ v[i] ]++;
			}
		}
		else good[ v[i] ] = 1;
		s.insert(v[i]);
	}

	int ans = 1;

	for(int i = 1; i <= n; i++){
		if(cnt[i] - good[i] > cnt[ans] - good[ans]) ans = i;
	}

	printf("%d\n", ans);

    return 0;
}
