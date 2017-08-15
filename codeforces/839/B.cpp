#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int v[N];

int main(){

    int n, k;

    scanf("%d %d", &n, &k);
    
    for(int i = 0; i < k; i++)
        scanf("%d", v+i);

    int four = n, two = 2*n, one = 0;

    for(int i = 0; i < k; i++){
        int tmp = v[i] / 4;
        if(four < tmp){
            tmp -= four;
            four = 0;
            if(two < 2*tmp){
                if(4*tmp - 2*two > one) return printf("NO\n"), 0;
                one -= 4*tmp - 2*two;
                two = 0;
            }
            two -= 2*tmp;
        }
        else four -= tmp;
        tmp = v[i] % 4;
        if(!tmp) continue;
        if(tmp == 1 && one){
            one--;
            continue;
        }
        if(tmp == 3 && one){
            if(two){
                two--;
                one--;
                continue;
            }
        }
        if(two < (tmp+1) / 2){
            if(four){
                if(tmp == 1) two++;
                if(tmp == 2) one++;
                four--;
                continue;
            }
            return printf("NO\n"), 0;
        }
        two -= (tmp+1)/2;
    }
    printf("YES\n");



    return 0;
}
