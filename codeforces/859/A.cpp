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
    int n;
    int x, mx = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        mx = max(mx, x);
    }

    printf("%d\n", max(0, mx - 25));



    return 0;
}
