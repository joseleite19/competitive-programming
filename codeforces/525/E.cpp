#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 500005;

ll C(int n, int k){
    if(n == 0 || k == 0 || n == k) return 1;
    return C(n-1, k) + C(n, k-1);
}

map<int, int> cnt;
ll fat[20];

ll f(int left){
    if(!left) return 1;
    
    ll ans = 0;
    for(int i = 1; i <= left; i++){
        ans = max(ans, (i+1)*(f(left-i)+1));
    }
    return ans;
}

int main(){
    fat[0] = 1;
    for(int i = 1; i < 20; i++)
        fat[i] = i*fat[i-1];
    int n, k;
    ll s;

    scanf("%d %d %lld", &n, &k, &s);

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    //<val, num ways, stick useds>
    vector< vector<tuple<ll, ll, int> > > v;
    for(pair<int, int> x : cnt){
        vector<tuple<ll, ll, int> > tmp;
        int len = x.ss;
        if(x.ff <= 18){ // 3 parts: i stick, j choose, k unchoose
            for(int i = 0; i <= len && i <= k; i++){
                for(int j = 0; j <= len; j++){
                    if(i + j > len) continue;
                    int k = len - i - j;
                    ll val = x.ff * j + fat[x.ff] * i;
                    if(val > s) continue;
                    ll how = C(len, i) * C(len-i, j);
                    tmp.eb(val, how, i);
                    //printf("%d: %lld %lld %d\n", x.ff, val, how, i);
                }
            }
        }
        else{ // 2 parts
            for(int i = 0; i <= len; i++){
                ll val = x.ff * i;
                if(val > s) continue;
                ll how = C(len, i);
                tmp.eb(val, how, 0);
            }
        }

        v.eb(move(tmp));
    }
    
    vector<tuple<ll, ll, int> > ans;

    ll a, b, c, d;
    int e, f;
    ll w = 0;
    for(const auto &vv : v){
        int sz = ans.size();
        for(const auto &x : vv){
            ans.eb(x);
            tie(a, b, e) = x;
            for(int i = 0; i < sz; i++){
                tie(c, d, f) = ans[i];
                if(f + e > k || a + c > s) continue;
                //printf("%lld %lld %d, %lld %lld %d\n", a, b, e, c, d, f);
                ans.eb(a + c, b * d, e + f);
            }
        }
    }


    for(const auto &x : ans){
        tie(a, b, e) = x;
        if(a == s){
            w += b;
        }
    }

    printf("%lld\n", w);
    


    return 0;
}
