#include <bits/stdc++.h>

using namespace std;

const int N = 1505;

char s[N], bad[N];
int ptr;
map<char, int> tr[N*N];

int putchar(int s, char c){
    if(!tr[s].count(c)) tr[s][c] = ++ptr;
    return tr[s][c];
}

int main(){

    int k;
    scanf("%s %s %d", s, bad, &k);

    int n = strlen(s);

    for(int i = 0; i < n; i++){
        int p = 0;
        int cnt = 0;
        for(int j = i; j < n; j++){
            if(bad[ s[j]-'a' ] == '0'){
                cnt++;
                if(cnt > k) break;
            }
            p = putchar(p, s[j]);
        }
    }

    printf("%d\n", ptr);



    return 0;
}
