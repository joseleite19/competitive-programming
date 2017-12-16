#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

const int N = 100005;

/*template<
	  typename Key, // Key type
  	  typename Mapped, // Mapped-policy
  	  typename Cmp_Fn = std::less<Key>, // Key comparison functor
  	  typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
  	  template<
  	  typename Const_Node_Iterator,
  	  typename Node_Iterator,
  	  typename Cmp_Fn_,
 	  typename Allocator_>
  	  class Node_Update = null_node_update, // A policy for updating node invariants
  	  typename Allocator = std::allocator<char> > // An allocator type
class tree;*/

typedef tree<
int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	oset;

int main(){
	int n, m, q;

	scanf("%d %d %d", &n, &m, &q);

	int t, x, y, sz;
	char cty;

	map<int, set<int> > l;
	map<int, oset> lt;
	map<int, set<int> > c;
	map<int, oset> ct;

	while(q--){
		scanf("%d %c %d %d %d", &t, &cty, &x, &y, &sz);
		swap(x, y);

		if(t == 1){
			bool ok = 1;

			int dx = 0, dy = 0;
			if(cty == 'L') dy++;
			else dx++;
			forn(i, sz){
				if(l[ x + i*dx ].count(y + i*dy)) ok = 0;
				if(c[ y + i*dy ].count(x + i*dx)) ok = 0;
			}
			if(!ok){ printf("-1\n"); continue; }
			forn(i, sz){
				l[ x + i*dx ].insert(y + i*dy);
				lt[ x + i*dx ].insert(y + i*dy);
				c[ y + i*dy ].insert(x + i*dx);
				ct[ y + i*dy ].insert(x + i*dx);
			}
		}
		else{
			if(cty == 'L'){
				int tmp = lt[x].order_of_key(y+sz) - lt[x].order_of_key(y);
				printf("%d\n", tmp);
			}
			else{
				int tmp = ct[y].order_of_key(x+sz) - ct[y].order_of_key(x);
				printf("%d\n", tmp);
			}
		}
	}



    return 0;
}
