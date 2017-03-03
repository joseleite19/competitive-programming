#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define mp make_pair

char t[100005], p[50004];

int main(){

    scanf("%s %s", t, p);

    int n = strlen(t);
    int m = strlen(p);

    for(int i = 0; i < n; i++)
        t[i+n] = t[i];

    map<int, int> c;

    c['a'] = c['A'] = 0;
    c['b'] = c['B'] = 1;
    c['c'] = c['C'] = 2;
    c['d'] = c['D'] = 3;
    c['e'] = c['E'] = 4;

    int ans = 1000000000;
    for(int start = 0; start < min(1000, n); start++){
        int id[] = {0, 1, 2, 3, 4};
        do{
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(c[ t[i+start] ] != id[ c[ p[i] ] ]){
                    cnt++;
                }
            }
            if(ans == 0) break;
            ans = min(ans, cnt);

        }while(next_permutation(id, id+5));
    }

    printf("%d\n", ans);

    return 0;
}