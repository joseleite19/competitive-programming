#include <cstdio>
#include <algorithm>
#include <set>

#define MAXV 10004
#define MAXE 1000003

int conjunto[MAXV], ranked[MAXV];

void make_set(int x){
	conjunto[x] = x;
 	ranked[x] = 0;
}

int find_set(int x){
	return (x == conjunto[x] ? x : conjunto[x] = find_set(conjunto[x]));
}

void union_set(int x, int y){
	int a = find_set(x),
	b = find_set(y);

	if(ranked[a] > ranked[b]) conjunto[b] = a;
	else{
		conjunto[a] = b;
		if(ranked[a] == ranked[b]) ranked[b]++;
	}
}

struct edge{
	int x, y, z;
	bool operator<(const edge & e) const{
		return z < e.z;
	}
};

int main(){
	int n, m, k;
	edge e[MAXE];

	scanf("%d", &n);
	m = 0;
	for(int i = 1; i < n; i++){
		make_set(i);
		scanf("%d", &k);
		for(int p = 0; p < k; p++){
			scanf("%d %d", &e[m].y, &e[m].z);
			e[m++].x = i;
		}
	}
	make_set(n);
	std::sort(e, e + m);
	long long mst = 0;
	int familia = n;
	for(int i = 0; i < m; i++){
		if(find_set(e[i].x) != find_set(e[i].y)){
			familia--;
			mst += e[i].z;
			union_set(e[i].x, e[i].y);
		}
	}

	printf("%d %lld\n", familia, mst);

	return 0;
}