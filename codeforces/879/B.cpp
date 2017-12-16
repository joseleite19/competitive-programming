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

int n, v[N];

int main(){

    ll k;

    scanf("%d %lld", &n, &k);

    forn(i, n) scanf("%d", v+i);

    if(k >= n){
        return printf("%d\n", n), 0;
    }

    queue<int> q;
    forn(i, n) q.push(v[i]);

    int row = 1, win;
    int a = q.front(); q.pop();
    int b = q.front(); q.pop();

    if(a > b) win = a, q.push(b);
    else win = b, q.push(a);

    while(row < k){
        int b = q.front(); q.pop();
        if(win > b){
            q.push(b);
            row++;
        }
        else{
            q.push(win);
            win = b;
            row = 1;
        }
    }

    printf("%d\n", win);


    return 0;
}
