#include <cstdio>

int main(){
    int t, n, sum, notas[1005];
    double above;

    scanf("%d",&t);
    while(t--){
        above = sum = 0;
        scanf("%d", &n);
        for(int i = 0;i < n; i++){
            scanf("%d", notas+i);
            sum += notas[i];
        }
        sum /= n;
        for(int i = 0;i < n; i++)
            if(notas[i] > s)
                above++;

        printf("%.3lf%%\n",100*above/n);
    }

    return 0;
}
