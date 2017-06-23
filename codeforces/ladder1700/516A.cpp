#include <bits/stdc++.h>

using namespace std;

vector<int> v[10] = {{}, {}, {2}, {3}, {3, 2, 2}, {5}, {5, 3}, {7}, {7, 2, 2, 2}, {7, 3, 3, 2}};

char s[20];
int main(){
    int n;

    scanf("%d %s", &n, s);

    multiset<int> ans;
    for(int i = 0; i < n; i++) if(s[i] >= '2'){
        for(int u : v[s[i]-'0'])
            ans.insert(u);
    }

    stack<int> tmp;
    for(int x : ans)
        tmp.push(x);

    while(!tmp.empty()) printf("%d", tmp.top()), tmp.pop();
    printf("\n");





    return 0;
}
