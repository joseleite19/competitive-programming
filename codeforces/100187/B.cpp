#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const ll oo = 1000000000000000000;
const int N = 400005;

char s[N];
int v[26], n;

// cnt * q * q! / n!
double f(int x){
    double ans = x;
    for(int i = 1; i <= x; i++)
        ans *= 1.0*i / (n - i + 1);
    return ans;
}

int main(){

    scanf("%s", s);

    n = strlen(s);

    for(int i = 0; i < n; i++)
        v[ s[i] -'a' ]++;

    map<int, int> cnt;
    double ans = 0;
    for(int i = 0; i < 26; i++) if(v[i]){
        //cnt[ v[i] ]++;
        ans += 1.0*v[i]*v[i]/n;
        //printf("%d %d\n", v[i], n);
        //printf("%lf %lf\n", ans, f(v[i]));
    }

    for(pair<int, int> x : cnt){
        //ans += f(x.ss, x.ff);
    }
    // sum( cnt[i] * i * i! ) / n!

    printf("%.20lf\n", ans);

    return 0;
}
