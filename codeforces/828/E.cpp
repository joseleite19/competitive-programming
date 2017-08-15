#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 100005;

char s[N];

char e[22];

class Bit{
    int n;
    vector<int> ft;

public:
    Bit(int sz = 0) : n(sz), ft(sz+1, 0){}
    int query(int x) const{
        int ans = 0;
        for(; x > 0; x -= x & -x)
            ans += ft[x];
        return ans;
    }
    void update(int x, int v){
        for(; x <= n; x += x & -x)
            ft[x] += v;
    }
    int query(int i, int j){
        return query(j) - query(i-1);
    }
};

int back(char c){
    if(c == 'A') return 0;
    if(c == 'T') return 1;
    if(c == 'G') return 2;
    if(c == 'C') return 3;
    assert(0);
}

int main(){

    scanf("%s", s);
    int n = strlen(s);

    vector<vector<vector<Bit> > > ft(13, vector<vector<Bit> >(13, vector<Bit>(4, Bit(n))));

    for(int i = 0; i < n; i++){
        int p = i;
        for(int mod = 1; mod <= 10; mod++){
            ft[mod][(p % mod) + 1][back(s[i])].update(p+1, 1);
        }
    }

    // mod / pos / letter

    int q;

    scanf("%d", &q);

    int t, l, r, sz, x;
    char c;
    while(q--){
        scanf("%d", &t);

        if(t == 2){
            scanf("%d %d %s", &l, &r, e);
            sz = strlen(e);
            int ans = 0;
            for(int i = 0; i < sz; i++){
                ans += ft[sz][(i+l-1)%sz+1][back(e[i])].query(l, r);
            }
            printf("%d\n", ans);
        }
        else{
            scanf("%d %c", &x, &c);
            x--;
            for(int mod = 1; mod <= 10; mod++){
                ft[mod][(x % mod) + 1][ back(s[x]) ].update(x+1,-1);
                ft[mod][(x % mod) + 1][ back(  c ) ].update(x+1, 1);
            }
            s[x] = c;
        }
    }


    return 0;
}
