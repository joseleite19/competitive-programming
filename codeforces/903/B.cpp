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
	int h1, a1, c1, h2, a2;

	scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);

	vector<int> ans;

	while(1){
		if(h2 - a1 > 0){
			if(h1 - a2 <= 0){
				ans.pb(1);
				h1 += c1;
			}
			else ans.pb(2), h2 -= a1;
		}
		else{ ans.pb(2); break; }
		h1 -= a2;
	}

	printf("%d\n", int(ans.size()));

	for(int x : ans)
		printf("%s\n", x == 1 ? "HEAL" : "STRIKE");


    return 0;
}
