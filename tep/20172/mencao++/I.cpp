#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 100005;

vector<int> q, w;

int main(){

	int a, b;

	scanf("%d %d", &a, &b);

	for(int i = 1; i * i <= a; i++) if(a % i == 0){
		q.pb(i);
		if(i != a / i) q.pb(a / i);
	}

	for(int i = 1; i * i <= b; i++) if(b % i == 0){
		w.pb(i);
		if(i != b / i) w.pb(b / i);
	}

	sort(q.begin(), q.end()), sort(w.begin(), w.end());

	int n;

	scanf("%d", &n);

	while(n--){

		scanf("%d %d", &a, &b);
		size_t i = 0, j = 0;
		int ans = -1;
		while(i < q.size() && q[i] < a) i++;
		while(j < w.size() && w[j] < a) j++;
		while(i < q.size() && j < w.size() && q[i] <= b && w[j] <= b){
			if(q[i] < w[j]) i++;
			else if(q[i] > w[j]) j++;
			else ans = q[i], i++;
		}

		printf("%d\n", ans);
	}


    return 0;
}
