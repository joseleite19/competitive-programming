#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

const int N = 1000006;

int vis[N];

int d(int x){
    int ans = x;
    while(x) ans += (x % 10), x /= 10;
    return ans;
}

int main(){

    for(int i = 1; i < N; i++){
        if(d(i) < N)
            vis[d(i)] = 1;
    }

    for(int i = 1; i <= 1000000; i++) if(!vis[i])
        printf("%d\n", i);

    return 0;
}
