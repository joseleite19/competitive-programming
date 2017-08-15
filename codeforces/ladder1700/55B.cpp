#include <bits/stdc++.h>

using namespace std;

long long ans = 1e18;

char s[4];

void solve(int id, vector<long long> v){
    if(id == 3){
        ans = min(ans, v[0]);
        return;
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            vector<long long> tmp;
            for(int k = 0; k < v.size(); k++) if(k != i && k != j)
                tmp.push_back(v[k]);
            if(s[id] == '+') tmp.push_back(v[i] + v[j]);
            else tmp.push_back(v[i] * v[j]);
            solve(id+1, tmp);
        }
    }
}

int main(){
    vector<long long> v(4);

    for(int i = 0; i < 4; i++)
        scanf("%lld", &v[i]);

    for(int i = 0; i < 3; i++)
        scanf(" %c", s+i);

    solve(0, v);

    printf("%lld\n", ans);
}
