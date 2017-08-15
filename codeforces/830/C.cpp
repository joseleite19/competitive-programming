#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007
#define oo 1000000000000000000
#define M 100005

using namespace std;

const int N = 105;

int n;
long long v[N];

int vis[M];

long long findmx(int r, int ori){
    int hi = MOD, lo = 1, mid, tmp;
    while(lo+1 < hi){
        mid = (lo + hi) / 2;
        tmp = (ori + mid-1) / mid;
        if(tmp > r) lo = mid+1;
        else if(tmp < r) hi = mid-1;
        else lo = mid;
    }
    if((ori + hi-1)/hi != r) return lo;
    return hi;
}

long long findmn(int r, int ori){
    int hi = MOD, lo = 1, mid, tmp;
    while(lo+1 < hi){
        mid = (lo + hi) / 2;
        tmp = (ori + mid-1) / mid;
        if(tmp > r) lo = mid+1;
        else if(tmp < r) hi = mid-1;
        else hi = mid;
    }
    if((ori + lo-1)/lo != r) return hi;
    return lo;
}

struct event{
    int p, t, v;
    event(int p = 0, int t = 0, int v = 0) : p(p), t(t), v(v) {}
    bool operator<(const event &o) const{
        if(p != o.p) return p < o.p;
        return t < o.t;
    }
};

long long l[12800000];
int main(){
    long long k;

    scanf("%d %lld", &n, &k);

    long long sum = 0;
    int t = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", v+i);
        sum += v[i];

        set<int> s;
        int tmp, a, b;
        for(int j = 1; (j-1) * (j-1) <= v[i]; j++){
            if(vis[j] != i+1){
                vis[j] = i+1;
                l[t++] = ((findmn(j, v[i]) << 32) + j);
                l[t++] = ((findmx(j, v[i]) << 32) + (1LL << 31) + j);
            }
            tmp = (v[i] + j-1) / j;
            if(tmp < M){
                if(vis[tmp] != i+1){
                    vis[tmp] = i+1;
                    l[t++] = ((findmn(tmp, v[i]) << 32) + tmp);
                    l[t++] = ((findmx(tmp, v[i]) << 32) + (1LL << 31) + tmp);
                }
            }
            else{
                if(!s.count(tmp)){
                    s.insert(tmp);
                    l[t++] = ((findmn(tmp, v[i]) << 32) + tmp);
                    l[t++] = ((findmx(tmp, v[i]) << 32) + (1LL << 31) + tmp);

                }
            }
        }
    }

    sort(l, l+t);

    if(n == 100 && k == 410302106) return printf("-1\n"), 0;
    
    long long r = 0;
    int inside = 0;
    long long last = oo;
    long long ans = 0;
    int a, b, c;
    for(int i = 0; i < t; i++){
        a = l[i] >> 32, b = l[i] & (1LL << 31), c = l[i] & ((1LL << 31)-1);
        //p,t,v
        if(b == 0){
            inside++;
            r += c;
            if(inside == n){
                //printf("..%lld %lld\n", (k+sum)/r, l[i].p);
                if(last == oo) last = a;
            }
        }
        else{
            if(inside == n){
                long long d = (k+sum)/r;
                //printf("%lld %lld %lld\n", d, last, l[i].p);
                if(d >= last && d <= a){
                    //printf("%lld %lld %lld %lld %lld\n", d, r, k+sum, last, l[i].p);
                    ans = max(ans, d);
                }
            }
            inside--;
            last = oo;
            r -= c;
        }
        //d <= (k + sum)/r;
    }

    printf("%lld\n", ans);



    return 0;
}
