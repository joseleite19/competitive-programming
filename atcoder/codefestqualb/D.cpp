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
const int N = 500005;

char s[N];
int n;

int main(){

    scanf("%d %s", &n, s);

    int ans = 0;
    int one = 0;
    forn(i, n-1){
        printf("%d %d %d: %s\n", i, one, ans, s);
        if(s[i] == '1') one++;
        else{
            if(s[i+1] == '0') one = 0;
            else{
                if(one){
                    ans += one;
                    s[i+1] = '0';
                    if(one != 1) one = 0;
                }
            }
        }
    }

    printf("%d\n", ans);


    return 0;
}
