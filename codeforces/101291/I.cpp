#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

map<int,int> ms;

int main(){
	int n,x,ans=0;
	cin >> n;
	forn(i,n){
		cin >> x;
		ms[x]++;
	}
	ms.insert(0);
	while(ms.size() > 2){
		ii a = *ms.rbegin();

		ii b = *next(ms.rbegin());

		ii c = *next(next(ms.rbegin()));


	}
    
}