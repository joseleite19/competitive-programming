#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

int used[N], d[N], lp[N], pot[N];

int main(){

    for(int i = 2; i < N; i++){
        if(!lp[i]){
            lp[i] = i;
            pot[i] = 1;
            for(int j = i + i; j < N; j += i) if(!lp[j]){
                lp[j] = i;
            }
        }
        else{
            int j = i, is = 1;
            while(j > 1 && is){
                if(lp[j] != lp[i]) is = false;
                j /= lp[j];
            }
            if(is) pot[i] = 1;
        }
    }

    for(int i = 2; i < 40; i++)
        printf("%d %d %d\n", i, lp[i], pot[i]);




    return 0;
}
