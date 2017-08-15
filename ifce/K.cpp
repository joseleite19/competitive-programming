#include <bits/stdc++.h>

using namespace std;

const int N = 44;

int n;

long long m, v[N];


int main(){

    scanf("%d %lld", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    if(n == 1) return printf("%s\n", v[0] == m ? "sim" : "nao"), 0;

    for(int i = 0; i < n; i++) if(v[i] == m)
        return printf("sim\n"), 0;

    int lef = n/2;

    set<long long> s;

    for(int bit = 0; bit <= (1 << lef); bit++){
        long long sum = 0;
        bool cant = false;
        for(int i = 0; i < lef; i++){
            if(bit & (1 << i)){
                sum += v[i];
                if(sum > m){ cant = true; break; }
            }
        }
        if(cant) continue;
        s.insert(sum);
    }

    int rig = n - lef;

    bool ans = false;
    for(int bit = 0; bit <= (1 << rig); bit++){
        long long sum = 0;
        bool cant = false;

        for(int i = 0; i < rig; i++){
            if(bit & (1 << i)){
                sum += v[i+lef];
                if(sum > m){ cant = true; break; }
            }
        }
        if(cant) continue;
        if(s.count(m - sum)){ ans = true; break; }
    }

    printf("%s\n", ans ? "sim" : "nao");

}
