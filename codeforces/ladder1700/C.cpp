#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int l[1003], r[1003];

int v[1003], n, m, cnt[1003];

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d %*d.%*d", v+i);

	for(int i = 1; i <= n; i++){
		cnt[ v[i] ]++;
		// r[ v[i] ] = i;
		// if(!l[ v[i] ])
		// 	l[ v[i] ] = i;
	}

	int ans = 0;
	int last = 1;
	memset(l, -1, sizeof l);
	for(int i = 1; i <= m; i++){
		if(!cnt[i]) continue;
		l[i] = r[i] = 0;
		cnt[i] = 0;
		int off = 0;
		int off2 = 0;
		for(int j = last; j <= n; j++){
			cnt[ v[j] ]++;
			if(v[j] < i) off++;
			r[ v[j] ] = j;
			if(!l[ v[j] ])
				l[ v[j] ] = j;
		}
		if(!cnt[i]) continue;
		
		int tmp = last;
		off = 0;
		int tmp2 = 0;
		int tmp3 = 0;
		for(int q = l[i]; q <= r[i]; q++){
			if(v[q] < i) off++;
			else if(v[q] != i){
				tmp2 += q - tmp - off;
				tmp = q;
				off = 0;
				while(q <= r[i] && v[q] != i){
					if(v[q] < i) off++;
					q++;
				}
				q--;
			}
		}
		tmp2 += r[i]+1 - tmp;

		// int tmp = l[i] - last - off2;
		// int tmp2 = r[i] - l[i] - off + 1 - cnt[i];
		if(tmp2 < cnt[i]){
			ans += tmp2;
			last = r[i]+1;
		}
		else{
			ans += cnt[i];
		}
		printf("%d %d %d %d %d %d %d %d\n", i, tmp, tmp2, off2, l[i], r[i], cnt[i], ans);
	}

	printf("%d\n", ans);



	return 0;
}