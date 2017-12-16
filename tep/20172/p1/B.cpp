#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int v[N];

int day[N];

int main(){
    int k, d, p, l, m;

    scanf("%d %d %d %d %d", &k, &d, &p, &l, &m);

    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", v+i);

    int e;

    scanf("%d", &e);

    for(int i = 0; i < e; i++){
        int a;
        char b;
        scanf("%d %c", &a, &b);

        day[a] = (b == 'B' ? 1 : -1);
    }

    int q = k;
    for(int t = 1; t <= n; t++){
        p += v[t];
        if(p > l) return printf("Demitido no dia %d\n", t), 0;
        p = max(0, p-q);
        if(p == 0) return printf("Promovido no dia %d\n", t+1), 0;
        if(day[t] == 1) q = min(m, q+k);
        if(day[t] == 0) q = max(0, q-d);
        if(day[t] ==-1) q = max(0, q-3*d);
    }

    printf("Tocando em frente\n");

    return 0;
}
