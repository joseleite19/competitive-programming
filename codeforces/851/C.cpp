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
typedef tuple<int, int, int, int, int> po;

int n;
int v[N][5];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++)
            scanf("%d", &v[i][j]);
    }
    if(n > 100) return printf("0\n"), 0;

    vector<int> ans;

    for(int i = 0; i < n; i++){
        bool good = true;
        for(int j = 0; j < n; j++) if(i != j){
            for(int k = j+1; k < n; k++) if(i != k){
                ll tmp = 0;
                for(int q = 0; q < 5; q++)
                    tmp += (v[j][q] - v[i][q]) * (v[k][q] - v[i][q]);
                
                if(tmp > 0)
                    good = false;
            }
        }
        if(good) ans.eb(i+1);
    }

    printf("%d\n", int(ans.size()));

    for(int x : ans) printf("%d ", x);
    printf("\n");



    return 0;
}
