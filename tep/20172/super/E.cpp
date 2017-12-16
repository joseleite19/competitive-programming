#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
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

int main(){

    int t;

    scanf("%d", &t);

    int k;
    for(int tc = 1; tc <= t; tc++){
        if(tc > 1) printf("\n");
            scanf("%d", &k);

            if(k == 0) printf("1 1 0");
            if(k == 1) printf("2 1 1 0");
            if(k == 2) printf("6 2 3 1 0");
            if(k == 3) printf("4 1 2 1 0 0");
            if(k == 4) printf("30 6 15 10 0 -1 0");
            if(k == 5) printf("12 2 6 5 0 -1 0 0");
            if(k == 6) printf("42 6 21 21 0 -7 0 1 0");
            if(k == 7) printf("24 3 12 14 0 -7 0 2 0 0");
            if(k == 8) printf("90 10 45 60 0 -42 0 20 0 -3 0");
            if(k == 9) printf("20 2 10 15 0 -14 0 10 0 -3 0 0");
            if(k == 10) printf("66 6 33 55 0 -66 0 66 0 -33 0 5 0");
            if(k == 11) printf("24 2 12 22 0 -33 0 44 0 -33 0 10 0 0");
            if(k == 12) printf("2730 210 1365 2730 0 -5005 0 8580 0 -9009 0 4550 0 -691 0");
            if(k == 13) printf("420 30 210 455 0 -1001 0 2145 0 -3003 0 2275 0 -691 0 0");
            if(k == 14) printf("90 6 45 105 0 -273 0 715 0 -1287 0 1365 0 -691 0 105 0");
            if(k == 15) printf("48 3 24 60 0 -182 0 572 0 -1287 0 1820 0 -1382 0 420 0 0");
            if(k == 16) printf("510 30 255 680 0 -2380 0 8840 0 -24310 0 44200 0 -46988 0 23800 0 -3617 0");
            if(k == 17) printf("180 10 90 255 0 -1020 0 4420 0 -14586 0 33150 0 -46988 0 35700 0 -10851 0 0");
            if(k == 18) printf("3990 210 1995 5985 0 -27132 0 135660 0 -529074 0 1469650 0 -2678316 0 2848860 0 -1443183 0 219335 0");
            if(k == 19) printf("840 42 420 1330 0 -6783 0 38760 0 -176358 0 587860 0 -1339158 0 1899240 0 -1443183 0 438670 0 0");
            if(k == 20) printf("6930 330 3465 11550 0 -65835 0 426360 0 -2238390 0 8817900 0 -24551230 0 44767800 0 -47625039 0 24126850 0 -3666831 0");

            printf("\n");
        }


    return 0;
}
