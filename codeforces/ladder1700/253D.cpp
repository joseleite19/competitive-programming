#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 404;

int n, m, k;
char mat[N][N];
int s[N][N];
int tmp[26][N][N];

int l[N];

int sum(int a, int b, int c, int d){
    return s[c][d] - s[c][b-1] - s[a-1][d] + s[a-1][b-1];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++)
        scanf(" %s", mat[i]+1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            s[i][j] = (mat[i][j] == 'a');
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int c = mat[i][j] - 'a';
            if(l[c] != i){

                int e = 0;
                for(int k = j; k <= m; k++){
                    if(mat[i][k] == c+'a'){
                        for(int q = i; q <= n; q++){
                            tmp[c][q][k] = (mat[q][k] == c + 'a') + tmp[c][q][e];
                        }
                        e = k;
                    }
                }
                l[c] = i;
            }

            int w = m;
            for(int q = i+1; q <= n; q++) if(mat[q][j] == c + 'a'){
                while((w > j && sum(i, j, q, w) > k) || mat[i][w] != c + 'a') w--;
                if(w <= j) break;
                ans += tmp[c][q][w] - tmp[c][q][j];
            }
        }
    }


    printf("%lld\n", ans);


    return 0;
}
