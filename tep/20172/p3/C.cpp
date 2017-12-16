#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define debug(x) cout << #x << " = " << x << endl
#define ford(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 100005;
double conta = 0;
double r, i, v, j;

bool f(int s){
	return r*(pow(i, s) - 1) / (i - 1) + 1e-7 >= v*pow(j, s);
}

int main(){
	int t;

	scanf("%d", &t);

	fore(tc, 1, t+1){
		conta = 0;
		scanf("%lf %lf %lf %lf", &r, &i, &v, &j);
		int L = 0, R = 3640;
		i = (100 + i) / 100;
		j = (100 - j) / 100;

		while(L+1 < R){
			int mid = (L+R)/2;
			if(f(mid)) R = mid;
			else L = mid+1;
		}
		if(!f(L)) L = R;

		/*while(ans <= 3640){
			ans++;
			conta = conta * i + r;
			v *= j;
			if(conta+1e-7 >= v) break;
		}*/
		printf("Caso #%d: ", tc);
		if(!f(L)) printf("nunca\n");
		else{
			int ans = L;
			if(ans >= 52){
				printf("%d %s", ans / 52, ans/52 == 1 ? "ano": "anos"), ans %= 52;
				if(ans) printf(" e %d %s", ans, ans == 1 ? "semana" : "semanas");
				printf("\n");
			}
			else{
				printf("%d %s\n", ans, ans == 1 ? "semana" : "semanas");
			}
		}
	}



    return 0;
}
