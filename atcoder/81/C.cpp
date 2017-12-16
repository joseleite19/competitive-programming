#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

typedef long long ll;

ll v[N];

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    sort(v, v+n);

    long long a = 0, b = 0;

    int i;
    for(i = n-1; i > 0; i--){
        if(v[i] == v[i-1]){
            a = v[i];
            i -= 2;
            break;
        }
    }

    for(; i > 0; i--){
        if(v[i] == v[i-1]){
            b = v[i];
            break;
        }
    }

    printf("%lld\n", a * b);

}
