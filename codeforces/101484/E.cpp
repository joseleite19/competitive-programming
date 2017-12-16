#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

const int N = 100005;

int n, m;
pair<int, int> p1[N], p2[N];

vector<pair<int, int> > low, up;

void process(){
    int mn = 0, mx = 0;

    for(int i = 0; i < n; i++){
        if(p1[i] < p1[mn])
            mn = i;
        if(p1[i] > p1[mx])
            mx = i;
    }


}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d %d", &p1[i].ff, &p1[i].ss);

    for(int i = 0; i < m; i++)
        scanf("%d %d", &p2[i].ff, &p2[i].ss);





    return 0;
}
