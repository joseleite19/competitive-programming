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

int cnt[333];

char s[N];
int v[N];

int main(){

    int n, m;

    scanf("%s %d", s, &m);

    n = strlen(s);

    while(m--){
        int x;
        scanf("%d", &x);
        v[x-1]++;
        v[n-x+1]++;
    }

    int cnt = 0;
    for(int i = 0; i < n/2; i++){
        cnt += v[i];
        if(cnt & 1){
            swap(s[i], s[n-i-1]);
        }
    }

    printf("%s\n", s);





    return 0;
}
