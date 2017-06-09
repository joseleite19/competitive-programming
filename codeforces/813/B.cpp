#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long x, y, l, r;

int f(long long v, long long a){
    int ans = 0;
    while(v) ans++, v /= a;
    return ans;
}

int main(){

    scanf("%lld %lld %lld %lld", &x, &y, &l, &r);

    int limx = f(r, x), limy = f(r, y);

    long long xx = 1, yy = 1;

    vector<long long> v;

    for(int i = 0; i < limx; i++){
        
        yy = 1;
        for(int j = 0; j < limy; j++){
            if(xx + yy > r) break;
            if(l <= xx + yy){
                v.push_back(xx + yy);
            }

            yy *= y;
        }

        xx *= x;
    }

    if(v.empty()) return printf("%lld\n", r - l  +1) , 0;

    sort(v.begin(), v.end());

    long long ans = v[0] - l;

    for(int i = 1; i < v.size(); i++)
        ans = max(ans, v[i] - v[i-1] - 1);

    ans = max(ans, r - v.back());

    printf("%lld\n", ans);




    return 0;
}
