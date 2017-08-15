#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
#define pb push_back

using namespace std;

char s[1000];

int main(){
    long long a, b;

    long long last = 0;
    double delta = 0;
    double speed = 0;
    while(scanf(" %[^\n]", s) == 1){
        int a, b, c, d;

        int x = sscanf(s, "%d:%d:%d %d", &a, &b, &c, &d);
        if(x == 4){
            delta += speed * (a * 3600LL + b*60L + c - last);
            last = a * 3600LL + b * 60LL + c;
            speed = d/3600.0;
        }
        else{
            long long tmp = a * 3600LL + b * 60LL + c;
            printf("%s %.2lf km\n", s, speed*(tmp - last) + delta);
        }
        //printf("%d\n", x);
    }

    return 0;
}
