#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

short qt0[1003],qt1[1003];

int main(){
	file();
	//char v[1003][1003];
	vector<vector<bool> > v(1003, vector<bool>(1003, 0));
	short n, t[1003],qt02[1003],qt12[1003],t2[1003];
	scanf("%hd",&n);
	for(int i = 0; i < n; i++){
		short m;
		scanf("%hd",&m);
		for(int j = 0; j < m; j++){
			char s[3];
			scanf(" %s",s);
			if(s[0] == 'b'){
				v[i][j] = 0;
				if(j > 0){
					if(v[i][j - 1] == 0){
						m--;
						j--;
					}
					else qt0[i]++;
				}
				else qt0[i]++;
			} 
			else{
				v[i][j] = 1;
				if(j > 0){
					if(v[i][j - 1] == 1){
						m--;
						j--;
					}
					else qt1[i]++;
				}
				else qt1[i]++;
			} 
		}
		reverse(v[i].begin(),v[i].begin() + m);
		t[i] = m;
	//	printf("%d\n",t[i] );
	}
	int t0 = 0, t1 = 0,t12,t02;
	for(int i = 0; i < n; i++){
		t0 += qt0[i];	
		t1 += qt1[i];	
	}
	memcpy(qt02,qt0,sizeof(qt0)); 
	memcpy(qt12,qt1,sizeof(qt1)); 
	memcpy(t2,t,sizeof(t));
	t12 = t1; 
	t02 = t0; 
	bool da = true;
	if(n == 1 && v[0][t[0] - 1] == 1 && qt0[0] > 1){
		printf("-1\n");
		return 0;
	}
	if(n == 1 && v[0][t[0] - 1] == 0 && qt0[0] > 2){
		printf("-1\n");
		return 0;
	}
	int ans = 0; 	

	vector<short> vE;
	while(t0 > 0){
		while(1){
			int cnt = 0;
			for(int i = 0; i < n; i++){
				if(t[i]){
					if(v[i][t[i] - 1] == 1 && t[i] > 1) {
						vE.push_back(i);
						cnt++;
					}
				}
				else cnt++;
			}
			if(cnt == n || vE.empty()) break;
			// while(1){
			for(int i = 0; i < n; i++){
				if(t[i]){
					if(v[i][t[i] - 1] == 0){
						//printf("%d\n",i);
						if(vE.size()){
							int kk = vE[vE.size() - 1];
							vE.pop_back();
							ans++;
							t[kk] -= 2;
							qt0[kk]--;
							t0--;
							v[i][t[i]] = 1;
							t[i]++;
							qt1[i]++;
						}
					}
				}
			}
			vE.clear();
		}
		int  i,qq = 0;
		for(i = 0; i < n; i++){
			if(t[i]){
				if(v[i][t[i] - 1]){
					for(int j = i+1; j < n; j++){
						if(t[j]){
							if(v[j][t[j] - 1] == 1){
								ans++;
								t1--;
								qt1[j]--;
								t[j]--;
								qq++;
							}
			//			printf("%d\n",ans);
						}
					}
				break;
				}
			}
		}
		if(i == n || !qq){
			//printf("%d\n",ans);
			break;
		}
	}
	for(int i = 0; i < n; i++){
		while(t[i]){
			ans++;
			t[i]--;
		}
	}
	memcpy(qt0,qt02,sizeof(qt02)); 
	memcpy(qt1,qt12,sizeof(qt12)); 
	memcpy(t,t2,sizeof(t2));
	t1 = t12; 
	t0 = t02;
int ans2 = 0; 	
	for(int i = 0; i < n; i++){
		if(t[i]){
			if(v[i][t[i] - 1] == 0){
				//printf("%d\n",i);
				ans2++;
				t[i]--;
				qt0[i]--;
				t0--;
			}
		}
	}
	//printf("%d\n",ans2);
	int esp = -1;
	while(t0 > 0){
		for(int i = 0; i < n; i++){
			if(t[i]){
				if(qt0[i] > 0){
					if(qt0[i] == 1 && qt1[i] <= 2 && esp == -1 ){
						esp = i;
					}
					else if(esp != i){
						ans2 += 2;
						t[i] -= 2;
						qt1[i]--;
						qt0[i]--;
						t0--;
						t1--;
					}
					else{
						t[esp] -= 2;
						ans2++;
						t1--;
						t0--;
						qt0[esp]--;
						qt1[esp]--;
						esp = -1;
					}
				}
			}
			//printf("%d\n",t0 );
		}
	}
	//printf("%d %d %d %d\n",ans2,n, t[0], t[1]);
	for(int i = 0; i < n; i++){
		if(t[i]){
			//rintf("ad %d\n",ans2);
			ans2 = ans2+1;
			//printf("ad %d\n",ans2);
		}
		// if(qt0[i]){
		// 	printf("-1\n");
		// 	return 0;
		// }
	}
	printf("%d\n",min(ans,ans2));
	return 0;
}