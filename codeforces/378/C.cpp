#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	long long a[100005], b[100000], c[100000];
	int n, k, oldn;

	vector<pair<int, char> > ans;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", a+i);

	scanf("%d", &k);

	for(int i = 0; i < k; i++)
		scanf("%lld", b+i);

	bool possible = true;

	for(int i = 0; i < k && possible; i++){
		long long tmp = 0;
		int j;
		for(j = i; j < n && tmp < b[i]; j++)
			tmp += a[j];

		if(tmp != b[i]){
			possible = false;

			break;
		}

		for(int k = j - i; k > 1; k--){
			int q;
			long long hi = -1e18;
			long long low = 1e18;
			int idH = -1;
			int idL = -1;
			for(q = i; q < i+k; q++){
				if(a[q] < low){
					idL = q;
					low = a[q];
				}
				if(a[q] > hi){
					idH = q;
					hi = a[q];
				}
			}
			
			if(hi == low){
				possible = false;
				break;
			}

			for(q = i; q < i+k; q++){
				if(a[q] == hi){
					if(q > i && a[q] > a[q-1]){
						ans.push_back(mp(q+1, 'L'));
						a[q-1] += a[q];
						for(int w = q; w < n-1; w++)
							a[w] = a[w+1];
						n--;
						break;
					}
					else if(q < i+k-1 && a[q] > a[q+1]){
						ans.push_back(mp(q+1, 'R'));
						a[q] += a[q+1];
						for(int w = q+1; w < n-1; w++)
							a[w] = a[w+1];
						n--;
						break;
					}
				}
			}
			if(q == i+k){
				possible = false;
				break;
			}
		}

	}
	if(n != k) possible = false;

	if(!possible) printf("NO\n");
	else{
		printf("YES\n");
		for(int i = 0; i < (int)ans.size(); i++)
			printf("%d %c\n", ans[i].ff, ans[i].ss);
	}

}