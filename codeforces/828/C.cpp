#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 2000006;

int n;
char ans[N], s[N];

int main(){

    scanf("%d", &n);

    set<int> free;

    for(int i = 0; i < N; i++) free.insert(i);

    for(int i = 0; i < n; i++){
        int k;
        scanf(" %s %d", s, &k);
        int t;
        int sz = strlen(s);
        for(int j = 0; j < k; j++){
            scanf("%d", &t);
            int q = *free.lower_bound(t);
            for(q = *free.lower_bound(t); q < t+sz; q = *free.upper_bound(q)){
                free.erase(q);
                ans[q] = s[q-t];
            }
        }
    }
    int sz = 0;
    for(int i = 0; i < N; i++) if(ans[i])
        sz = i+1;
    for(int i = 0; i < sz; i++) if(!ans[i])
        ans[i] = 'a';

    printf("%s\n", ans+1);

    return 0;
}
