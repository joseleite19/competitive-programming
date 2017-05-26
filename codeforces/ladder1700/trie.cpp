#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000003

using namespace std;
class Trie{
protected:
	vector<map<char, int> > trie;
	vector<bool> final;
public:

	Trie() : trie(1), final(1){}

	inline bool has_edge(int state, char c) const{
		return trie[state].count(c);	
	}

	inline int change_state(int state, char c) const{
		return has_edge(state, c) ? trie[state].at(c) : 0;
	}

	inline bool is_final(int state) const{
		return state < final.size() && final[state];
	}

	inline size_t size() const{
		return trie.size();
	}
	
	const map<char, int> &getchilds(int state) const{
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

class Aho : public Trie{
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

	int has_output(int s) const{
		return outputlink[s];
	}

	int anda(int s, char c)const{
		while(s && !has_edge(s, c)) s = fail[s];
		if(has_edge(s, c)) s = change_state(s, c);
		return s;
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

int main(){

	int n, A, B;

	char s[10005];

	vector<string> v;
	scanf("%d %d %d", &A, &B, &n);
	for(int i = 0; i < n; i++){
		scanf(" %s", s);
		v.push_back(s);
	}

	Aho a(v);

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