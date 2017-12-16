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

int n;
int v[50];
int mem[50][2];
bool set_[50][2];
int ans(int cur,bool inc){
	if(cur == n-1)return 1;
	if(cur >= n)return 0;
	if(set_[cur][inc])return mem[cur][inc];
	int a = ans(cur+1,inc);
	if(inc){
		if(v[cur] < v[cur+1])a = max(a,ans(cur+1,!inc) + 1);
	}
	else{
		if(v[cur] > v[cur+1])a = max(a,ans(cur+1,!inc) + 1);
	}
	set_[cur][inc] = true;
	return mem[cur][inc] = a;
}

int main(){
	cin >> n;
	forn(i,n)cin >> v[i];
	cout << max(ans(0,true),ans(0,false)) << endl;
}
