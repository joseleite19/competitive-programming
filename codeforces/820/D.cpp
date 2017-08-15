#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 1000006;

int n;

int p[N];

long long ans[N];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", p+i), p[i]--;

    int best = 0;

    for(int i = 0; i < n; i++) ans[0] += abs(p[i] - i);

    long long g = 0, l = 0, e = 0;
    long long szg = 0;
    for(int i = 0; i < n; i++){
        if(p[i] == i) e++;
        if(p[i] > i) g += p[i] - i;
        if(p[i] < i) l += i - p[i], szg++;
    }
    set<pair<long long, int> > le, ge, ee;
    for(int i = 0; i < n; i++){
        if(p[i] < i){
            le.insert(mp(p[i] - i, i));
        }
        if(p[i] > i)
            ge.insert(mp(i - p[i], i));
        if(p[i] == i)
            ee.insert(mp(0, i));
    }

    long long addl = 0, addg = 0;
    printf("%lld %lld %lld\n", l, e, g);
    for(int start = 1; start < n; start++){
        
        
        while(!ee.empty()){
            le.insert(mp(1 + addl, ee.begin()->ss));
            ee.erase(ee.begin());
        }

        while(!ge.empty() && ge.begin()->ff + addg == 1){
            ee.insert(mp(0, ge.begin()->ss));
            g -= ge.begin()->ff + addg;
            ge.erase(ge.begin());
        }

        if(p[start-1] == 0){ 
            g += n-1+addg;
            ee.erase(mp(0, start-1));
        }
        else if(p[start-1] == n-1){
            ee.insert(mp(0, start-1));
            l -= n-1;
            le.erase(mp(n-1-addl, start-1));
            //le.insert(mp(n-1+addl, start-1));
            //l += n-1+addl;
        }
        else{ // era g e agora vira l
            l -= n-1-p[start-1];
            szg--;
            le.insert(mp(p[start-1]+addl, start-1));
            g += p[start-1]+addl;
        }


        ans[n-start] = g - addl * le.size() + l;
   
        printf("%d %lld %lld %lld %lld\n", start, l, addl, le.size(), g);

        l += szg;
    }
    for(int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    printf("\n");



    return 0;
}
