#include <bits/stdc++.h>

using namespace std;
const int N = 200005;

int s[N], p[N];

int b[N];

int n, m;

void pf(){
    int j = -1;
    b[0] = -1;
    for(int i = 1; i <= m; i++){
        while(j >= 0 && p[i-1] != p[j]) j = b[j];
        j++;
        b[i] = j;
    }
}

int match(){
    int j = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(j >= 0 && s[i] != p[j]) j = b[j];
        j++;
        if(j == m){
            ans++; j = b[j];
        }
    }
    return ans;
}


int main(){

    scanf("%d %d", &n, &m);

    if(m == 1) return printf("%d\n", n), 0;

    for(int i = 0; i < n; i++)
        scanf("%d", s+i);

    for(int i = 0; i < m; i++)
        scanf("%d", p+i);

    for(int i = 0; i+1 < n; i++)
        s[i] = s[i+1] - s[i];
    n--;
    for(int i = 0; i+1 < m; i++)
        p[i] = p[i+1] - p[i];
    m--;

    pf();
    printf("%d\n", match());
    /*for(int i = 0; i < m; i++)
        printf("%d ", b[i]);
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", s[i]);
    printf("\n");
    for(int i = 0; i < m; i++)
        printf("%d ", p[i]);
    printf("\n");*/
}
