#include <bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define imprime(x, Y)                               \
	for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
cerr << endl;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;
const int N=1e5+10;
int n,k,x;
vi v[100];
int achamaior(int i){
	int ret=0;
	for(int j=0;j<n;j++) ret=max(ret,v[i][j]);
	return ret;
}
int achamenor(int i){
	int ret=INF;
	for(int j=0;j<n;j++) {
		ret=min(ret,v[i][j]);
	}
	return ret;
}
int main()
{
	sc3(n,k,x);
	for(int i=0;i<100;i++) v[i].resize(n);
	for(int i=0;i<n;i++) sc(v[0][i]);
	sort(v[0].begin(),v[0].end());

	for(int j=1;j<100;j++){
		
		for(int i=0;i<n;i++) v[j][i]=v[j-1][i]; 
		for(int i=0;i<n;i+=2) v[j][i]^=x;
		sort(v[j].begin(),v[j].end());
	}

	int menor=0;
	int cic=INF;
	for(int i=0;i<100;i++){
		for(int j=i+1;j<100;j++){
			if(v[i]==v[j]){
					if(cic>j-i+1){
					cic=(j-i);
					menor=j;
				}
			}
		}
	}
//	db(cic);
//	db(menor);
	if(k<menor){
		cout<<achamaior(k)<<" "<<achamenor(k)<<endl;
	}
	else{
		k-=menor;
		cout<<achamaior(k%cic+menor)<<" "<<achamenor(k%cic+menor)<<endl;
	}
	return 0;
}