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

int main(){
	int v[4];

	forn(i, 4) scanf("%d", v+i);

	sort(v, v+4);

	int ans = 0;
	do{
		if(v[0] + v[1] == v[2]) ans = max(ans, 1);
		if(v[0] + v[2] == v[1]) ans = max(ans, 1);
		if(v[2] + v[1] == v[0]) ans = max(ans, 1);
		if(v[0] < v[1] + v[2] && v[1] < v[0] + v[2] && v[2] < v[0]+v[1])
			ans = 2;
	}while(next_permutation(v, v+4));

	if(ans == 2) printf("TRIANGLE\n");
	else if(ans == 1) printf("SEGMENT\n");
	else printf("IMPOSSIBLE\n");


    return 0;
}
