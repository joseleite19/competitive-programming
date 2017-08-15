#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, k;
long long x[1005], m[1005];

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%lld %lld", x+i, m+i);

    vector<pair<long long, long long> > neg, pos;
    for(int i = 0; i < n; i++)
        if(x[i] < 0) neg.push_back(mp(-x[i], m[i]));
        else if(x[i] > 0) pos.push_back(mp(x[i], m[i]));

    sort(neg.begin(), neg.end(), greater<pair<long long, long long> >());
    sort(pos.begin(), pos.end(), greater<pair<long long, long long> >());

    int ptr = 0;

    long long ans = 0, carry = k;

    for(int i = 0; i < neg.size(); i++){
        long long tmp = min(carry, neg[i].ss);
        carry -= tmp;
        neg[i].ss -= tmp;
        if(neg[i].ss){
           tmp = (neg[i].ss + k - 1) / k;
           ans += tmp * 2 * neg[i].ff;
           carry = tmp*k - neg[i].ss;
        }
    }

    carry = k;

    for(int i = 0; i < pos.size(); i++){
        long long tmp = min(carry, pos[i].ss);
        carry -= tmp;
        pos[i].ss -= tmp;
        if(pos[i].ss){
           tmp = (pos[i].ss + k - 1) / k;
           ans += tmp * 2 * pos[i].ff;
           carry = tmp*k - pos[i].ss;
        }
    }
    
    if(neg.size()) ans += 2*neg[0].ff;
    if(pos.size()) ans += 2*pos[0].ff;

    printf("%lld\n", ans);










}
