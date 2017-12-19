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

const int N = 155;

int f[N][N];
int v[N];

int main(){

	f[0][0] = 1;

	f[1][1] = 1;

	fore(i, 2, N){
		forn(j, N-1) f[i][j+1] = f[i-1][j];
		forn(j, N){
			f[i][j] += f[i-2][j];
			if(f[i][j] > 1) f[i][j] = -1;
			if(f[i][j] <-1) f[i][j] = 1;
		}
		//forn(j, i+1) printf("%d ", f[i][j]);
		//printf("\n");
	}

	int n;
	scanf("%d", &n);

	printf("%d\n", n);
	forn(i, n+1) printf("%d ", f[n][i]); printf("\n");

	printf("%d\n", n-1);
	forn(i, n) printf("%d ", f[n-1][i]); printf("\n");


    return 0;
}
