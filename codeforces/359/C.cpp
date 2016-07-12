#include <bits/stdc++.h>

using namespace std;

vector<int> v1, v2;
int countDigits(int n, vector<int> &v){
	int ans = 0;
	for(ans = 0; n; n /= 7, ans++){
		v.push_back(n % 7);
	}
	return ans;
}

int sig(int n){
	while(n >= 7)
		n /= 7;
	return n;
}

int fat(int n){
	if(n == 0) return 1;
	return n*fat(n-1);
}

int a, b, c, d, e, f, ans;
bool used[7];
set<int> s;
int bc(int n, int num, bool first = 0, bool second = 0){
	if(n == a + b){
		ans++;
		s.insert(num);
	}
	else{
		int limit = 0;
		if(n == 0){
			// printf("das %d\n", c);
			for(int i = 0; i < c; i++){
				if(!used[i]){
					used[i] = 1;
					bc(n+1, 10*num + i);
					used[i] = 0;
				}
			}
			if(!used[c]){
				used[c] = 1;
				bc(n+1, 10*num + c, 1);
				used[c] = 0;
			}
		}
		else if(n < a && first){
			for(int i = 0; i < v1[n]; i++){
				if(!used[i]){
					used[i] = 1;
					bc(n+1, 10*num + i, 0, 0);
					used[i] = 0;
				}
			}
			if(!used[ v1[n] ]){
				used[ v1[n] ] = 1;
				bc(n+1, 10*num +  v1[n] , 1, 0);
				used[ v1[n] ] = 0;
			}
		}
		else if(n == a){
			for(int i = 0; i < d; i++){
				if(!used[i]){
					used[i] = 1;
					bc(n+1, 10*num + i);
					used[i] = 0;
				}
			}
			if(!used[d]){
				used[d] = 1;
				bc(n+1, 10*num + d, first, 1);
				used[d] = 0;
			}

		}
		else if(n > a && second){
			for(int i = 0; i < v2[n-a]; i++){
				if(!used[i]){
					used[i] = 1;
					bc(n+1, 10*num + i);
					used[i] = 0;
				}
			}
			if(!used[ v2[n-a] ]){
				used[ v2[n-a] ] = 1;
				bc(n+1, 10*num +  v2[n-a], first, 1);
				used[ v2[n-a] ] = 0;
			}
		}
		else{
			for(int i = 0; i < 7; i++){
				if(!used[i]){
					used[i] = 1;
					bc(n+1, 10*num + i);
					used[i] = 0;
				}
			}
		}
	}
}

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	a = countDigits(n-1, v1), b = countDigits(m-1, v2), c = sig(n-1), d = sig(m-1);
	e = (n-1)%7, f = (m-1)%7;
	int numbers[] = {0, 1, 2, 3, 4, 5, 6};
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());

	if(a + b > 7) printf("0\n");
	else{
		// int ans = 0;
		// while(next_permutation(numbers, numbers + 7)){
		// 	if(numbers[0] > c) continue;
		// 	if(numbers[a] > d) continue;
		// 	ans++;
		// }

		memset(used, 0, sizeof used);
		ans = 0;
		if(!a) a = 1;
		if(!b) b = 1;
		// printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
		bc(0, 0, 0, 0);
		// for(int i : s)
		// 	printf("%d\n", i);
		printf("%d\n", ans);
	}

	return 0;
}