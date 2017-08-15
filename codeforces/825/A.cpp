#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
char s[100];

int main(){

    scanf("%d %s", &n, s);

    int num = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') num++;
        else{
            printf("%d", num);
            num = 0;
        }
    }
    printf("%d", num);

    printf("\n");


    return 0;
}
