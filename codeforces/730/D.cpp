#include <bits/stdc++.h>

#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;

const int N = 200005;

int n;
long long r, l[N], t[N];

long long f(){

    long long rem = 0, ans = 0;

    for(int i = 0; i < n; i++){
        long long L = l[i] - rem, T = t[i] - rem;
        if(L <= 0){
            rem -= l[i];
            continue;
        }
        rem = 0;
        if(2*L <= T){
            continue;
        }
        long long tmp = 2*L-T;
        ans += (tmp + r - 1)/r;
        rem = (r - (tmp % r)) % r;
    }

    return ans;
}

long long print_ans(){

    long long rem = 0, ans = 0;

    long long tot = 0;
    for(int i = 0; i < n; i++){
        long long L = l[i] - rem, T = t[i] - rem;
        if(L <= 0){
            rem -= l[i];
            continue;
        }
        rem = 0;
        if(2*L <= T){
            tot += 2*L;
            continue;
        }
        long long tmp = 2*L-T;
        ans += (tmp + r - 1)/r;
        long long qnt = (tmp + r - 1)/r;
        long long tt = rem;
        for(int i = 0; i < qnt-1; i++){
            printf("%lld ", tot + tt);
            tt += r;
        }
        rem = (r - (tmp % r)) % r;
        printf("%lld ", tot + T - (r-rem));
        tot += T + rem;
    }
    printf("\n");

    return ans;
}

int main(){

    scanf("%d %lld", &n, &r);

    for(int i = 0; i < n; i++)
        scanf("%lld", l+i);

    for(int i = 0; i < n; i++)
        scanf("%lld", t+i);

    for(int i = 0; i < n; i++) if(t[i] < l[i])
        return printf("-1\n"), 0;

    long long ans = f();

    printf("%lld\n", ans);

    if(ans <= 100000) print_ans();

	return 0;
}
