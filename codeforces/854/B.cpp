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

    int n, k;

    scanf("%d %d", &n, &k);

    if(k == n || k == 0) return printf("0 0\n"), 0;

    //0 x 0 0 x 0
    //2*k good
    printf("1 %d\n", min(2*k, n - k));


    return 0;
}
