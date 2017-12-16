#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 200005;

int n;

pair<int, int> v[N];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d %d", &v[i].ff, &v[i].ss);

    sort(v, v+n);

    int lasta = -2, lastb = -2;

    for(int i = 0; i < n; i++){
        if(v[i].ff > lasta){
            lasta = v[i].ss;
        }
        else if(v[i].ff > lastb){
            lastb = v[i].ss;
        }
        else return printf("NO\n"), 0;
    }
    printf("YES\n");
    
}
