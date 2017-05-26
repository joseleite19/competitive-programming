#include <bits/stdc++.h>

using namespace std;

class Trie{
protected:
	vector<map<char, int> > trie;
	vector<bool> final;
public:

	Trie() : trie(1), final(1){}

	inline bool has_edge(int state, char c){
		return trie[state].count(c);	
	}

	inline int change_state(int state, char c){
		return has_edge(state, c) ? trie[state][c] : 0;
	}

	inline bool is_final(int state){
		return state < final.size() && final[state];
	}

	inline size_t size(){
		return trie.size();
	}
	
	const map<char, int> &getchilds(int state){
		return trie[state];
	}

	int insert_word(const string& s){
		int ptr = 0;
		for(char c : s){
			if(!trie[ptr].count(c)){
				trie[ptr][c] = trie.size();
				trie.resize(trie.size()+1);
				final.resize(final.size()+1);
			}
			ptr = trie[ptr][c];
		}
		final[ptr] = true;
		return ptr;
	}
};

class Aho : Trie{
	vector<int> fail;
	vector<int> outputlink;
	vector<bool> vis;
	vector<vector<int> > pos;
	vector<int> last_state;

public:
	void build_failures(){
		fail.assign(size(), 0);

		queue<int> q;

		for(pair<const char, const int> p : getchilds(0)){
			fail[ p.second ] = 0;
			q.push(p.second);
		}

		while(!q.empty()){
			int u = q.front(); q.pop();

			for(pair<const char, const int> p : getchilds(u)){
				char c = p.first;
				int v = p.second, ptr = fail[u];
				
				while(ptr && !has_edge(ptr, c)) ptr = fail[ptr];
				
				if(has_edge(ptr, c)) ptr = change_state(ptr, c);
				fail[v] = ptr;
				
				if(is_final(ptr)) outputlink[v] = ptr;
				else if(outputlink[ptr]) outputlink[v] = outputlink[ptr];

				q.push(v);
			}
		}
	}

	void back(int ptr, int id){
		if(!ptr) return;
		vis[ptr] = 1;
		pos[ptr].push_back(id);
		back(outputlink[ptr], id);
	}

	void run(string s){
		int ptr = 0;
		for(int i = 0; i < s.size(); i++){
			if(!has_edge(ptr, s[i])){
				int nptr = ptr;
				while(nptr && !has_edge(nptr, s[i])) nptr = fail[nptr];
				
				if(has_edge(nptr, s[i])) nptr = change_state(nptr, s[i]);
				trie[ptr][ s[i] ] = nptr;
			}

			ptr = change_state(ptr, s[i]);

			if(is_final(ptr)) back(ptr, i);
			else back(outputlink[ptr], i);
		}
	}

	bool was_visited(int id){
		return vis[ last_state[id] ];
	}

	Aho(const vector<string> &v){
		Trie();
		last_state.assign(v.size(), 0);
		for(int i = 0; i < v.size(); i++)
			last_state[i] = insert_word(v[i]);
		vis.assign(size(), 0);
		pos.assign(size(), vector<int>());
		outputlink.assign(size(), 0);
		build_failures();
	}
};

char s[100005];
char p[100005];

int main(){

	int t, n;

	scanf("%d", &t);

	while(t--){

		scanf(" %s %d", s, &n);
		string food = s;
		vector<string> v(n);

		for(int i = 0; i < n; i++){
			scanf(" %s", p);
			v[i] = p;
		}

		Aho cora(v);
		cora.run(food);

		for(int i = 0; i < n; i++)
			printf("%s\n", cora.was_visited(i) ? "y" : "n");

	}

	// vector<string> qwe;
	// qwe.push_back("take");
	// qwe.push_back("fast");
	// qwe.push_back("so");
	// qwe.push_back("sofa");

	// Aho q(qwe);



	return 0;
}



// int ans = 0;
// for(s : gabarito){
// 	for(id : vec[ last_state[s] ]){
// 		int x = st.query(0, id-s.size());
// 		st.update(id, x);
// 		ans = max(ans, x);
// 	}
// }