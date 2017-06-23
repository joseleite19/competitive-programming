#include <bits/stdc++.h>

using namespace std;

char s[100005];

int main(){

    while(scanf(" %[^\n]", s) == 1 && s[0] != '*'){
        stringstream ss(s);
        string tmp;
        bool can = true;
        char obj = tolower(s[0]);

        while(ss >> tmp){
            if(tolower(tmp[0]) != obj) can = false;
        }
        printf("%s\n", can ? "Y" : "N");
    }




    return 0;
}
