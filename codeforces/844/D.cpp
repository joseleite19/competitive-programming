#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int limit = 2000;
int n, start, x;

int rd(){
    return (rand() << 15) ^ rand();
}

pair<int, int> query(int x){
    assert(x >= 1);
    assert(x <= n);
    printf("? %d\n", x); fflush(stdout);
    pair<int, int> q;
    scanf("%d %d", &q.ff, &q.ss);
    return q;
}

void easy(){
    while(start != -1){
        limit--;
        pair<int, int> q = query(start);
        if(q.ff >= x){
            printf("! %d\n", q.ff); fflush(stdout);
            return;
        }
        start = q.ss;
    }
    printf("! -1\n"); fflush(stdout);
}

const int N = 500005;
int ft[N];

void add(int x, int v){
    for(; x < N; x += x & -x)
        ft[x] += v;
}

int sum(int x){
    int ans = 0;
    for(; x; x -= x & -x)
        ans += ft[x];
    return ans;
}

int findk(int k){
    int lo = 1, hi = n;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        int tmp = sum(mid);
        if(tmp < k) lo = mid+1;
        else if(tmp > k) hi = mid-1;
        else hi = mid;
    }
    if(sum(lo) < k) lo = hi;
    if(sum(lo) !=k) assert(0);
    return lo;
}

int v[N];

int main(){
    srand(time(0));
    unsigned int a, b;
    for(int i = 0; i < rd(); i++){
        a = rd();
        b = (a ^ b) + (1 << a);
    }

    srand(b);
   
    for(int i = 1; i < N; i++)
        add(i, 1);

    scanf("%d %d %d", &n, &start, &x);
    
    if(n <= limit) return easy(), 0;

    for(int i = 0; i < n; i++)
        v[i] = i+1;

    random_shuffle(v, v+n);


    set<int> sss;

    int mx = query(start).ff;
    int sz = n;
    int x = 0;
    for(int i = 0; i < 999; i++){
        limit--;
        //x = (rd() % sz) + 1;
        //sz--;

        //x = findk(x);
        x = v[i];
        //assert(!sss.count(x));
        //sss.insert(x);
        
        //add(x, -1);

        pair<int, int> q = query(x);
        if(q.ff <= x){
            if(q.ff == x){
                printf("! %d\n", x); fflush(stdout);
                return 0;
            }
            if(q.ff > mx){
                mx = q.ff, start = q.ss;
                if(x - mx + 1 < limit)
                    break;
            }
        }
    }

    easy();

    return 0;
}
