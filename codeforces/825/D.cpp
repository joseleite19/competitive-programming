#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 1000006;

char s[N];
char t[N];
int n, m;

int p[N];

void pf(){

    for(int i = 2; i <= m; i++){
        p[i] = p[i-1];
        while(p[i] > 0 && t[ p[i] ] != t[i-1]) p[i] = p[ p[i] ];
        if(t[ p[i] ] == t[i-1]) p[i]++;
    }
    p[m+1] = 0;
}

pair<int, int> mx[N];

void match(){

    int j = 0;
    for(int i = 0; i < n; i++){
        while(j > 0){
            if(s[i] == t[j] || s[i] == '?') break;
            j = p[j];
        }
        if(s[i] == t[j] || s[i] == '?') j++;

        if(j == m){
            j = p[j];
            pair<int, int> tmp = mx[n-m];
            tmp.ff++; tmp.ss = i;
            mx[i] = tmp;
        }
        if(i) mx[i] = max(mx[i], mx[i-1]);
    }
}

int v[300];
int c[300];
int imp[300];

int main(){

    scanf("%s %s", s, t);
    n = strlen(s);
    m = strlen(t);

    for(int i = 0; i < m; i++)
        v[ t[i] ]++;

    int space = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != '?')
            c[ s[i] ]++;
        else space++;
    }

    int mn = 1000000000;

    for(int i = 'a'; i <= 'z'; i++) if(v[i]){
        mn = min(mn, c[i] / v[i]);
    }

    for(int i = 'a'; i <= 'z'; i++) if(v[i]){
        c[i] -= v[i]*mn;
    }

    while(1){
        bool can = true;
        for(int i = 'a'; i <= 'z'; i++) if(v[i]){
            if(c[i] >= v[i]){
                c[i] -= v[i];
            }
            else{
                if(space >= v[i] - c[i]){
                    space -= v[i] - c[i];
                    imp[i] += v[i] - c[i];
                    c[i] = 0;
                }
                else can = false;
            }
        }
        if(!can) break;
    }


    int j = 'a';
    for(int i = 0; i < n; i++) if(s[i] == '?'){
        while(j <= 'z' && imp[j] == 0) j++;
        if(j > 'z') s[i] = 'a';
        else s[i] = j, imp[j]--;
    }

    printf("%s\n", s);


    return 0;
}
