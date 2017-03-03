#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}


int main(){
	file();
	map<string,int> m;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		vector<string> v;
		while(x--){
			char s[20];
			scanf("%s",s);
			v.pb(s);
		}
		sort(v.begin(),v.end());
		for(int j = 0; j < v.size(); j++)
			m[v[j]]++;
		if(v.size() > 1){
			for(int j = 0; j < v.size(); j++){
				for(int k = j+1; k < v.size(); k++)
					m[v[j] + '#' + v[k]]++;
			}
			if(v.size() > 2){
				for(int j = 0; j < v.size(); j++){
					for(int k = j+1; k < v.size(); k++)
						for(int l = k+1; l < v.size(); l++)
							m[v[j] + '#' + v[k] + '#' + v[l]]++;
				}
				if(v.size() > 3){
					for(int j = 0; j < v.size(); j++){
						for(int k = j+1; k < v.size(); k++)
							for(int l = k+1; l < v.size(); l++)
								for(int o = l+1; o < v.size(); o++)
									m[v[j] + '#' + v[k] + '#' + v[l] + '#' + v[o]]++;
					}	
				}
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		vector<string> v;
		while(x--){
			char s[20];
			scanf("%s",s);
			v.pb(s);
		}
		sort(v.begin(),v.end());
		if(v.size() == 1)
			printf("%d\n",m[v[0]]);
		else if(v.size() == 2)
			printf("%d\n",m[v[0] + '#' + v[1]]);
		else if(v.size() == 3)
			printf("%d\n",m[v[0] + '#' + v[1] + '#' + v[2]]);
		else if(v.size() == 4)
			printf("%d\n",m[v[0] + '#' + v[1] + '#' + v[2] + '#' + v[3]]);

	}

	return 0;
}