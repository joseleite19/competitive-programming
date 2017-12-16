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
const int N = 100005;


int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    int ans = 0;
    while(1){
        if(n > m){
            if(n >= 2 && m >= 1) n -= 2, m -= 1, ans++;
            else break;
        }
        else{
            if(n >= 1 && m >= 2) n -= 1, m -= 2, ans++;
            else break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
