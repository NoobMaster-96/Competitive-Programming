#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node{
public:
	char data;
	int freq;
	unordered_map<char,Node*> children;
	bool terminal;
	Node(char d){
		freq = 1;
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
				temp->freq += 1;
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

	string findPrefix(string s){
		Node* temp = root;
		int n = s.length();
		string ans = "";
		for(int i=0;i<n;i++){
			ans += s[i];
			if(temp->children[s[i]]->freq==1){
				return ans;
			}
			temp = temp->children[s[i]];
		}
		return "-1";
	}
};


int main(){
	Trie T;
	int n;
	cin>>n;
	vector<string> a(n),ans(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		T.insert(a[i]);
	}
	for(int i=0;i<n;i++){
		ans[i] = T.findPrefix(a[i]);
		cout<<ans[i]<<endl;
	}
}