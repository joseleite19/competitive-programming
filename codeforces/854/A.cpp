#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int main(){

    int n;

    scanf("%d", &n);

    int q = 0, w = 1;
    for(int a = 1; a <= n; a++){
        for(int b = a+1; b <= n; b++){
            if(__gcd(a, b) != 1) continue;
            if(a + b != n) continue;
            if(a*w > q*b){
                q = a, w = b;
            }
        }
    }

    printf("%d %d\n", q, w);


    return 0;
}
