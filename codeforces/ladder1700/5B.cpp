#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main(){

    vector<string> v;

    int sz = 0;
    while(scanf("%[^\n]", s) != EOF){
        v.push_back(s);
        sz = max(sz, int(strlen(s)));
        getchar();
        s[0] = 0;
    }

    for(int i = 0; i < sz+2; i++) printf("*");
    printf("\n");

    int b = 0;
    for(int i = 0; i < v.size(); i++){
        int left = sz - v[i].size(), l = 0, r = 0;
        if(left & 1){
            l = r = left / 2;
            if(b) l++;
            else r++;
            b ^= 1;
        }
        else l = r = left / 2;

        printf("*");
        for(int j = 0; j < l; j++) printf(" ");
        printf("%s", v[i].c_str());
        for(int j = 0; j < r; j++) printf(" ");
        printf("*\n");
    }


    for(int i = 0; i < sz+2; i++) printf("*");
    printf("\n");

    return 0;
}
