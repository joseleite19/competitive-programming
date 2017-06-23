#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 1000006;

char s[N];
int n;

vector<int> pf(const string& s){
    vector<int> p(s.size()+1, 0);
    int j = -1;
    p[0] = -1;
    for(int i = 0; i < s.size(); i++){
        while(j >= 0 && s[i] != s[j]) j = p[j];
        p[i+1] = ++j;
    }
    return p;
}


int main(){

    scanf("%s", s);
    n = strlen(s);

    vector<int> p = pf(s);

    if(!p[n]) return printf("Just a legend\n"), 0;

    for(int i = 0; i < n; i++){
        if(p[i] == p[n]){
            s[i] = 0;
            printf("%s\n", s + i - p[i]); 
            return 0;
        }
    }

    if(!p[p[n]]) return printf("Just a legend\n"), 0;
    s[ p[n] ] = 0;
    printf("%s\n", s + p[n] - p[ p[n] ]);


    return 0;
}
