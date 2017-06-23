#include <bits/stdc++.h>

using namespace std;

const int N = 5003;

char s[N][N];
int mark[N][N];

int cnt[N][N];

int n, m;

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf(" %s", s[i]); 
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '0') cnt[j][i] = 0;
            else cnt[j][i] = (j > 0 ? cnt[j-1][i] : 0)+1;
        } 
    }

    for(int j = 0; j < m; j++){
        sort(cnt[j], cnt[j]+n); reverse(cnt[j], cnt[j]+n);
        for(int i = 0; i < n; i++){
            ans = max(ans, cnt[j][i]*(i+1));
        }
    }

    printf("%d\n", ans);






    return 0;
}
