	#include <bits/stdc++.h>

	#define ff first
	#define ss second
	#define mp make_pair
	#define pb push_back

	using namespace std;

	long long w[200005], c[200005];

	char s[200005];

	void file(){
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	long long sum[200005];
	long long sumc[200005];

	int main(){
		// file();
		int n, m, k;

		scanf("%d %d %d", &n, &m, &k);
		for(int i = 0; i < n; i++)
			scanf("%lld %lld", w+i, c+i);

		sum[0] = w[0];
		sumc[0] = c[0];
		for(int i = 1; i < n; i++){
			sum[i] = sum[i-1] + w[i];
			sumc[i] = sumc[i-1] + c[i];
		}

		// for(int i = 0; i < n; i++)
		// 	printf("%3lld ", c[i]);
		// printf("\n");

		// for(int i = 0; i < n; i++)
		// 	printf("%3lld ", sumc[i]);
		// printf("\n");

		// for(int i = 0; i < n; i++)
		// 	printf("%3lld ", sum[i]);
		// printf("\n");

		// for(int i = 0; i < n; i++)
		// 	printf("%3d ", i);
		// printf("\n");

		long long mx = 0;
		long long l1 = -1, r1 = n;

		for(int r = n-1; r >= m; r--){
			if(sum[r] - sum[r-m] > sum[r-m]*k) break;
			
			long long hi = r-m, lo = 0, id = -1;

			while(lo <= hi){
				int mid = (lo + hi) / 2;
				if(sum[r] - sum[r-m] <= (sum[r-m] - sum[mid])*k){
					lo = mid+1;
					id = mid;
				}
				else hi = mid-1;
			}

			long long tmp = (id != -1 ? sumc[id] : 0) + sumc[n-1] - sumc[r];

			if(tmp > mx){
				mx = tmp;
				l1 = id;
				r1 = r;
			}
		}
		if(l1 == -1){
			printf("0 0\n");
			return 0;
		}

		printf("%lld %lld\n", l1+1 + n-r1-1, mx);

		for(int i = r1+1; i < n; i++)
			printf("H");

		for(int i = 0; i <= l1; i++)
			printf("T");
		printf("\n");

		return 0;
	}