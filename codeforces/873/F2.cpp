#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int MAX = 2e5 + 5;
int N;
char T[MAX], cant[MAX];
int sa[MAX], tsa[MAX], ra[MAX], tra[MAX];
int lcp[MAX], plcp[MAX], phi[MAX], c[MAX];

void sort(int k) {
    memset(c, 0, sizeof c);
    fori(i, 0, N) {
        c[i + k < N ? ra[i + k] : 0]++; 
    }
    int sum = 0, maxi = max(300, N);
    fori(i, 0, maxi) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    fori(i, 0, N) {
        int cur = sa[i] + k < N ? ra[sa[i] + k] : 0; 
        tsa[c[cur]++] = sa[i];
    }
    memcpy(sa, tsa, sizeof(int) * N);
}

void build_sa() {
    fori(i, 0, N) {
        ra[i] = T[i];
        sa[i] = i;
    }
    for(int k = 1; k < N; k *= 2) {
        sort(k);
        sort(0);
        int r = tra[sa[0]] = 0;
        fori(i, 1, N) {
            if(ra[sa[i]] == ra[sa[i - 1]]) {
                int cur = (sa[i] + k) < N ? ra[sa[i] + k] : 0;
                int prev = (sa[i - 1] + k) < N ? ra[sa[i - 1] + k] : 0;
                if(cur == prev) {
                    tra[sa[i]] = r;
                }
                else {
                    tra[sa[i]] = ++r;
                }
            }
            else {
                tra[sa[i]] = ++r;
            }
        }
        if(tra[sa[N - 1]] == N - 1) {
            break;
        }
        memcpy(ra, tra, sizeof(int) * N);
    }
}

void build_lcp() {
    phi[sa[0]] = -1;
    fori(i, 1, N) {
        phi[sa[i]] = sa[i - 1];
    }
    int l = 0;
    fori(i, 0, N) {
        if(phi[i] == -1) {
            plcp[i] = 0;
            continue;
        }
        while(T[i + l] == T[phi[i] + l]) {
            l++;
        }
        plcp[i] = l;
        l = max(l - 1, 0);
    }
    fori(i, 0, N) {
        lcp[i] = plcp[sa[i]];
    }
}

int pref[MAX];
int lft[MAX], rgt[MAX];

int main() {
    scanf("%d", &N);
    scanf("%s", T);
    scanf("%s", cant);
    reverse(T, T + N);
    reverse(cant, cant + N);

    T[N++] = '$';
    build_sa();
    build_lcp();

    fori(i, 1, N) {
        pref[i] = pref[i - 1];
        if(cant[sa[i]] == '1') {
            pref[i]--;
        }
    }

    vector<ii> stac {{-1, 0}};
    fori(i, 1, N) {
        while(stac.back().first >= lcp[i]) {
            stac.pop_back();
        }
        lft[i] = stac.back().second;
        stac.emplace_back(lcp[i], i);
    }
    stac.clear();
    stac.emplace_back(-1, N);
    ford(i, N - 1, 1) {
        while(stac.back().first >= lcp[i]) {
            stac.pop_back();
        }
        rgt[i] = stac.back().second;
        stac.emplace_back(lcp[i], i);
    }

    ll ans = 0;
    fori(i, 0, N) {
        if(cant[i] == '0') {
            ans = max<ll>(ans, N - i - 1);
        }
    }
    fori(i, 1, N) {
        int left = max(1, lft[i]);
        int right = rgt[i] - 1;
        printf("%d %d [%d %d] %d %d %d\n", i, lcp[i], left, right, lft[i], rgt[i]-1, sa[i]);
        ans = max(ans, 1LL * lcp[i] * ((right - left + 1) + (pref[right] - pref[left - 1])));
    }
    
    printf("%lld\n", ans);

    return 0;
}
