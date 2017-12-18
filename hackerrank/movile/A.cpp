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

int main(){

	int t;

	scanf("%d", &t);

	while(t--){
		int d;
		scanf("%d %d", &d, &n);

		forn(i, n) scanf("%d", v+i);

		map<int, int> m;
		forn(i, n){
			if(m.count(d - v[i])){
				printf("%d %d\n", m[d-v[i]]+1, i+1);
				break;
			}
			m[ v[i] ] = i;
		}
	}



    return 0;
}
