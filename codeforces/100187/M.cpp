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

int main(){

    scanf("%d", &n);

    vector<int> v1, v2;
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 1) v1.pb(b);
        else v2.pb(-b);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int m;

    scanf("%d", &m);

    int x;
    while(m--){
        scanf("%d", &x);
        int id1 = lower_bound(v2.begin(), v2.end(), x) - v2.begin();
        id1 = int(v2.size()) - id1;
        int id2 = upper_bound(v1.begin(), v1.end(), x) - v1.begin();
        printf("%d\n", id1+id2);
    }
    
    return 0;
}
