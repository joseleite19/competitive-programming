#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 2005;

int mat[N][N];
int n;



int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    map<int, long long> s, d;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            s[i+j] += mat[i][j], d[i-j] += mat[i][j];
    
    pair<int, int> p, q;
    long long mx1 = -1, mx2 = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long x = s[i+j] + d[i-j] - mat[i][j];
            if((i+j) & 1){
                if(x > mx1) mx1 = x, p = mp(i, j);
            }
            else{
                if(x > mx2) mx2 = x, q = mp(i, j);
            }
        }
    }

    printf("%lld\n", mx1+mx2);

    printf("%d %d %d %d\n", p.ff+1, p.ss+1, q.ff+1, q.ss+1);


    return 0;
}
