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

double dp[N][N][2];
int mark[N][N][2];

double f(int w, int b, int q){
    if(!w) return 0;
    if(!b) return q == 0;
    double &ans = dp[w][b][q];
    if(mark[w][b][q]) return ans;
    mark[w][b][q] = 1;
    ans = 0;

    if(q == 0){
        ans = 1.0 * w / (w + b) + 1.0 * b / (w + b) * f(w, b-1, 1);
    }
    else{
        double t = 1.0 * w / (w + b - 1) * f(w - 1, b - 1, 0);
        if(b > 1) t += 1.0 * (b-1) / (w + b - 1) * f(w, b-2, 0);
        t *= 1.0 * b / (w + b);
        ans = t;
    }

    return ans;
}

int main(){
    int w, b;

    scanf("%d %d", &w, &b);

    printf("%.20lf\n", f(w, b, 0));



    return 0;
}
