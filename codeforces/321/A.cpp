#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int a, b;
char s[222];
int n;

pair<int, int> f(pair<int, int> p, char c){
    if(c == 'U') p.ss++;
    if(c == 'D') p.ss--;
    if(c == 'L') p.ff--;
    if(c == 'R') p.ff++;
    return p;
}

vector<pair<int, int> > v;

bool can(pair<int, int> x, pair<int, int> y){
    /*existe k >= 0 tal que
    y.ff*k = x.ff;
    y.ss*k = x.ss;*/

    if(!x.ff && !x.ss) return true;

    int k1, k2;
    if(!y.ff){
        if(x.ff) return false;
        k1 = 0;
    }
    else{
        if(x.ff % y.ff) return false;
        k1 = x.ff / y.ff;
    }
    
    if(!y.ss){
        if(x.ss) return false;
        k2 = 0;
    }
    else{
        if(x.ss % y.ss) return false;
        k2 = x.ss / y.ss;
    }

    if(k1 < 0 || k2 < 0) return false;
    if(k1 && k2 && k1 != k2) return false;
    if(x.ff != y.ff * k1 || (x.ff == 0 && y.ff)) return false;
    if(x.ss != y.ss * k2 || (x.ss == 0 && y.ss)) return false;
    return true;
    
}

int main(){

    scanf("%d %d %s", &a, &b, s);
    n = strlen(s);

    v.push_back(mp(0, 0));

    for(int i = 0; i < n; i++){
        v.push_back(f(v.back(), s[i]));
    }

    for(int i = 0; i < v.size(); i++){
        int x = a - v[i].ff;
        int y = b - v[i].ss;
        if(can(mp(x, y), v.back()))
            return printf("Yes\n"), 0;
    }

    printf("No\n");

    return 0;
}
