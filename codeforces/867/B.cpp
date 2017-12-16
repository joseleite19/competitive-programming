#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 200005;

vector<int> v = {1, 2};

int dp[N][11];
int mark[N][11], pass;
int f(int x, int j){
    if(x == 0) return 1;
    if(j == v.size()) return 0;
    if(v[j] > x) return 0;
    if(mark[x][j] == pass) return dp[x][j];
    mark[x][j] = pass;
    return dp[x][j] = f(x, j+1) + f(x - v[j], j);
}

int main(){
pass++;

    int n;

    scanf("%d", &n);

    for(int i = 1; ; i++) if(f(i, 0) == n){       
        printf("%d 2\n1 2\n", i);
        break;
    }
}
