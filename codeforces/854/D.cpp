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
const int N = 1000006;

vector<tuple<int, int, int>> f[N];

multiset<int> chega[N], sai[N];

ll ansa, ansb;

int qnta = 0, qntb = 0;
void adda(int x){
    for(auto q : f[x]) if(get<1>(q) == 0){
       int a, b, c;
       tie(a, b, c) = q;
       if(chega[a].empty()) qnta++;
       else ansa -= *chega[a].begin();
       chega[a].insert(c);
       ansa += *chega[a].begin();
    }
}

void addb(int x){
    for(auto q : f[x]) if(get<0>(q) == 0){
       int a, b, c;
       tie(a, b, c) = q;
       if(sai[b].empty()) qntb++;
       else ansb -= *sai[b].begin();
       sai[b].insert(c);
       ansb += *sai[b].begin();
    }
}

void rema(int x){
    for(auto q : f[x]) if(get<1>(q) == 0){
       int a, b, c;
       tie(a, b, c) = q;
       
       ansa -= *chega[a].begin();
       chega[a].erase(chega[a].find(c));
       
       if(chega[a].empty()) qnta--;
       else ansa += *chega[a].begin();
    }
}

void remb(int x){
    for(auto q : f[x]) if(get<0>(q) == 0){
       int a, b, c;
       tie(a, b, c) = q;
       
       ansb -= *sai[b].begin();
       sai[b].erase(sai[b].find(c));
       
       if(sai[b].empty()) qntb--;
       else ansb += *sai[b].begin();
    }
}

int main(){

    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < m; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        f[a].eb(b, c, d);
    }

    int La, Lb = 0, Ra = 0, Rb = -1;

    ll ans = oo;
    for(int i = 1; i < N; i++){
        while((Ra < N && qnta < n) || Ra < i){
            adda(++Ra);
        }
        if(Ra == N) break;

        while(Lb < N && Lb < Ra+k+1){
            if(Lb == Rb+1) Lb++, Rb++;
            else remb(Lb++);
        }

        if(Lb == N) break;

        while(Rb < N){
            addb(++Rb);
        }

        if(qntb < n) break;

        ans = min(ans, ansa + ansb);
    }

    if(ans == oo) ans = -1;

    printf("%lld\n", ans);

    return 0;
}
