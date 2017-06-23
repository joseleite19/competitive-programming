#include <bits/stdc++.h>

using namespace std;

const int N = 10004;


int n;
int p[N], v[N];
int vis[N], mark[N], pass;;
int s, c;

bool f(int x){
    if(!vis[x]) return false;
    if(x == p[x]) return true;
    if(mark[x] == pass) return true;
    mark[x] = pass;
    return f(p[x]);
}

int main(){

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", p+i);

    scanf("%d %d", &s, &c);

    while(s--){
        for(int i = 0; i < c; i++)
            scanf("%d", v+i);

        for(int i = 0; i < c; i++)
            vis[ v[i] ] = 1;

        bool can = true;
        pass++;
        for(int i = 0; i < c; i++)
            if(!f(v[i]))
                can = false;
        for(int i = 0; i < c; i++)
            vis[ v[i] ] = 0;
        printf("%s\n", can ? "yes" : "no");
    }


    return 0;
}
