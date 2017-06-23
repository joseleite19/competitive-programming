#include <bits/stdc++.h>

using namespace std;

char t[10];

int main(){
    set<string> s;

    for(int h = 0; h < 24; h++){
        string ss = to_string(h);
        if(ss.size() == 1) ss = '0' + ss;
        for(int m = 0; m < 60; m++){
            string sm = to_string(m);
            if(sm.size() == 1) sm = '0' + sm;
            string sn = ss+sm;
            string cp = sn;
            reverse(cp.begin(), cp.end());
            if(sn == cp) s.insert(sn);
        }
    }

    scanf("%c%c:%c%c", t, t+1, t+2, t+3);

    int ans = 0;
    set<string>::iterator it = s.lower_bound(t);
    for(int i = 0; i < 4; i++) t[i] -= '0';
    if(it == s.end()){
        it = s.begin();
        string ss = *it;
        ans = 1440;
        ans-= (t[0]*10 + t[1])*60 + (t[2]*10 + t[3]);
    }
    else{
        string ss = *it;
        for(int i = 0; i < 4; i++)
            ss[i] -= '0';
        ans = (ss[0]*10 + ss[1])*60 + (ss[2]*10 + ss[3]);
        ans-= (t[0]*10 + t[1])*60 + (t[2]*10 + t[3]);
    }

    printf("%d\n", ans);



}
