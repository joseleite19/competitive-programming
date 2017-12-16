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
#define d2(...) cerr << __VA_ARGS__ << endl
#define _ << " " <<

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 1005;

char s[N];
int n;

int dp[N][100][2];
int mark[N][100][2], pass;

inline int tou(char c){ return 'z' - c + 1; }
inline int tod(char c){ return c - 'a'; }

int f(int i, int u, int l){
    if(i == n) return 0;

    int &ans = dp[i][u][l];
    if(mark[i][u][l] == pass) return ans;
    mark[i][u][l] = pass;

    char c = s[i];

    if(l == 0){ // anterior virou pro u
        ans = max(0, tou(c) - u) + f(i+1, tou(c), 0);
        ans = min(ans, tod(c) + f(i+1, tod(c), 1));
        ans = min(ans, 26+max(0, tou(c) - u) + f(i+1, 26+tou(c), 0));
        ans = min(ans, 26+tod(c) + f(i+1, 26+tod(c), 1));
    }
    else{ // anterior virou pro d
        ans = max(0, tod(c) - u) + f(i+1, tod(c), 1);
        ans = min(ans, tou(c) + f(i+1, tou(c), 0));
        ans = min(ans, 26+max(0, tod(c) - u) + f(i+1, 26+tod(c), 1));
        ans = min(ans, 26+tou(c) + f(i+1, 26+tou(c), 0));
    }
    
    return ans;
}

int main(){

    //d2(tou('e'+15));
    for(pass = 1; scanf(" %s", s) == 1 && s[0] != '*'; pass++){
        n = strlen(s);
/*
        forn(i, n) printf("%d %d\n", tou(s[i]), tod(s[i]));

        f(0, 0, 0);

        int u = 0, l = 0;

        for(int i = 0; i < n; i++){
            char c = s[i];
            if(l == 0){
                if(f(i, u, l) == max(0, tou(c) - u) + f(i+1, tou(c), 0)){
                    printf("%d - pegou u\n", i);
                    u = tou(c);
                    l = 0;
                }
                else{
                    printf("%d - pegou d\n", i);
                    u = tod(c);
                    l = 1; 
                }
            }
            else{
                if(f(i, u, l) == max(0, tod(c) - u) + f(i+1, tod(c), 1)){
                    printf("%d - pegou d\n", i);
                    u = tod(c), l = 1;
                }
                else{
                    printf("%d - pegou u\n", i);
                    u = tou(c), l = 1;
                
                }
            }
        }
*/
        printf("%d\n", f(0, 0, 0));
    }

    return 0;
}
