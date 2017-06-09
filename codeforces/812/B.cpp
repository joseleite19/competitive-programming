#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

char mat[20][2203];
int n, m;
int last[20], first[20];
vector<int> pos[20];

int cnt = -1;
int f(int i, int lado){
    if(i >= cnt){
        if(lado){
            int tmp = last[i];
            if(last[i] == -1) tmp = 0;
            return tmp;
        }
        else{
            int tmp = (m+1) - first[i];
            if(first[i] == -1) tmp = 0;
            return tmp;
        }
        return 0;
    }

    int ans = 1000000000;
    if(lado){
        int tmp = last[i];
        tmp *= 2;
        if(last[i] == -1) tmp = 0;
        ans = min(m+1 + f(i+1, 0), tmp + f(i+1, 1));
    }
    else{
        int tmp = (m+1) - first[i];
        tmp *= 2;
        if(first[i] == -1) tmp = 0;
        ans = min(m+1 + f(i+1, 1), tmp + f(i+1, 0));
    }
    return ans;
}


int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf(" %s", mat[i]);

    memset(last, -1, sizeof last);
    memset(first, -1, sizeof first);


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m+2; j++) if(mat[i][j] == '1'){
            if(first[n-1 - i] == -1)
                first[n-1-i] = j;
        }
        for(int j = m+1; j >= 0; j--) if(mat[i][j] == '1')
            if(last[n-1-i] == -1)
                last[n-1-i] = j;
        if(last[n-1-i] != -1 && cnt == -1) cnt = n-1-i;
    }
    if(cnt < 0) cnt = 0;

    printf("%d\n", f(0, 1) + cnt);



    return 0;
}
