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

    int n, x;

    scanf("%d", &n);

    multiset<int> a, b;

    forn(i, n){
        scanf("%d", &x);
        a.insert(x);
    }

    forn(i, n-1){
        scanf("%d", &x);
        b.insert(x);
        a.erase(a.find(x));
    }

    printf("%d\n", *a.begin());

    a.clear();
    swap(a, b);

    forn(i, n-2){
        scanf("%d", &x);
        b.insert(x);
        a.erase(a.find(x));
    }

    printf("%d\n", *a.begin());
    

    return 0;
}
