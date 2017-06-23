#include <bits/stdc++.h>

using namespace std;

int n, v[55];

int fat(int k){
    int ans = 1;
    for(int i = 1; i <= k; i++) ans *= i;
    return ans;
}

int comp(int k){
    int ans = 1;

    for(int i = 1; k-i > 0; i += 2){
        ans *= k-i;
    }

    return ans;
}
// segmento termina no indice i
int f(int i, int d, int t){ //qnts de 2 e qnts de 3
    if(i == n-1) return 1;

    printf("%d %d %d\n", i, d, t);

    int ans = 0;
    int dd = 0, tt = 0;
    // novo segmento [i+1, j]
    for(int j = i+1; j < n-1; j++){
        if(v[j] == 2) dd++;
        if(v[j] == 3) tt++;
        printf(".%d\n", j);
        if(t < j - i) continue;
        int qntfora = t - (j - i);
        if(qntfora & 1) continue;
        ans = max(ans, fat(t)/fat(qntfora)*comp(qntfora)*f(j, dd, tt));
    }

    //testa segmento [i+1, n-1] (ultimo segmento)
    int qntfora = t - (n-1 - i);
    printf("%d\n", qntfora);
    if(t <= n-1 - i && qntfora % 2 == 0)
        ans = max(ans, fat(t)/fat(qntfora)*comp(qntfora)*f(n-1, dd, tt));

    return ans;
}


int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    int ans = 0;
    int d = 0, t = 0;
    for(int i = 1; i <= v[0]; i++){
        if(v[i] == 2) d++;
        if(v[i] == 3) t++;
    }

    printf("%d\n", f(v[0], d, t));



    return 0;
}
