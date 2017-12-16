#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10004;

int n, k;
int v[100][N];


bool f(){
    //if(n <= k) return 0;
    int i = 0, j = 0;

    for(int i = 0; i < k; i++){
        int w;
        for(w = i; w < n; w++) if(v[i][w]) // procura primeiro 1 da linha
            break;
        if(w == n) return 0; // nao tem nenhum 1 na linha
        
        for(int q = 0; q < k; q++)
            swap(v[q][i], v[q][w]);
        
        for(int q = 0; q < k; q++) if(q != i){
            if(v[q][i]){
                for(int w = 0; w < n; w++)
                    v[q][w] ^= v[i][w];
            }
        }
        for(int w = 0; w < n; w++) if(w != i){
            if(v[i][w]){
                for(int q = 0; q < k; q++)
                    v[q][w] ^= v[q][i];
            }        
        }
    }
    for(int w = 0; w < n; w++){
        int zero = 0;
        for(int q = 0; q < k; q++){
            if(v[q][w]){
                zero = 1;
                break;
            }
        }
        if(!zero) return 1;
    }
    return 0;
}

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        int x;
        for(int j = 0; j < k; j++){
            scanf("%d", &x);
            x &= 1;
            v[j][i] = x;
            assert(v[j][i] <= 1);
        }
    }

    printf("%s\n", !f() ? "S" : "N");

    return 0;
}

