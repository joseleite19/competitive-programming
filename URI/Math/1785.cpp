#include <cstdio>

int menor_numero_com_digitos_de(int x){
    int n[4], i, j;
    for(i = 0; i < 4; i++){
        n[i] = x%10;
        x /= 10;
    }
    for(i = 0; i < 4; i++)
        for(j = i+1; j < 4; j++)
            if(n[i] > n[j]){
                n[i] = n[i]^n[j];
                n[j] = n[i]^n[j];
                n[i] = n[i]^n[j];
            }
    return n[0]*1000 + n[1]*100 + n[2]*10 + n[3];
}

int maior_numero_com_digitos_de(int x){
    int n[4], i, j;
    for(i = 0; i < 4; i++){
        n[i] = x%10;
        x /= 10;
    }
    for(i = 0; i < 4; i++)
        for(j = i+1; j < 4; j++)
            if(n[i]<n[j]){
                n[i] = n[i]^n[j];
                n[j] = n[i]^n[j];
                n[i] = n[i]^n[j];
            }
    return n[0]*1000 + n[1]*100 + n[2]*10 + n[3];
}

int krapekar(int X){
    int cnt = 0;
    while (X != 6174){
        int maior = maior_numero_com_digitos_de(X);
        int menor = menor_numero_com_digitos_de(X);
        X = maior - menor;
        cnt = cnt + 1;
    }
    return cnt;
}

int main(){
    int n, i, a;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        if(a == 0 || a == 1111 || a == 2222 || a == 3333 || a == 4444 || a == 5555 || a == 6666 || a == 7777 || a == 8888 || a == 9999)
            printf("Caso #%d: %d\n",i+1,-1);
        else
            printf("Caso #%d: %d\n",i+1,krapekar(a));
    }
    return 0;
}
