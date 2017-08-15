#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

#define MAGIC 10000

using namespace std;



int a, b, l, r;

char s[24*MAGIC];

int main(){

    scanf("%d %d %d %d", &a, &b, &l, &r); l--; r--;

    for(int i = 0; i < a; i++) s[i] = i+'a';

    int id = a;
    for(int k = 0; k < MAGIC; k++){
        if(k & 1){
            set<char> ss;
            for(int i = 0; i < a; i++) ss.insert(s[id-i-1]);
            char c = 'a';
            for(int i = 0; i < a; i++){
                while(ss.count(c)) c++;
                s[id+i] = c++;
            }
            id += a;
        }
        else{
            for(int i = 0; i < b; i++) s[id+i] = s[id-1];
            id += b;
        }
    }
    s[id] = 0;
    s[703] = 0;
    printf("%s\n", s);

    set<char> ss;

    int start = l % id;

    ss.insert(s[start]);
    for(int i = l+1; i <= r && i % id != start; i++){
        ss.insert(s[i % id]);
    }

    printf("%d\n", int(ss.size()));



    return 0;
}
