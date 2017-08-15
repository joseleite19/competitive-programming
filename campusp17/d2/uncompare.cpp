#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

const int N =100005;

char s[N];

int ans[N];

int main(){

    scanf("%s", s);
    int n = strlen(s)+1;

    ans[0] = 1;

    set<int> ss;
    for(int i = -n-1; i <= n+1; i++) ss.insert(i);

    ss.erase(1);
    for(int i = 0; i+1 < n; i++){
        if(s[i] == '<'){
            ans[i+1] = *ss.lower_bound(ans[i]+1);
        }
        else{
            ans[i+1] = *prev(ss.lower_bound(ans[i]));
        }
        ss.erase(ans[i+1]);
    }
    int mn = 1;

    for(int i = 0; i < n; i++)
        mn = min(mn, ans[i]);
    
    if(mn <= 0){
        for(int i = 0; i < n; i++)
            ans[i] = ans[i] - mn + 1;
    }

    printf("%d", ans[0]);

    for(int i = 1; i < n; i++)
        printf(" %d", ans[i]);
    printf("\n");


    return 0;
}
