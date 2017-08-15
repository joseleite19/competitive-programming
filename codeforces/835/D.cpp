#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 5005;

bitset<N*N*20> dp2, mark2;
char s[N];
int n;
int ans[N];
unsigned long long hs[N], W[N], w;

inline bool f1(int i, int j){
    int mid = (j-i+1)/2;
    int start = j - mid+1;

    //printf("[%d %d] [%d %d]\n", i, i+mid-1, start, j);
    //printf("..%llu %llu\n", hs[j] - hs[start-1], W[2] * s[2]);
    //printf("..%llu\n", (hs[i+mid-1] - (i ? hs[i-1] : 0)) * W[start - i]);

    return (hs[j] - hs[start-1]) == (hs[i+ mid -1] - (i ? hs[i-1] : 0)) * W[start - i];
    return (hs[j] - hs[j-(j-i+1)/2]) == (hs[i+ (j-i+1)/2 -1] - (i ? hs[i-1] : 0)) * W[j - i + 1 - (j-i+1)/2];
}

int qwe;
long long all;
bool f3(int i, int j, int k){
    int idx = i*n*20 + j*20 + k;

    if(mark2[idx]) return dp2[idx];
    mark2[idx] = 1;

    if(k == 0){
        if(i == j) return dp2[idx] = 1;
        if(i+1==j) return dp2[idx] = (s[i] == s[j]);
        return dp2[idx] = (s[i] == s[j]) && f3(i+1, j-1, k);
    }

    qwe++;

    if(!f1(i, j)) return dp2[idx] = 0;
    int nj = (j-i+1)/2 + i - 1;
    if(i <= nj) return dp2[idx] = f3(i, nj, k-1);
    return dp2[idx] = 0;
}

int main(){

    scanf("%s", s);
    n = strlen(s);
    w = 1009;
    W[0] = 1;

    for(int i = 0; i < n; i++){
        hs[i] = W[i] * s[i] + (i ? hs[i-1] : 0);
        W[i+1] = W[i] * w;
    }


    for(int i = 0; i < n; i++) for(int j = i; j < n; j++)
        ans[0] += f3(i, j, 0);

    for(int k = 1; k < n; k++){    
        for(int i = 0; i < n; i++) for(int j = i; j < n; j++){
            int idx = i*n*20 + j*20 + k;
            mark2[idx] = 1;
            if(!f1(i, j)) dp2[idx] = 0;
            else{
                int nj = (j-i+1)/2 + i - 1;
                if(i <= nj){
                    dp2[idx] = f3(i, nj, k-1);
                    ans[k] += dp2[idx];
                }
                else dp2[idx] = 0;
            }
        }
        if(!ans[k]) break;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");


    return 0;
}

