#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

map<char, int> tr[N];
int fim[N];
int ptr;

char s[N];

bool insert(){
    int p = 0;

    for(int i = 0; s[i]; i++){
        if(!tr[p].count(s[i])) tr[p][ s[i] ] = ptr++;
        p = tr[p][ s[i] ];
        if(fim[p]) return false;
    }
    fim[p] = true;
    if(tr[p].size()) return false;
    return true;
}

int main(){

    int t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        for(int i = 0; i < ptr; i++) tr[i].clear(), fim[i] = 0;
        ptr = 1;

        int n;
        scanf("%d", &n);

        bool can = true;
        for(int i = 0; i < n; i++){
            scanf(" %s", s);
            if(can) can &= insert();
        }
        printf("%s\n", can ? "YES" : "NO");
    }

    return 0;
}
