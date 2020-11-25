#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node{
public:
	Node* left; //for 0
	Node* right; //for 1
};

class Trie{
	Node* root;
public :
	Trie(){
		root = new Node();
	}

	void insert(int n){
		Node* temp = root;
		for(int i=31;i>=0;i--){
			int bit = (n>>i)&1;
			if(bit==0){
				if(temp->left==NULL){
					temp->left = new Node();
				}
				temp = temp->left;
			}
			else{
				if(temp->right==NULL){
					temp->right = new Node();
				}
				temp = temp->right;
			}
		}
	}
	// helper function to find max xor
	int max_xor_helper(int val){
		int curr_ans = 0;
		Node* temp = root;
		for(int i=31;i>=0;i--){
			int bit = (val>>i)&1;
			if(bit==0){
				if(temp->right!=NULL){
					temp = temp->right;
					curr_ans += (1<<i);
				}
				else{
					temp = temp->left;
				}
			}
			else{
				if(temp->left!=NULL){
					temp = temp->left;
					curr_ans += (1<<i);
				}
				else{
					temp = temp->right;
				}
			}
		}
		return curr_ans;
	}

	int max_xor(vector<int> &a){
		int n = a.size();
		int ans = 0;
		for(int i=0;i<n;i++){
			int val = a[i];
			int curr_xor = max_xor_helper(val);
			ans = max(ans,curr_xor);
		}
		return ans;
	}
};

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	Trie t;
	for(int i=0;i<n;i++){
		cin>>a[i];
		t.insert(a[i]);
	}
	cout<<t.max_xor(a);
}
