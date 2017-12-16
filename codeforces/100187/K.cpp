#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 200005;

int n;
ll k;
int ans[N];

int main(){

    scanf("%d %lld", &n, &k);

    int off = 1;
    int q = n;
    while(k){
        if(k <= q-1){
            ans[k+1] = off++;
            break;
        }
        else{
            ans[q] = off++;
            k -= q-1;
            q--;
        }
    }

    for(int i = 1; i <= n; i++) if(!ans[i]){
        ans[i] = off++;
    }

    printf("%d", ans[1]);

    for(int i = 2; i <= n; i++)
        printf(" %d", ans[i]);
    printf("\n");



    return 0;
}
