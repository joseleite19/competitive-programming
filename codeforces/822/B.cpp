#include <bits/stdc++.h>

using namespace std;

int n, m;

char s[1005], t[1005];

int main(){

    scanf("%d %d %s %s", &n, &m, s, t);

    vector<int> ans;
    for(int i = 0; i < n+m; i++) ans.push_back(i);
    for(int i = 0; i <= m - n; i++){
        vector<int> tmp;
        for(int j = 0; j < n; j++){
            if(s[j] != t[i+j])
                tmp.push_back(j+1);
        }
        if(tmp.size() < ans.size()) ans = tmp;
    }

    printf("%d\n", ans.size());

    for(int x : ans) printf(" %d", x);

    printf("\n");


    return 0;
}
