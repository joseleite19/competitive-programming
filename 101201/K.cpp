#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

double fat(int x){
    double ans = 1;
    for(int i = 1; i <= x; i++)
        ans *= i;
    return ans;
}

int main(){
    long long k, r;

    scanf("%lld %lld", &k, &r);

    double ans = 0;

    long long tot = 1LL << k;
    for(long long games = 1; games <= k; games++){
        long long people = (1 << games);
    double prob = 1;
        //C(tot-r, people-1) / C(tot-1, people-1)

        //C(n, k) = fat(n) / (fat(k)*fat(n-k))
        //fat(tot - r) / (fat(people-1) * fat(tot-r-people+1))
        //fat(tot - 1) / (fat(people-1) * fat(tot - people))

        // (fat(tot - r) / fat(tot-r-people+1)) / (fat(tot-1) / fat(tot - people))

        // fat(tot - r) * fat(tot - people)
        // fat(tot - r - people + 1) * fat(tot - 1)
        if(people-1 > tot-r) continue;
        if(people-1 > tot) continue;

        // prob *= fat(tot-r) * fat(tot - people);
        // prob /= fat(tot - r - people + 1) * fat(tot - 1);

        for(int i = tot - r - people + 2, j = tot - r + 1; i <= tot - people; i++, j++)
            prob *= double(i) / j;

        /*for(int i = tot; i >= 0; i--){
            if(i <= tot - people && i > tot - r - people + 1 && i <= tot - 1 && i > tot - r) continue;

            if(i <= tot - people && i > tot - r - people + 1)
                prob *= i;
            if(i <= tot - 1 && i > tot - r)
                prob /= i;
        }*/

        ans += prob;
    }

    printf("%.5lf\n", ans);




    return 0;
}
