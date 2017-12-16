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
const int N = 100005;

int y[N], n;


int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", y+i);

    map<pair<int, int>, set<int> > m;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int a = y[j] - y[i];
            int b = j - i;
            int g = __gcd(a, b);
            if(g) a /= g, b /= g;
            m[mp(a, b)].insert(i);
            m[mp(a, b)].insert(j);
        }
    }

    if(m.size() == 1) return printf("No\n"), 0;

    for(const auto &x : m){
        if(x.ss.size() == n || x.ss.size() == n-1)
            return printf("Yes\n"), 0;
    }

    printf("No\n");



    return 0;
}
