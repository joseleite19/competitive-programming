#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)

using namespace std;

typedef long long ll;
const int N = 400005;

char s[N];
int n;
int cnt[256];

int test(int k){
	int imp = 0;

	forn(i, 256) imp += (cnt[i] & 1);

	if(k < imp) return 0;
	if((k - imp) & 1) return 0;

	if(((n - k) / k)&1) return 0;

	return 1;
}

int main(){

	scanf("%d %s", &n, s);

	forn(i, n) cnt[ s[i] ]++;

	int tmp = 0;
	forn(i, 256) tmp += (cnt[i] & 1);
	if(tmp <= 1){
		printf("1\n");
		stack<char> s;
		forn(i, n/2){
			int j = 0;
			while(j < 256 && cnt[j] <= 1) j++;
			printf("%c", j);
			s.push(j);
			cnt[j] -= 2;
		}
		if(n & 1){
			int j = 0;
			while(j < 256 && cnt[j] % 2 == 0) j++;
			if(j == 256){
				j = 0;
				while(j < 256 && !cnt[j]) j++;
			}
			printf("%c", j);
		}
		while(!s.empty()) printf("%c", s.top()), s.pop();
		printf("\n");
		return 0;
	}

	vector<int> d;

	for(int i = 1; i*i <= n; i++) if(n % i == 0)
		d.push_back(i), d.push_back(n / i);
	
	sort(d.begin(), d.end());

	forn(i, d.size()){
		int k = d[i];
		if(test(k)){
			printf("%d\n", k);
			forn(w, k){
				int tam = n / k;
				stack<char> s;
				forn(i, tam / 2){
					int j = 0;
					while(j < 256 && cnt[j] <= 1) j++;
					s.push(j);
					printf("%c", j);
					cnt[j] -= 2;
				}
				if(tam & 1){
					int j = 0;
					while(j < 256 && cnt[j] % 2 == 0) j++;
					if(j == 256){
						j = 0;
						while(j < 256 && !cnt[j]) j++;
					}
					cnt[j]--;
					printf("%c", j);
				}

				while(!s.empty()) printf("%c", s.top()), s.pop();
				printf("%c", " \n"[w == k-1]);
			}


			return 0;
		}
	}


}

