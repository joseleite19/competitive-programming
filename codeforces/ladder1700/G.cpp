#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 2002;

int v[N];

long long lcm(long long a, long long b){
    return a / __gcd(a, b) * b;
}

int main(){

    int t, n;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            scanf("%d", v+i);

        long long tmp = 1, sum;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum = 0;
            tmp = 1;
            for(int j = i; j < n; j++){
                sum += v[j];
                tmp = lcm(tmp, v[j]);
                if(tmp > 100000000000000) break;
                if(sum % tmp == 0){
                    ans++;
                }
            }
        }

        printf("%d\n", ans);
    }


	return 0;
}
