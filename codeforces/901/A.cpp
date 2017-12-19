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

const int N = 200005;

int n, v[N];

int p1[N], p2[N];

int main(){

	scanf("%d", &n);
	n++;

	forn(i, n) scanf("%d", v+i);

	bool ans = 0;
	int last = 0;
	int id = 1;

	forn(i, n){
		int t = id;
		if(id - last > 1 && v[i] > 1){
			ans = 1;
			p1[id] = last, p2[id] = last+1;
			id++, v[i]--;
		}
		forn(j, v[i]){
			p1[id] = p2[id] = last;
			id++;
		}
		last = t;
	}

	if(!ans) printf("perfect\n");
	else{
		printf("ambiguous\n");
		fore(i, 1, id) printf("%d ", p1[i]); printf("\n");
		fore(i, 1, id) printf("%d ", p2[i]); printf("\n");
	}


    return 0;
}
