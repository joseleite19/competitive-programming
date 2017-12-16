#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, n) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int n, k, x;
int v[N];

int f(const vector<int>& v){
    vector<int> s;
    int ans = -1;
    forn(i, v.size()){
        s.pb(v[i]);
        while(s.size() >= 3){
            if(i < v.size()-1 && v[i+1] == v[i]) break;
            if(s.back() == s[s.size()-2] && s.back() == s[s.size()-3]){
                while(s.size() > 1 && s.back() == s[s.size()-2]){
                    ans++;
                    s.pop_back();
                }
                    ans++;
                    s.pop_back();
            }
            else break;
        }
    }
    return max(0, ans);
}

int main(){

    scanf("%d %d %d", &n, &k, &x);

    forn(i, n) scanf("%d", v+i);

    int ans = 0;
    forn(i, n+1){
        vector<int> q;
        forn(j, n+1){
            if(j < i) q.pb(v[j]);
            else if(j > i) q.pb(v[j-1]);
            else q.pb(x);
        }
        ans = max(ans, f(q));
    }

    printf("%d\n", ans);


    return 0;
}
