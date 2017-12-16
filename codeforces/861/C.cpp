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
#define fore(i, n) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 3005;

int n;
char s[N];

int b(int i){
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') return 0;
    return s[i] - 'a';
}

int dp[N][5][30][30];

int f(int i, int sz, int l, int pl){
    if(i == n) return 0;

    int &ans = dp[i][sz][l][pl];

    if(~ans) return ans;

    ans = f(i+1, 1, b(i), 0)+1;
    int can = 1;
    if(l && pl){
        if((!l || b(i) != l) && (!pl || b(i) != pl))
            can = 0;
    }
    if(sz >= 2){
        if(pl) can = 0;
        else if(b(i) != l) can = 0;
    }

    if(!b(i)){
        ans = min(ans, f(i+1, 0, 0, 0));
    }
    else if(can){
        if(!l || b(i) == l) ans = min(ans, f(i+1, min(2, sz+1), b(i), 0));
        else if(!pl || b(i) == pl) ans = min(ans, f(i+1, min(2, sz+1), l, b(i)));
    }

    return ans;    
}

int main(){

    memset(dp, -1, sizeof dp);

    scanf("%s", s);
    n = strlen(s);

    int sz = 0, l = 0, p = 0;

    for(int i = 0; i < n; i++){
        if(f(i, sz, l, p) == f(i+1, 1, b(i), 0)+1){
            printf(" ");
            sz = 1;
            l = b(i);
            p = 0;
        }
        else{
            if(!b(i)){
                sz = 0;
                l = p = 0;
            }
            else{
                if(!l || b(i) == l){
                    sz = min(2, sz+1);
                    l = b(i), p = 0;
                }
                else{
                    sz = min(2, sz+1);
                    p = b(i);
                }
            }
        }
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
