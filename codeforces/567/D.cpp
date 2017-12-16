#include <bits/stdc++.h>

using namespace std;

int seg[800008];

void update(int p, int l, int r, int i, int v){
	if(i == l && i == r){
		seg[p] = v;
		return;
	}
	int mid = (l + r) / 2;
	if(i <= mid) update(2*p, l, mid, i, v);
	else update(2*p+1, mid+1, r, i, v);
	seg[p] = seg[2*p] + seg[2*p+1];
}

int queryL(int p, int l, int r, int i){
	if(seg[p] == (r - l + 1)) return -1;
	if(l >= i) return -1;
	if(l == r && seg[p] == 0) return l;

	int mid = (l + r) / 2;
	int ret = queryL(2*p+1, mid+1, r, i);
	if(ret == -1)
		ret = queryL(2*p, l, mid, i);
	return ret;
}
int queryR(int p, int l, int r, int i){
	if(seg[p] == (r - l + 1)) return -1;
	if(r <= i) return -1;
	if(l == r && seg[p] == 0) return l;

	int mid = (l + r) / 2;
	int ret = queryR(2*p, l, mid, i);
	if(ret == -1)
		ret = queryR(2*p+1, mid+1, r, i);
	return ret;
}


int main(){
	int n, k, a, m, x[200005], possible;

	scanf("%d %d %d %d", &n, &k, &a, &m);

	for(int i = 1; i <= n; i++)
		update(1, 1, n, i, 1);

	for(int i = 0; i < m; i++)
		scanf("%d", x + i);

	int index = -1;
	possible = (n+1)/(a+1);
	for(int i = 0; i < m; i++){
		update(1, 1, n, x[i], 0);
		int l = queryL(1, 1, n, x[i]);
		int r = queryR(1, 1, n, x[i]);
		if(l == -1) l = 1;
		else l++;
		if(r == -1) r = n;
		else r--;

		possible += (x[i] - l + 1)/(a+1) + (r - x[i] + 1)/(a+1) - (r - l + 2) / (a + 1);
		if(possible < k){
			index = i+1;
			break;
		}

	}
	printf("%d\n", index);


	return 0;
}