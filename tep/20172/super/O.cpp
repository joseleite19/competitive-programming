#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
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
const int N = 1005;

int k, n;

double dp[N][22];
int mark[N][22], pass;

double f(int i, int l){
    if(i == n) return 1;
    double &ans = dp[i][l];
    
    if(mark[i][l] == pass) return ans;
    mark[i][l] = pass;
    ans = 0;
    if(l) ans += f(i+1, l-1);
    ans += f(i+1, l);
    if(l < k) ans += f(i+1, l+1);
    ans /= k+1;
    return ans;
}


int main(){

    while(scanf("%d %d", &k, &n) == 2){
        pass++;
        double ans = 0;
        forn(i, k+1) ans += f(1, i);
        ans /= k+1;
        printf("%.5lf\n", 100*ans);
    }


    return 0;
}
