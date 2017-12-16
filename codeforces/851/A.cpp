#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int main(){
    int n, k, t;

    scanf("%d %d %d", &n, &k, &t);

    if(t <= k) printf("%d\n", t);
    else{
        if(t <= n) printf("%d\n", k);
        else printf("%d\n", n - (t-k));
    }


    return 0;
}
