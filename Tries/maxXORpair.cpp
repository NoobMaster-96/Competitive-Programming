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
	trie(){
		root = new node();
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
		
	}
}
