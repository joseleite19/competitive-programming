#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

const int N = 3005;
const int oo= 1000000000;

pair<int, int> v[N];

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d %d", &v[i].ff, &v[i].ss);

	sort(v, v+n);

	int ans = 0;
	for(int i = 0; i < n; i++){
        int ymn = -oo, ymx = oo;
        for(int j = i-1; j >= 0; j--){
            if(v[j].ss > v[i].ss){
                if(v[j].ss >= ymx)
                    continue;
                ans++;
                ymx = v[j].ss;
            }
            else{
                if(v[j].ss <= ymn)
                    continue;
                ans++;
                ymn = v[j].ss;
            }
        }
	}
	printf("%d\n", ans);

	return 0;
}
