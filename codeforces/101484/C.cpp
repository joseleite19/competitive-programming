#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

vector<pair<int, pair<int, int> > > att[333]; // <team, <problem, ok> >

char s[100], ss[100];

ll cnt[222][300];
ll sc[222], pen[222];

int main(){

    int n, m, p;

    map<string, int> go;

    scanf("%d %d %d", &n, &m, &p);

    for(int i = 0; i < n; i++){
        scanf(" %s", s);
        if(!go.count(s)) go[s] = i;
        else assert(0);
    }

    for(int i = 0; i < m; i++){
        char pr;
        int t;

        scanf(" %s %c %d %s", s, &pr, &t, ss);
        att[t].eb(go[s], mp(pr-'A', ss[0] == 'O'));
    }

    ll msc = 0, pp = 0;

    int ans = 0;
    for(int i = 0; i < 300; i++){

        for(auto x : att[i]){
            if(x.ss.ss){ //OK
                if(cnt[x.ff][x.ss.ff] == -1) continue;
                sc[x.ff]++;
                pen[x.ff] += i + 20*cnt[x.ff][x.ss.ff];
                cnt[x.ff][x.ss.ff] = -1;
                if(sc[x.ff] > msc){
                    msc = sc[x.ff];
                    pp = pen[x.ff];
                }
                else if(sc[x.ff] == msc){
                    pp = min(pp, pen[x.ff]);
                }
            }
            else{
                cnt[x.ff][x.ss.ff]++;
            }
        }

        if(sc[0] == msc && pen[0] == pp)
            ans++;
    }

    printf("%d\n", ans);


    return 0;
}
