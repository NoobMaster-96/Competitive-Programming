#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node{
public:
	char data;
	unordered_map<char,Node*> children;
	bool terminal;
	Node(char d){
		data = d;
		terminal = false;
	}
};

class Trie{
	Node* root;
	int cnt;
public:
	Trie(){
		root = new Node('\0');
		cnt = 0;
	}

	int count(){
		return cnt;
	}

	void insert(string s){
		Node* temp = root;
		int n = s.length();
		for(int i=0;i<n;i++){
			if(temp->children.find(s[i])!=temp->children.end()){
				temp = temp->children[s[i]];
			}
			else{
				Node* newNode = new Node(s[i]);
				temp->children[s[i]] = newNode;
				temp = newNode;
			}
		}
		temp->terminal = true;
		cnt++;
	}

	bool find(string s){
		int n = s.length();
		Node* temp = root;
		for(int i=0;i<n;i++){
			if(temp->children.find(s[i])==temp->children.end()){
				return false;
			}
			temp = temp->children[s[i]];
		}
		return temp->terminal;
	}
};

int main(){
	Trie t;
	int n;
	cin>>n;
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
		t.insert(s[i]);
	}
	int f;
	cin>>f;
	vector<string> str(f);
	for(int i=0;i<f;i++){
		cin>>str[i];
		cout<<t.find(str[i])<<endl;
	}
	cout<<t.count()<<endl;
}