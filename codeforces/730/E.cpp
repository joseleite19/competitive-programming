#include <bits/stdc++.h>

#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;

const int N = 111;

int n;

int a[N], d[N], id[N];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d %d", a+i, d+i);

    for(int i = 0; i < n; i++)
        id[i] = i;

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(a[ id[i] ] < a[ id[j] ] || (a[ id[ i] ] == a[ id[j] ] && id[i] > id[j]))
                swap(id[i], id[j]);

    int ans = 0;
    for(int i = n-1; i >= 0; i--) if(d[ id[i] ] > 0){
        a[ id[i] ] += d[ id[i] ]; d[ id[i] ] = 0;
        int tmp = 0;
        int now = i;
        for(int j = i; j >= 0; j--){
            if(a[ id[j] ] < a[ id[now] ]){
                swap(id[now], id[j]);
                now = j;
                tmp++;
            }
            else if(a[ id[j] ] == a[ id[now] ] && id[j] > id[now]){
                swap(id[now], id[j]);
                now = j;
                tmp++;
            }
        }
        if(tmp){
            ans += tmp; i++;
        }
    }

    for(int i = 0; i < n; i++) if(d[ id[i] ] < 0){
        a[id[i]] += d[id[i]]; d[id[i]] = 0;
        int tmp = 0;
        int now = i;
        for(int j = i+1; j < n; j++){
            if(a[id[j]] > a[id[now]]){
                swap(id[now], id[j]);
                now = j;
                tmp++;
            }
            else if(a[ id[j] ] == a[ id[now] ] && id[j] < id[now]){
                swap(id[now], id[j]);
                now = j;
                tmp++; 
            }
        }
        if(tmp){
            ans += tmp; i--;
        }
    }

    printf("%d\n", ans);


    return 0;
}
