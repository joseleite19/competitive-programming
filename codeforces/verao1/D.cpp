#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int n, m;
int ans[105];
int l[105];
int r[105];

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        l[i] = 1, r[i] = m;

    for(int qwe = 0; qwe < 10; qwe++){
        printf("?");
        for(int i = 0; i < n; i++)
            printf(" %d", (l[i] + r[i])/ 2);
        printf("\n");
        fflush(stdout);
        long long x;

        for(int i = 0; i < n; i++){
            scanf("%lld", &x);
            if(x > 0) r[i] = ((l[i] + r[i])/ 2);
            else if(x < 0) l[i] = ((l[i] + r[i])/ 2) + 1;
            else{
                x = (l[i] + r[i])/ 2;
                r[i] = l[i] = x;
                ans[i] = x;
            }
        }
    }

    printf("A ");
    for(int i = 0; i < n; i++)
        printf(" %d", ans[i] == 0 ? (l[i] + r[i])/ 2 : ans[i]);
    printf("\n");

    fflush(stdout);

    return 0;
}
