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
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

char s[N][8];
int n;
int t[N];
int e = 0;

int b(int i){
    int x;
    if(sscanf(s[i], "%d", &x) != 1) return N-1;
    if(strcmp(to_string(x).c_str(), s[i])) return N-1;
    return x;
}

int vis[N];
int vis2[N];
int main(){

    scanf("%d", &n);

    for1(i, n)
        scanf(" %s %d", s[i], t+i), e += t[i];

    vector<pair<string, string> > v;
    int l = n;
    for1(i, n){
        int x = b(i);
        if(x <= n) vis2[x] = 1;
    }

    l = 1;
    for1(i, n) if(t[i]){
        int x = b(i);
        if(x <= e || x > n) continue;
        while(l <= e && vis2[l]) l++;
        if(l > e) break;
        vis2[x] = 0;
        vis2[l] = 1;
        v.eb(s[i], to_string(l));
        sprintf(s[i], "%d", l++);
    }

    l = n;
    for1(i, n) if(t[i] == 0){
        if(b(i) <= e){
            while(l <= n && l > e && vis2[l]) l--;
            if(l == e) break;
            v.eb(s[i], to_string(l));
            sprintf(s[i], "%d", l--);
        }
    }

    set<int> wa, wb;

    for1(i, n){
        int x = b(i);
        if(t[i] == 0){
            if(x > e && x <= n) continue;
            wb.insert(i);
        }
        else{
            if(x <= e) continue;
            wa.insert(i);
        }
    }

    set<int> la, lb;

    for1(i, e) la.insert(i);
    fore(i, e+1, n) lb.insert(i);

    for1(i, n){
        int x = b(i);
        if(x <= e) la.erase(x);
        else if(x <= n) lb.erase(x);
    }

    set<int> wwa, wwb;
    int fora = 999999;
    while(!wa.empty() || !wb.empty() || !wwa.empty() || !wwb.empty()){
        if(!wa.empty() && !la.empty()){
            int i = *wa.begin();
            int l = *la.begin();
            wa.erase(i), la.erase(l);
            int x = b(i);
            if(x <= e) la.insert(x);
            else if(x <= n) lb.insert(x);

            v.eb(s[i], to_string(l));
            sprintf(s[i], "%d", l);
        }   
        else if(!wb.empty() && !lb.empty()){
            int i = *wb.begin();
            int l = *lb.begin();
            wb.erase(i), lb.erase(l);
            int x = b(i);
            if(x <= e) la.insert(x);
            else if(x <= n) lb.insert(x);
            v.eb(s[i], to_string(l));
            sprintf(s[i], "%d", l);
        }
        else if(!wwa.empty() && !la.empty()){
            int i = *wwa.begin();
            int l = *la.begin();
            wwa.erase(i), la.erase(l);
            int x = b(i);
            if(x <= e) la.insert(x);
            else if(x <= n) lb.insert(x);

            v.eb(s[i], to_string(l));
            sprintf(s[i], "%d", l);
        }   
        else if(!wwb.empty() && !lb.empty()){
            int i = *wwb.begin();
            int l = *lb.begin();
            wwb.erase(i), lb.erase(l);
            int x = b(i);
            if(x <= e) la.insert(x);
            else if(x <= n) lb.insert(x);
            v.eb(s[i], to_string(l));
            sprintf(s[i], "%d", l);
        }
        else{
            if(!wa.empty()){
                int i = *wa.begin();
                wa.erase(i);
                wwa.insert(i);
                int x = b(i);
                if(x <= e) la.insert(x);
                else if(x <= n) lb.insert(x);

                v.eb(s[i], to_string(fora));
                sprintf(s[i], "%d", fora--); 
            }
            else if(!wb.empty()){
                int i = *wb.begin();
                wb.erase(i);
                wwb.insert(i);
                int x = b(i);
                if(x <= e) la.insert(x);
                else if(x <= n) lb.insert(x);

                v.eb(s[i], to_string(fora));
                sprintf(s[i], "%d", fora--); 
            }
            else assert(0);
        }
    }



    printf("%d\n", int(v.size()));

    for(auto x : v)
        printf("move %s %s\n", x.ff.c_str(), x.ss.c_str());


    return 0;
}
