#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define debug(x) cout << #x << " = " << x << endl
#define ford(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2000006;

int b, n, R[N];

tuple<int, int, int, int> v[N];

vector<int> w[N];

int main(){

	scanf("%d %d", &b, &n);

	forn(i, n) scanf("%d", R+i);
	forn(i, n){
		w[ ((R[i] % b) + b)%b ].pb(R[i]);
	}

	int Q;
	scanf("%d", &Q);

	int ans = 1;
	forn(i, Q){
		int a;
		scanf("%d", &a);
		
		int x = ((a % b) + b) % b;
		if(w[x].size() != 1) ans = 0;
		if(w[x].empty()){ // impossivel
			v[i] = mt(0, 0, 0, -1);
		}
		else{
			int r = w[x][0];
			int q = (a - r) / b;
			v[i] = mt(a, r, q, int(w[x].size()));
		}
	}

	printf("%s\n", ans ? "Sim" : "Nao");

	forn(i, Q){
		printf("Q %d: ", i+1);
		int a, r, q, p;
		tie(a, r, q, p) = v[i];
		if(p < 0) printf("impossivel\n");
		else printf("%d %d %d %d\n", a, b, q, r);
	}


    return 0;
}
