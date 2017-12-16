#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;

const int N = 30005;

bitset<N> mat[N];

int n, a;
void file(){
    freopen("j.in", "r", stdin);
}
int main(){
    file();
    
    scanf("%d %d", &n, &a);

    for(int i = 0; i < a; i++){
        int q, w, e, r;
        scanf("%d %d %d %d", &q, &w, &e, &r);
        
        int X = q;
        int L, R;
        int addL, addR;
        if(r == 0){
            R = w+1;
            L = w - e + 1;
            addL = 1, addR = 0;
        }
        else if(r == 1){
            L = w;
            R = w + e;
            addL = 0, addR = -1;
        }
        else if(r == 2){
            L = w;
            R = w + 1;
            X -= e+1;
            addL = 0, addR = 1;
        }
        else if(r == 3){
            L = w;
            R = w+1;
            X -= e+1;
            addL = -1, addR = 0;
        }
        
        for(int x = X; x < X + e; x++){
            if(x >= N) break;
            if(x >= 0 && L <= n) mat[x].flip(max(0, L));
            if(x >= 0 && R <= n) mat[x].flip(max(0, R));

            L += addL;
            R += addR;
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        int sum = 0;
        for(int j = 0; j <= n; j++){
            sum ^= mat[i][j];
            if(sum) ans++;
            //printf("%d", (int)mat[i][j]);
            //if(sum) printf("%d %d\n", i, j);
        }
        //printf("\n");
    }
    
    printf("%d\n", ans);


    return 0;
}
