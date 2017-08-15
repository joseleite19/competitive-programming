#include <bits/stdc++.h>

#define ff first
#define ss second

#define MOD (1000000007)

using namespace std;

const int N = 1000006;

vector<pair<int, int> > v;

long long dist(int x, int y){
    long long ans = 0;
    for(int i = 0; i < v.size(); i++)
        ans += abs(v[i].ff - x) + abs(v[i].ss - y);
    return ans;
}

long long dist(int i, int x, int y){
    return abs(v[i].ff - x) + abs(v[i].ss - y);
}

long long dd(long long a, long long b){
    return a / b + (a % b >= (b)/2);
}

int main(){

    int r;

    scanf("%d", &r);

    for(int i = 0; i < r; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        for(int x = a; x <= c; x++){
            for(int y = b; y <= d; y++){
                v.emplace_back(x, y);
            }
        }
    }

    sort(v.begin(), v.end());

    long long dx = 0, dy = 0;

    for(int i = 0; i < v.size(); i++)
        dx += v[i].ff, dy += v[i].ss;
    
    dx = dd(dx, v.size()), dy = dd(dy, v.size());

    int ans = 0;

    for(int i = 0; i < v.size(); i++){
        if(dist(ans, dx, dy) > dist(i, dx, dy))
            ans = i;
    }

    printf("%lld\n", dist(v[ans].ff, v[ans].ss));
    printf("%d %d\n", v[ans].ff, v[ans].ss);


    return 0;
}
