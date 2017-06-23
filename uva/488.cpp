#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, a, b;

    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        if(tc > 1) printf("\n");
        scanf("%d %d", &a, &b);
        
        for(int q = 0; q < b; q++){
            if(q) printf("\n");
            for(int i = 1; i <= a; i++){
                for(int j = 0; j < i; j++)
                    printf("%d", i);
                printf("\n");
            }
            for(int i = a-1; i >= 1; i--){
                for(int j = 0; j < i; j++)
                    printf("%d", i);
                printf("\n");
            }
        }
    }




    return 0;
}
