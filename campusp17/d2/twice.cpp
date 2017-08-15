#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

const int N = 100005;

char s[200];

int cnt[10];

int main(){

    int t;

    scanf("%d", &t);

    while(t--){
        scanf(" %s", s);
        int n = strlen(s);
        if(n > 20){
            printf("99887766554433221100\n");
            continue;
        }
        memset(cnt, 0, sizeof cnt);

        for(int i = 0; i < n; i++) s[i] -= '0';

        for(int i = 0; i < n; ){
            cnt[ s[i] ]++;
            if(cnt[ s[i] ] == 3){
                cnt[ s[i] ]--;
                
            }
            else i++;
        }

    }


    return 0;
}
