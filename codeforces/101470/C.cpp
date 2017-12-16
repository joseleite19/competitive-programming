#include <bits/stdc++.h>

using namespace std;

void file(){
    freopen("a.in", "r", stdin);
}

int n, m, r, k, p;

int main(){
    //file();

    scanf("%d %d %d %d %d", &n, &m, &r, &k, &p);

    vector<vector<int> > mat(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    int a, b;
    char c;
    while(k--){
        scanf(" %c %d %d", &c, &a, &b);


    
    }


    
    return 0;
}
