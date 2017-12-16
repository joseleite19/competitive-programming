#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 1000006;

ll v[N];

int main(){

    v[1] = 1, v[2] = 3;
    int j = 2;
    ll inc = 3;

    for(int i = 3; i < N; i++){
        if(inc == v[j]) inc++, j++;
        v[i] = (v[i-1] + inc++) % MOD;
    }

    int t;

    scanf("%d", &t);

    char c;
    int x;
    while(t--){
        scanf(" %c %d", &c, &x);

        if(c == 'R') printf("%lld\n", v[x]);
        if(c == 'S') printf("%lld\n", (v[x+1] - v[x] + MOD) % MOD); 
    }

    return 0;
}
