#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define mp make_pair

const int N = 50004;
const double PI = acos(-1);

char t[2*N], p[N];

struct cd{
    double r, i;
    cd(double r = 0, double i = 0) : r(r), i(i) {}

    cd operator*(const cd& o)const{ return cd(r*o.r - i*o.i, r*o.i + i*o.r); }
    cd operator+(const cd& o)const{ return cd(r+o.r, i+o.i); }
    cd operator-(const cd& o)const{ return cd(r-o.r, i-o.i); }
    void operator+=(const cd& o){ r += o.r, i += o.i; }
    void operator-=(const cd& o){ r -= o.r, i -= o.i; }
    void operator*=(const cd& o){
        double rr = r*o.r - i*o.i, ii = r*o.i + i*o.r;
        r = rr, i = ii;
    }
    void operator/=(const double o){ r /= o, i /= o; }
};

void fft(vector<cd>& v, bool inv = false){
    int n = v.size();

    for(int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        for(; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if(i < j) swap(v[i], v[j]);
    }

    for(int len = 2; len <= n; len <<= 1){
        double ang = 2*PI/len * (inv ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len){
            cd w(1);
            for(int j = 0; j < len/2; j++){
                cd x = v[i+j], y = v[i+j+len/2] * w;
                v[i+j] = x + y, v[i+j+len/2] = x - y;
                w *= wlen;
            }
        }
    }

    if(inv) for(int i = 0; i < n; i++)
        v[i] /= n;
}


vector<int> mult(vector<cd> a, vector<cd> b){
    int sz = 1;
    while(sz < a.size()) sz <<= 1;
    while(sz < b.size()) sz <<= 1;
    sz <<= 1;
    
    a.resize(sz);
    b.resize(sz);
    
    fft(a), fft(b);

    for(int i = 0; i < sz; i++)
        a[i] *= b[i];
    fft(a, 1);
    vector<int> ans(sz);

    for(int i = 0; i < sz; i++){
        ans[i] = int(a[i].r + 0.5);
    }
    return ans;
}

int main(){

    scanf("%s %s", t, p);

    int n = strlen(t);

    for(int i = 0; i < n; i++) t[i+n] = t[i];

    vector<cd> q[5];

    for(int l = 0; l < 5; l++){
        for(int i = 0; i < n; i++)
            q[l].push_back(cd(p[i] == 'a' + l));
        reverse(q[l].begin(), q[l].end());
    }

    vector<int> res[5][5];

    for(int l = 0; l < 5; l++){
        vector<cd> w;
        for(int i = 0; i < 2*n; i++)
            w.push_back(cd(t[i] == 'A' + l));
        for(int r = 0; r < 5; r++){
            res[l][r] = mult(w, q[r]);
        }
    }

    int ans = 1000000000;
    int id[] = {0, 1, 2, 3, 4};
    do{
        int cnt = 1000000000;
        for(int i = n-1; i < 2*n; i++){
            int t = 0;
            for(int l = 0; l < 5; l++)
                t += res[l][ id[l] ][i];
            cnt = min(cnt, n - t);
        }
        ans = min(ans, cnt);
    }while(next_permutation(id, id+5));

    printf("%d\n", ans);

    return 0;
}
