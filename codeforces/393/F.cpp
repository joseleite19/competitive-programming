#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define mp make_pair

long long t, m, g;
pair<long long, long long> p[3];

double eps = 1e-9;

long long dist(int f, int s){
    long long x, y;

    x = p[f].ff - p[s].ff;
    y = p[f].ss - p[s].ss;

    return x*x + y*y;
}

bool test(int f, int s, int c){

    if(dist(f, s) > 4*m*m) return false;

    long double l, r;

    {
        long double ang = -atan2(p[f].ss - p[s].ss, p[f].ff - p[s].ff);

        pair<long double, long double>  q[3];
        for(int i = 0; i < 3; i++)
            q[i] = mp((p[i].ff - p[f].ff)*cos(ang) - (p[i].ss-p[f].ss)*sin(ang), sin(ang)*(p[i].ff - p[f].ff) + (p[i].ss-p[f].ss)*cos(ang));

        l = max(q[f].ff, q[s].ff) - m;
        r = min(q[f].ff, q[s].ff) + m;

        if(fabs(q[c].ss) - eps <= g && l <= q[c].ff + eps && q[c].ff - eps <= r) return true;
    }

    long double ang = -atan2(p[s].ss - p[f].ss, p[s].ff - p[f].ff);

    pair<long double, long double>  q[3];
    for(int i = 0; i < 3; i++)
        q[i] = mp((p[i].ff - p[f].ff)*cos(ang) - (p[i].ss-p[f].ss)*sin(ang), sin(ang)*(p[i].ff - p[f].ff) + (p[i].ss-p[f].ss)*cos(ang));

    l = max(q[f].ff, q[s].ff) - m;
    r = min(q[f].ff, q[s].ff) + m;

    if(fabs(q[c].ss) - eps > g) return false;
    if(q[c].ff - eps <= r && l <= q[c].ff + eps) return true;

    return false;
}

bool test2(int f, int s, int c){

    if(dist(f, s) > g*g) return false;

    long double l, r;

    {
        long double ang = -atan2(p[f].ss - p[s].ss, p[f].ff - p[s].ff);

        pair<long double, long double>  q[3];
        for(int i = 0; i < 3; i++)
            q[i] = mp((p[i].ff - p[f].ff)*cos(ang) - (p[i].ss-p[f].ss)*sin(ang), sin(ang)*(p[i].ff - p[f].ff) + (p[i].ss-p[f].ss)*cos(ang));

        l = max(q[f].ff, q[s].ff) - g;
        r = min(q[f].ff, q[s].ff) + g;

        if(fabs(q[c].ss) - eps <= m && l <= q[c].ff + eps && q[c].ff - eps <= r && !(q[c].ff < max(q[f].ff,q[s].ff) && q[c].ff > min(q[f].ff,q[s].ff))) return true;
    }

    long double ang = -atan2(p[s].ss - p[f].ss, p[s].ff - p[f].ff);

    pair<long double, long double>  q[3];
    for(int i = 0; i < 3; i++)
        q[i] = mp((p[i].ff - p[f].ff)*cos(ang) - (p[i].ss-p[f].ss)*sin(ang), sin(ang)*(p[i].ff - p[f].ff) + (p[i].ss-p[f].ss)*cos(ang));

    l = max(q[f].ff, q[s].ff) - g;
    r = min(q[f].ff, q[s].ff) + g;

    if(fabs(q[c].ss) - eps > m) return false;
    if(q[c].ff - eps <= r && l <= q[c].ff + eps && !(q[c].ff < max(q[f].ff,q[s].ff) && q[c].ff > min(q[f].ff,q[s].ff))) return true;

    return false;
}

int main(){

    scanf("%lld", &t);

    while (t--){
        scanf("%lld %lld", &g, &m);

        for(int i = 0; i < 3; i++)
            scanf("%lld %lld", &p[i].ff, &p[i].ss);

        if(p[0].ff*p[1].ss + p[1].ff * p[2].ss + p[0].ss * p[2].ff - p[0].ss * p[1].ff - p[1].ss * p[2].ff - p[2].ss * p[0].ff == 0){
            long long tmp = 0, x;

            tmp = max(max(dist(0, 1), dist(0, 2)), dist(1, 2));

            x = max(g, 2*m);

            printf("%s\n", tmp > x * x ? "NO" : "YES");
            continue;
        }

        bool can = false;
        can |= test(0, 1, 2);
        can |= test(0, 2, 1);
        can |= test(2, 1, 0);
        can |= test2(0, 1, 2);
        can |= test2(0, 2, 1);
        can |= test2(2, 1, 0);
        printf("%s\n", !can ? "NO" : "YES");
    }
    return 0;
}