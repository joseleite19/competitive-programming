#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n, m, q;

int p[200005];

char s[100], t[100];

int f(int x){
	return (x == p[x] ? x : p[x] = f(p[x]));
}


int ptr;
map<string, int> vai;

int main(){

	scanf("%d %d %d", &n, &m, &q);

	for(int i = 0; i < n; i++){
		scanf(" %s", s);
		if(!vai.count(s))
			vai[s] = ptr++;
	}

	for(int i = 0; i < ptr+n; i++)
		p[i] = i;

	int x;
	for(int i = 0; i < m; i++){
		scanf("%d %s %s", &x, s, t);
		int u = vai[s], v = vai[t];
		int un = u+n, vn = v+n;
		if(x == 1){
			if(f(u) == f(vn) || f(un) == f(v)) printf("NO\n");
			else{
				printf("YES\n");
				p[ f(u) ] = f(v);
				p[ f(un) ] = f(vn);
			}
		}
		else{
			if(f(u) == f(v) || f(un) == f(vn)) printf("NO\n");
			else{
				printf("YES\n");
				p[ f(un) ] = f(v);
				p[ f(u) ] = f(vn);
			}
		}
	}

	for(int i = 0; i < q; i++){
		scanf(" %s %s", s, t);
		int u = vai[s], v = vai[t];
		int un = u+n, vn = v+n;

		if(f(u) == f(v) || f(un) == f(vn)) printf("1\n");
		else if(f(u) == f(vn) || f(un) == f(v)) printf("2\n");
		else printf("3\n");
	}



	return 0;
}