#include <bits/stdc++.h>

#define ff first
#define ss second

#define MOD (1000000007)

using namespace std;

const int N = 200005;

char s[N];

long long v[N];

unsigned long long h[N];
int tam[N];

unsigned long long w = 27;

unsigned long long W[N];
map<int, multiset<unsigned long long> > sz;

int tt;

bool f(){
    for(map<int, multiset<unsigned long long> >::iterator it = sz.begin(); it != sz.end(); it++){
        if(it->ff > tt) break;
        unsigned long long tmp = 0;
        int win = it->ff;
        for(int i = 0; i < win; i++)
            tmp = tmp * w + v[i];
        if(it->ss.count(tmp)) return true;
        
        for(int i = win; i < tt; i++){
            // tira i - win coloca i
            tmp = tmp - v[i-win] * W[win-1];
            tmp = tmp * w + v[i];
            if(it->ss.count(tmp)) return true;
        }
    }

    return false;
}

int main(){

    W[0] = 1;
    for(int i = 1; i < N; i++)
        W[i] = W[i-1] * w;

    int n, q;

    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++){
        scanf(" %s", s);
        unsigned long long tmp = 0;
        for(int j = 0; s[j]; j++) tmp = tmp * w + s[j]-'a'+1;
        h[i] = tmp;
        tam[i] = strlen(s);
        sz[ tam[i] ].insert(h[i]);
    }

    int t;
    int last = 0;
    for(int tc = 0; tc < q; tc++){
        scanf("%d", &t);

        if(t == 1){
            scanf(" %s", s);
            tt = strlen(s);

            for(int i = 0; i < tt; i++)
                v[i] = (s[i] - 'a' + last) % 26 + 1;

            if(f()) printf("YES\n"), last = tc;
            else printf("NO\n");
        }
        else{
            int i, a;
            scanf("%d %d", &i, &a);
            i = (i + last) % n;
            a = (a + last) % 26; a++;
            map<int, multiset<unsigned long long> >::iterator it = sz.find(tam[i]);

            it->ss.erase(it->ss.find(h[i]));
            if(it->ss.size() == 0) sz.erase(it);
            tam[i]++;
            h[i] = h[i]*w+a;
            sz[ tam[i] ].insert(h[i]);
        }
    }

    return 0;
}
