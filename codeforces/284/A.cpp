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

    int p;

    scanf("%d", &p);

    int ans = 0;

    for(int i = 0; i < p; i++){
        int tmp = 1;
        bool can = true;
        for(int j = 0; j+2 < p; j++){
            tmp = (tmp * i) % p;
            if((tmp - 1 + p) % p == 0)
                can = false;
        }
        tmp = (tmp * i) % p;
        if((tmp - 1 + p) % p == 0 && can)
            ans++;
    }

    printf("%d\n", ans);



    return 0;
}
