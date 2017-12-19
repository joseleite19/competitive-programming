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
	int n;
	scanf("%d", &n);

	vector<int> ans;

	int s = n % 4+1, j = n;

	while(s < j){
		ans.pb(s), ans.pb(j);
		s += 2, j -= 2;
	}

	int t = 0;
	if(n % 4 == 1){
		t = 1;
		ans.pb(1);
	}
	else if(n % 4 == 2){
		t = 1;
		ans.pb(1);
	}
	else if(n % 4 == 3){
		t = 0;
		ans.pb(1), ans.pb(2);
	}

	printf("%d\n", t);
	printf("%d", int(ans.size()));
	for(int x : ans) printf(" %d", x);
	printf("\n");



    return 0;
}
