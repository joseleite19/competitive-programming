#include <bits/stdc++.h>

#define MOD (1000000007)
#define ff first
#define ss second
#define mp make_pair

using namespace std;

struct tree{
	tree *left, *right;
	int value;
	tree(){
		left = right = NULL;
	}

	tree(int v){
		left = right = NULL;
		value = v;
	}

	void insert(int v){
		if(v < value){
			if(left) left->insert(v);
			else left = new tree(v);
		}
		else{
			if(right) right->insert(v);
			else right = new tree(v);
		}
	}
	bool operator==(const tree & o)const{
		bool r1 = (right != NULL);
		bool r2 = (o.right != NULL);
		bool l1 = (left != NULL);
		bool l2 = (o.left != NULL);
		if(r1 != r2 || l1 != l2) return false;
		bool ret = 1;
		if(left){
			ret &= (*left == *(o.left));
		}
		if(right){
			ret &= (*right == *(o.right));
		}
		return ret;
	}
};

bool same(tree *s, tree *t){
	if(s == NULL){
		if(t) return 0;
		return 1;
	}
	if(t == NULL) return 0;

	// bool r1 = (s->right != NULL);
	// bool r2 = (t->right != NULL);
	// bool l1 = (s->left != NULL);
	// bool l2 = (t->left != NULL);
	// if(r1 != r2 || l1 != l2) return false;
	// bool ret = 1;
	// if(s->left){
	// 	if(!t->left) return 0;
	// 	ret = same(s->left, t->left);
	// }
	// if(s->right){
	// 	if(!t->right) return 0;
	// 	ret &= same(s->right, t->right);
	// }
	// if(same(s->left, t->left)){
	// 	if(same(s->right, t->right)){
	// 		return 1;
	// 	}
	// 	printf("$%d %d\n", s->value, t->value);
	// 	return 0;
	// }
	// printf("$%d %d\n", s->value, t->value);
	// printf("asd\n");
	// return 0;
	return same(s->left, t->left) && same(s->right, t->right);
	// return same(s->left, t->left) && same(s->right, t->right);
}

int main(){
	int n, k, x;
	tree t[55];

	scanf("%d %d", &n, &k);


	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		t[i].value = x;
		for(int j = 1; j < k; j++){
			scanf("%d", &x);
			t[i].insert(x);
		}
	}

	int ans = n;
	// printf("%d\n", same(t+0, t+2));

	for(int i = 0; i < n; i++){
		bool deuruim = false;
		for(int j = i+1; j < n; j++){
			// if(t[i] == t[j])
			if(same(&t[i], &t[j]))
				deuruim = true;
		}
		if(deuruim) ans--;
	}

	printf("%d\n", ans);

	return 0;
}